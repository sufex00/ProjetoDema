#include "file.h"
#include <QDebug>
#include <QString>
#include <QFile>


// O construtor abre todas as informações que a classe precisa para ser aberta

File::File(QString Endereco)
    {
        std::ifstream file;
        this-> Dir = Endereco;

        this->size=1;

        file.open (this->Dir.toLatin1().data(), std::ifstream::in);

        QString aux1 = this->toString();

        this->file=this->toString(); // ler tudo e coloca nesse tostring para faer a contagem da frequêcia

        std::ifstream ifs;
        ifs.open (this->Dir.toLatin1().data(), std::ios::binary);// tolatin pega o diretório transforma numa string
        char c;
        c = ifs.get();
        int i=0;
        while (ifs.good())
        {
           this->frequency[this->toString(i)]++;
           c = ifs.get();
           size++;
           i++;
        }

       //Esse for pega tudo que tem no arquivo, lido no aux, e ordena


    }

    QByteArray File::toString()
    {

        QString PathFile;
        QString aux;
        std::ifstream ifs;
        ifs.open (this->Dir.toLatin1().data(), std::ios::binary);
        uchar c = ifs.get();
        QByteArray p = QByteArray();
        while (ifs.good())
        {
            p.append(c);
            c = ifs.get();
        }
        return p;
    }

    unsigned char File::toString(int position)
    {
        QByteArray p = QByteArray();
        return file.at(position);
    }

    int File::getFrequency(int character)
    {
        return this->frequency[character];
    }

    QString File::getNome()
    {
        return this->Dir;
    }

    int File::getSize()
    {
        return this->size;
    }

