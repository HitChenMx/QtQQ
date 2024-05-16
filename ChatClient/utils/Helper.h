#ifndef HELPER_H
#define HELPER_H

#include <QPixmap>
#include <QPainter>
#include <QFile>
#include <random>

QPixmap pixmaptoRound(const QPixmap &src, const QSize head_size);           // 圆形头像
QString generateRandomString(int length) ;          // 生成随机字符串
QString generateRandomFilePath(const QString& folder_path, const QString& file_path);       // 生成文件路径，名称是随机的，保证不发生路径冲突
QPixmap darkenImage(const QPixmap& origin_pixmap, const qreal& factor);     // 图像变暗

#endif // HELPER_H
