#include "InfoButton.h"

InfoButton::InfoButton(QWidget *parent) :
    QPushButton(parent),
    m_unreadPic(new QLabel(this))
{
    m_setUnreadNum(0);
    m_unreadPic->setStyleSheet("QLabel{ background-color: rgba(255, 255, 255, 0);}");
    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPointSize(8);
    font.setBold(true);
    m_unreadPic->setFont(font);
    // m_unreadPic->resize(35, 35);
    m_unreadPic->setFixedSize(35, 35);
    m_unreadPic->move(int(this->width()*0.4), int(this->height()*0.15));
    m_unreadPic->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
}

void InfoButton::m_setUnreadNum(int num)
{
    m_unreadNum = num > 0? num : 0;
    if(m_unreadNum > 0)
    {
        m_unreadPic->setStyleSheet("QLabel{"
                                   "color: rgb(255, 255, 255);"
                                   "margin-left:  5px;"
                                   "margin-right: 5px;"
                                   "margin-top:   5px;"
                                   "margin-bottom:5px;"
                                   "border-image: url(:/qqicons/qrc/red_circle.svg) ;"
                                   "background-color: rgba(255, 255, 255, 0);"
                                   "}");
        m_unreadPic->setText(QString::number(m_unreadNum));
    }
    else
    {
        m_unreadPic->clear();
        m_unreadPic->setStyleSheet("QLabel{ background-color: rgba(255, 255, 255, 0);}");
    }
}

void InfoButton::m_appendUnreadNum(int num)
{
    m_setUnreadNum(m_unreadNum + num);
}
