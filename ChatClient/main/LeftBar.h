#ifndef LEFTBAR_H
#define LEFTBAR_H

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QTextCodec>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDebug>
#include "InfoButton.h"
#include "PersonDataShow.h"
#include "PersonDataSet.h"
#include "Config.h"
#include "AssembleBytes.h"
#include "Helper.h"

class LeftBar : public QFrame
{
    Q_OBJECT
public:
    explicit LeftBar(QWidget *parent = nullptr);
    void m_informationAppendUnreadNum(const int& num);      // 消息：添加未读消息
    void m_friendsAppendUnreadNum(const int& num);          // 好友：添加未读消息
    void m_informationSetUnreadNum(const int& num);         // 消息：设置未读消息个数
    void m_friendsSetUnreadNum(const int& num);             // 好友：设置未读消息个数
    void m_clickInformation();                              // 点击消息
    void m_clickFriends();                                  // 点击好友
    void m_querySelfHeadPic();                              // 请求查询用户头像
    void m_setHeadPic(const QString& head_path);            // 设置头像

private:
    QLabel* m_lblHeadPic;                   // 头像
    InfoButton* m_btnInformation;           // 消息
    InfoButton* m_btnFriends;               // 好友
    PersonDataShow* m_PsnDataShow;              // 个人信息展示页
    PersonDataSet*  m_PsnDataSet;               // 个人信息修改页

    bool eventFilter(QObject *watched, QEvent *event) override;

signals:
    void signal_openInfomationPage();       // 信号：打开消息页面
    void signal_openFriendsPage();          // 信号：打开朋友页面
    void signal_queryUserHeadPic(quint32 user_id);

public slots:

private slots:
    void slot_btnInformation_clicked();             // 点击消息
    void slot_btnFriends_clicked();                 // 点击朋友
    void slot_lblHeadPic_clicked();                 // 点击头像
    void slot_buildTabwidget();                     // 手动构建tab标签页
    void slot_editUserInfo();                       // 修改用户信息
};

#endif // LEFTBAR_H
