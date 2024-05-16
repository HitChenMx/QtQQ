#ifndef HELPER_H
#define HELPER_H

#include <random>
#include <QString>
#include <QFile>


QString generateRandomString(int length) ;          // 生成随机字符串
QString generateRandomFilePath(const QString& folder_path, const QString& file_path);       // 生成文件路径，名称是随机的，保证不发生路径冲突


#endif // HELPER_H
