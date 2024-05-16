#ifndef PERSONDATASHOW_H
#define PERSONDATASHOW_H

#include <QDialog>
#include <QPainter>
#include <QPaintEvent>
#include <QSize>
#include <QPixmap>
#include <QTextCodec>
#include <QDebug>
#include "global.h"
#include "Helper.h"

namespace Ui {
class PersonDataShow;
}

class PersonDataShow : public QDialog
{
    Q_OBJECT

public:
    explicit PersonDataShow(QWidget *parent = 0);
    ~PersonDataShow();

    bool m_setUserInfoToUI(const sttClientInfo& user_info,
                           const QPixmap& head_pic = QPixmap());           // 把用户信息展示到界面上
    bool m_setUserInfoToUI(const sttClientInfo& user_info,
                           const QString& head_path = ":/qqicons/qrc/QQicon.svg");           // 把用户信息展示到界面上
    void m_setEditInfoUnvisible();                                   // 设置编辑资料不可见

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::PersonDataShow *ui;

    void m_init();              // 初始化界面

signals:
    void signal_userInfoEdit();

private slots:
    void slot_btnEditInfo_clicked();    // 按下“编辑资料”
};

#endif // PERSONDATASHOW_H
