#ifndef TWOCLICKAREABUTTON_H
#define TWOCLICKAREABUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QPen>
#include <QPainter>
#include <QPaintEvent>
#include <QMenu>
#include <QAction>
#include <QDebug>

class TwoClickAreaButton : public QPushButton
{
    Q_OBJECT
public:
    explicit TwoClickAreaButton(QWidget *parent = nullptr);
    ~TwoClickAreaButton();

    void setDrawedText(const QString& text);
    void setActionName(const QString& text);

private:
    enum ExpandDirection{
        Up,
        Down
    };

    QString m_text;       // 按键上显示的文字
    QMenu* m_expandMenu;        // 展开菜单
    QAction* m_expandAction;      // 展开菜单中的项
    ExpandDirection m_expandDirection;
    bool m_initPos;
    int m_posExpandIcon;      // 展开箭头的x坐标
    QSize m_sizeExpandIcon;   // 展开箭头icon的大小
    int m_posSplitLine;       // 分割线的x坐标

    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;

signals:
    void signal_leftPart_clicked();             // 信号：左半部分被点击
    void signal_expandAction_triggered();       // 信号：下拉菜单中的项被点击

public slots:

private slots:
    void slot_expandMenu_aboutToHide();
};

#endif // TWOCLICKAREABUTTON_H
