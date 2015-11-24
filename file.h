#ifndef FILE_H
#define FILE_H

#include <QString>
#include <fstream>
#include <QByteArray>

class File
{
    //256 é escolhido pelo número de caracteres que dispõe a tabela ASC.
    int frequency[256]= {0};

    QString Dir;

    int size;

    QByteArray file;

    //std::ifstream file;

    //QFile Arquivo;

public:

    File(QString Endereco);
    QByteArray toString();
    unsigned char toString(int position);
    int getFrequency(int character);
    QString getNome();
    QString readFile(int initPosition, int sizeRead);
    int readFile(int initPosition);
    int getSize();
};

#endif //FILE_H
