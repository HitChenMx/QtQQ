#ifndef SEARCHFRIENDWIDGET_H
#define SEARCHFRIENDWIDGET_H

#include <QWidget>
#include <QAction>
#include <QMap>
#include <QString>
#include <QVBoxLayout>
#include <QSharedPointer>
#include "SearchUserLittleBox.h"
#include "AssembleBytes.h"
#include "Config.h"
#include "global.h"

namespace Ui {
class SearchFriendWidget;
}

class SearchFriendWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SearchFriendWidget(QWidget *parent = 0);
    ~SearchFriendWidget();
    QVector<quint32> m_getResultUserIds() const;        // 获取当前搜索结果的用户id
    void m_checkSetUserHead(const quint32& user_id, const QString& head_path);  // 检查当前搜索结果是否有该用户，如果有，就设置该用户的头像

private:
    Ui::SearchFriendWidget *ui;

    QVBoxLayout* m_resultListVLayout;       // 搜索结果的垂直布局
    QVector<quint32> m_resultUserIds;       // 搜索结果的用户id

    void slot_edtSearch_textChanged(const QString& text);

signals:
    void signal_searchTextChanged(const quint32 user_id, const QString& search_text);       // 信号：搜索栏的文本发生改变
    void signal_sendMsgToFriend(const quint32 friend_id);                                   // 信号：发起与该好友的聊天

public slots:
    void slot_updateSearchRecords(const QString search_text, QVector<sttFriendInfo> update_records);       // 更新搜索结果

};

#endif // SEARCHFRIENDWIDGET_H
