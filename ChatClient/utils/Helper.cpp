#include "Helper.h"


QPixmap pixmaptoRound(const QPixmap &src, const QSize head_size)
{
    if (src.isNull())
    {
        return QPixmap();
    }
    QPixmap image(head_size);
    // image.fill(Qt::transparent);
    image.fill(QColor(255, 255, 255, 0));
    QPainter painter(&image);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    QPainterPath path;
    path.addEllipse(0, 0, head_size.width(), head_size.height());
    painter.setClipPath(path);
    painter.fillPath(path, QBrush(Qt::white));
    painter.drawPixmap(0, 0, head_size.width(), head_size.height(), src);
    return image;
}

QString generateRandomString(int length)
{
    QString randomString;
    randomString.reserve(length);

    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    const int possibleCharactersSize = possibleCharacters.size();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, possibleCharactersSize - 1);

    for (int i = 0; i < length; ++i)
    {
        int index = dis(gen);
        randomString[i] = possibleCharacters.at(index);
    }

    return randomString;
}

QString generateRandomFilePath(const QString &folder_path, const QString &file_path)
{
    QString random_prefix = generateRandomString(30);
    QString res_path = folder_path + "/" + random_prefix + "_" + file_path;
    while(QFile(res_path).exists())
    {
        random_prefix = generateRandomString(30);
        res_path = folder_path + "/" + random_prefix + "_" + file_path;
    }
    return res_path;
}

QPixmap darkenImage(const QPixmap &origin_pixmap, const qreal &factor)
{
    QPixmap darkenedPixmap(origin_pixmap.size());
    darkenedPixmap.fill(QColor(0, 0, 0));

    QPainter painter(&darkenedPixmap);
    painter.setOpacity(factor);
    painter.drawPixmap(0, 0, origin_pixmap);
    painter.end();

    return darkenedPixmap;
}
