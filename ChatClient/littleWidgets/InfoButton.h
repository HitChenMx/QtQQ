#ifndef INFOBUTTON_H
#define INFOBUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QDebug>

class InfoButton : public QPushButton
{
    Q_OBJECT
public:
    explicit InfoButton(QWidget *parent = nullptr);

    void m_setUnreadNum(int num);           // 设置未读消息个数为num
    void m_appendUnreadNum(int num);        // 未读消息个数加num

private:
    int m_unreadNum;        // 未读消息的计数
    QLabel* m_unreadPic;

signals:

public slots:
};

#endif // INFOBUTTON_H
