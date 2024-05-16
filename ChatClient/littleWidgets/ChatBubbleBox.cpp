#include "ChatBubbleBox.h"

ChatBubbleBox::ChatBubbleBox(const sttBubbleInfo& bubble_info, QWidget *parent) :
    QWidget(parent),
    m_bubbleInfo(bubble_info),
    m_lblHeadPic(nullptr),
    m_rectHeadPic(QRect()),
    m_rectBubbleFrame(QRect()),
    m_rectBubbleText(QRect())
{
    this->setMinimumWidth(200);

    if(m_bubbleInfo.sender != Sender::System)
    {
        // 设置头像
        m_lblHeadPic = new QLabel(this);
        QSize _head_size(45, 45);
        m_lblHeadPic->setMinimumSize(_head_size);
        m_lblHeadPic->setMaximumSize(_head_size);
        m_lblHeadPic->setFixedSize(_head_size);
        QPixmap head_pic;
        if(bubble_info.sender == Sender::Me)
        {
            QString head_path = Config::getInstance()->m_getLoginClientHead();
            if(!head_path.isEmpty() && QFile(head_path).exists())
                head_pic.load(head_path);
            else
                head_pic.load(":/qqicons/qrc/QQicon.svg");
        }
        else if(bubble_info.sender == Sender::Peer)
        {
            QString head_path;
            LocalDatabase::getInstance()->m_queryFriendHead(bubble_info.user_id, &head_path);
            if(!head_path.isEmpty() && QFile(head_path).exists())
                head_pic.load(head_path);
            else
                head_pic.load(":/qqicons/qrc/QQicon.svg");
        }
        else
            head_pic.load(":/qqicons/qrc/QQicon.svg");
        head_pic = pixmaptoRound(head_pic, _head_size);
        m_lblHeadPic->setPixmap(head_pic);
    }
    QFont _text_font("Microsoft YaHei", 10, 50, false);
    this->setFont(_text_font);
}

sttBubbleInfo ChatBubbleBox::m_getBubbleInfo() const
{
    return m_bubbleInfo;
}

void ChatBubbleBox::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

//    qDebug() << "------ " << m_bubbleInfo.msg_text;
//    qDebug() << this->width();
//    qDebug() << m_rectHeadPic;
//    qDebug() << m_rectBubbleFrame;
//    qDebug() << m_rectBubbleText;
//    qDebug() << "------ ";

    if(m_bubbleInfo.sender==Sender::Me || m_bubbleInfo.sender==Sender::Peer)
    {
        QColor frame_color(Qt::white);
        QColor frame_border_color(Qt::gray);
        QColor text_color(Qt::black);
        if(m_bubbleInfo.sender == Sender::Me)
        {
            frame_color = QColor(0, 170, 255);
            frame_border_color = frame_color;
            text_color = QColor(Qt::white);
        }

        // 头像
        if(m_lblHeadPic)
        {
            m_lblHeadPic->setGeometry(m_rectHeadPic);
        }

        // 气泡框
        painter.save();
        painter.setPen(QPen(frame_border_color));
        painter.setBrush(QBrush(frame_color));
        painter.drawRoundedRect(m_rectBubbleFrame, 12, 12);
        painter.restore();

        // 聊天内容
        painter.save();
        if(m_bubbleInfo.msg_type == ChatType::IsTextMsg)
        {
            QPen pen_text;
            pen_text.setColor(text_color);
            painter.setPen(pen_text);
            painter.setFont(this->font());
            QTextOption text_option(Qt::AlignLeft | Qt::AlignVCenter);
            text_option.setWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere);
            painter.drawText(m_rectBubbleText, m_bubbleInfo.msg_text, text_option);
        }
        else if(m_bubbleInfo.msg_type == ChatType::IsFileMsg)
        {
            QPixmap chat_pic;
            chat_pic.load(m_bubbleInfo.msg_text);
            chat_pic = chat_pic.scaled(m_rectBubbleText.width(), m_rectBubbleText.height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            painter.drawPixmap(m_rectBubbleText, chat_pic);
        }
        painter.restore();
    }
    else if(m_bubbleInfo.sender == Sender::System)
    {
        painter.save();
        painter.setPen(QColor(153, 153, 153));
        painter.setFont(QFont("Microsoft YaHei", 9, 50, false));
        QTextOption text_option(Qt::AlignHCenter | Qt::AlignVCenter);
        text_option.setWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere);
        painter.drawText(m_rectBubbleText, m_bubbleInfo.msg_text, text_option);
        painter.restore();
    }

}

QSize ChatBubbleBox::m_setRect()
{
    float res_height = 0;
    int Blank1 = 10;    // 头像和气泡框之间的空白宽度
    int Blank2 = 15;    // 头像和边框之间的空白宽度
    int Blank3 = 0;     // 气泡框顶部和头像顶部的空白宽度
    int Blank4 = 10;    // 气泡边框和内边矩形的宽度

    if(m_bubbleInfo.sender == Sender::Me)
    {
        if(m_lblHeadPic)
        {
            m_rectHeadPic = QRect(this->width()-Blank2-m_lblHeadPic->width(), Blank2, m_lblHeadPic->width(), m_lblHeadPic->height());
            QSize textSize = m_getContentSize(m_bubbleInfo.msg_type, &(m_bubbleInfo.msg_text));
            m_rectBubbleFrame = QRect(m_rectHeadPic.x()-Blank1-Blank4*2-textSize.width(),
                                      m_rectHeadPic.y()+Blank3,
                                      textSize.width()+Blank4*2,
                                      textSize.height()+Blank4*2);
            m_rectBubbleText = QRect(m_rectBubbleFrame.x()+Blank4, m_rectBubbleFrame.y()+Blank4, textSize.width(), textSize.height());
            res_height = m_rectBubbleFrame.height() + Blank2*2 + Blank3;
        }
        else
        {
            qDebug() << "Error from ChatBubbleBox: m_lblHeadPic is nullptr!";
        }
    }
    else if(m_bubbleInfo.sender == Sender::Peer)
    {
        if(m_lblHeadPic)
        {
            m_rectHeadPic = QRect(Blank2, Blank2, m_lblHeadPic->width(), m_lblHeadPic->height());
            QSize textSize = m_getContentSize(m_bubbleInfo.msg_type, &(m_bubbleInfo.msg_text));
            m_rectBubbleFrame = QRect(m_rectHeadPic.x()+m_lblHeadPic->width()+Blank1,
                                      m_rectHeadPic.y()+Blank3,
                                      textSize.width()+Blank4*2,
                                      textSize.height()+Blank4*2);
            m_rectBubbleText = QRect(m_rectBubbleFrame.x()+Blank4, m_rectBubbleFrame.y()+Blank4, textSize.width(), textSize.height());
            res_height = m_rectBubbleFrame.height() + Blank2*2 + Blank3;
        }
        else
        {
            qDebug() << "Error from ChatBubbleBox: m_lblHeadPic is nullptr!";
        }
    }
    else if(m_bubbleInfo.sender == Sender::System)
    {
        m_rectHeadPic = QRect();
        m_rectBubbleFrame = QRect();
        QSize textSize = this->m_getRealTextSize(m_bubbleInfo.msg_text);
        m_rectBubbleText = QRect(this->width()/2-textSize.width()/2, 10, textSize.width(), textSize.height());
        res_height = m_rectBubbleText.height() + 16;
    }

    return QSize(this->width(), res_height);
}

QSize ChatBubbleBox::m_getRealTextSize(QString text) const
{
    int textWidth = this->width()*0.75;
    QSize res(0, 0);

    QFont font = this->font();
    QFontMetrics fm(font);
    int lineHeight = fm.lineSpacing();      // 行高
    int lineNum = text.count("\n");         // 行数-1

    if(lineNum == 0)
    {
        int cur_line_width = fm.width(text);
        // 检查这一行的宽度是否超出textWidth
        if(cur_line_width > textWidth)
        {
            lineNum = fm.width(text) / textWidth;
            res = QSize(textWidth, (lineNum+1)*lineHeight);
        }
        else
        {
            res = QSize(cur_line_width, (lineNum+1)*lineHeight);
        }
    }
    else
    {
        QStringList text_lines = text.split("\n");
        int maxWidth = 0;
        // 检查每一行的宽度是否超出textWidth
        for(QString cur_line_text : text_lines)
        {
            int cur_line_width = fm.width(cur_line_text);
            maxWidth = cur_line_width > maxWidth? cur_line_width : maxWidth;
            if(cur_line_width > textWidth)
            {
                maxWidth = textWidth;
                lineNum += fm.width(cur_line_text) / textWidth;
            }
        }
        res = QSize(maxWidth, (lineNum+1)*lineHeight);
    }

    return res;
}

QSize ChatBubbleBox::m_getContentSize(const ChatType::ChatMsgType &msg_type, QString* msg_text)
{
    QSize res_size;
    if(msg_type == ChatType::IsTextMsg)
    {
        res_size = this->m_getRealTextSize(*msg_text);
    }
    else if(msg_type == ChatType::IsFileMsg)
    {
        QPixmap chat_pic(*msg_text);
        if(chat_pic.isNull())
        {
            qDebug() << "can not find chat picture:" << chat_pic;
            chat_pic.load(":/qqicons/qrc/img_deleted.png");
            *msg_text = ":/qqicons/qrc/img_deleted.png";
        }
        int pic_width = chat_pic.width();
        int pic_height = chat_pic.height();
        if(pic_width >= pic_height)
        {
            float factor = 200.0 / pic_width;
            pic_width = 200;
            pic_height = int(factor * pic_height);
        }
        else
        {
            float factor = 200.0 / pic_height;
            pic_height = 200;
            pic_width = int(factor * pic_width);
        }
        res_size = QSize(pic_width, pic_height);
    }
    return res_size;
}

//void ChatBubbleBox::mouseMoveEvent(QMouseEvent *event)
//{
//    event->ignore();
//}

//void ChatBubbleBox::mousePressEvent(QMouseEvent *event)
//{
//    event->ignore();
//}
