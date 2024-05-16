#include "Helper.h"


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
