#include "TwoClickAreaButton.h"

TwoClickAreaButton::TwoClickAreaButton(QWidget *parent) :
    QPushButton(parent),
    m_text(QString()),
    m_initPos(false),
    m_expandMenu(new QMenu(this)),
    m_expandAction(new QAction("action1", this)),
    m_expandDirection(ExpandDirection::Down)
{
    this->setStyleSheet("QPushButton{                             "
                        "   text-align: center;                   "
                        "   border: 1px solid grey;               "
                        "   padding: 0px 20px 0px 20px;           "
                        "   color: rgb(42, 42, 42);               "
                        "   background-color: rgb(255, 255, 255); "
                        "   border-radius: 5px;                   "
                        "}                                        "
                        "                                         "
                        "QPushButton:hover{                       "
                        "    background-color: rgb(240, 240, 240);"
                        "}                                        "
                        "                                         "
                        "QPushButton:pressed{                     "
                        "    background-color: rgb(224, 224, 224);"
                        "}"); 
    m_expandMenu->addAction(m_expandAction);
    connect(m_expandMenu, &QMenu::aboutToHide, this, &TwoClickAreaButton::slot_expandMenu_aboutToHide);
    connect(m_expandAction, &QAction::triggered, [this](){
        emit signal_expandAction_triggered();
    });
}

TwoClickAreaButton::~TwoClickAreaButton()
{

}

void TwoClickAreaButton::paintEvent(QPaintEvent *event)
{
    QPushButton::paintEvent(event);

    if(m_initPos == false)
    {
        m_sizeExpandIcon = QSize(qMax(this->width()/10, 20), qMax(this->width()/10, 20));
        m_posExpandIcon = this->width()/10*9 - m_sizeExpandIcon.width();
        m_posSplitLine = m_posExpandIcon - this->width()/10;
        m_initPos = true;
    }

    // 画展开箭头
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    QPixmap expand_icon;
    if(m_expandDirection == ExpandDirection::Down)
    {
        expand_icon.load(":/qqicons/qrc/119-down-arrow.svg");
    }
    else if(m_expandDirection == ExpandDirection::Up)
    {
        expand_icon.load(":/qqicons/qrc/119-up-arrow.png");
    }

    expand_icon = expand_icon.scaled(m_sizeExpandIcon, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    int x = m_posExpandIcon;
    int y = this->rect().center().y() - expand_icon.height()/2;
    if(y < 0)
        y = 0;
    painter.save();
    painter.drawPixmap(x, y, expand_icon);
    painter.restore();

    // 画分割线
    painter.save();
    QPen draw_line_pen;
    draw_line_pen.setWidth(2);
    draw_line_pen.setColor(QColor(153, 153, 153, 255));
    draw_line_pen.setStyle(Qt::SolidLine);
    painter.setPen(draw_line_pen);
    painter.drawLine(QLine(m_posSplitLine, this->height()/8, m_posSplitLine, this->height()/8*7));
    painter.restore();

    // 画文字
    painter.save();
    if(m_text.isEmpty())
    {
        m_text = this->text();
        this->setText("");
    }
    QString drawed_text = m_text;
    QFont drawed_font = this->font();
    if(drawed_font.pointSize() <= 0)
        drawed_font.setPointSize(8);
    painter.setFont(drawed_font);
    QRect drawed_rect(0, 0, m_posSplitLine, this->height());
    painter.setPen(QColor(Qt::black));
    painter.drawText(drawed_rect, Qt::AlignCenter, drawed_text);
    painter.restore();
}

void TwoClickAreaButton::mousePressEvent(QMouseEvent *event)
{
    QPushButton::mousePressEvent(event);

    int mouse_x_pos = event->x();
    if (mouse_x_pos >= 0 && mouse_x_pos < m_posSplitLine)
    {
        emit signal_leftPart_clicked();
    }
    else if (mouse_x_pos >= m_posSplitLine && mouse_x_pos <= this->width())
    {
        m_expandDirection = ExpandDirection::Up;
        this->update();
        m_expandAction->setFont(this->font());
        QPoint menu_pos = this->mapToGlobal(QPoint(m_posSplitLine, this->height()));
        m_expandMenu->exec(menu_pos);

    }

    // QPushButton::mousePressEvent(event);
}

void TwoClickAreaButton::setDrawedText(const QString &text)
{
    m_text = text;
    this->update();
}

void TwoClickAreaButton::setActionName(const QString &text)
{
    m_expandAction->setText(text);
}

void TwoClickAreaButton::slot_expandMenu_aboutToHide()
{
    // 当菜单收起时，重绘箭头
    m_expandDirection = ExpandDirection::Down;
    this->update();

    if(this->isDown())
        this->setDown(false);
}
