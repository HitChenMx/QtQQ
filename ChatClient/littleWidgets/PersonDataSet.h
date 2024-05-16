#ifndef PERSONDATASET_H
#define PERSONDATASET_H

#include <QWidget>
#include <QDebug>
#include <QMap>
#include "global.h"
#include <QTextCodec>
#include <QScopedPointer>
#include <QMessageBox>
#include <QFileDialog>
#include "Config.h"
#include "AssembleBytes.h"
#include "Helper.h"

namespace Ui {
class PersonDataSet;
}

class PersonDataSet : public QWidget
{
    Q_OBJECT

public:
    explicit PersonDataSet(QWidget *parent = 0);
    ~PersonDataSet();

    bool m_setUserInfoToUI(const sttClientInfo user_info);          // 刷新用户信息到界面

private:
    Ui::PersonDataSet *ui;
    QPixmap m_headPic;          // 头像
    QSize m_headSize;           // 头像大小
    QString m_changeHeadPath;   // 修改的新头像的图片路径

    void m_init();              // 初始化
    bool eventFilter(QObject *watched, QEvent *event) override;

signals:
    void signal_userInfoSave(const quint32 user_id, const QMap<QString, QVariant> user_info);             // 用户信息保存信号
    void signal_userHeadSave(const quint32 user_id, const QString head_path);             // 信号：修改了用户头像

private slots:
    void slot_btnSaveSet_clicked();         // 按下“保存”
    void slot_btnCancelSet_clicked();       // 按下“取消”
};

#endif // PERSONDATASET_H
