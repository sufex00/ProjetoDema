#include "treatmentheader.h"
#include <QDebug>
TreatmentHeader::TreatmentHeader(int argc, char* argv[])
{
    this->argc=argc;
    this->argv=argv;
    this->isCodificationComandBool=false;
    this->isSuccessBool=false;
    this->isCodificationBool=false;

    if(QString(argv[1]).contains("-c") && QString(argv[1]).size()==2)
    {
        this->isCodificationBool=true;
    }
}
bool TreatmentHeader::isCodification()
{
    return this->isCodificationBool;
}
bool TreatmentHeader::isSuccess()
{
    return this->isSuccessBool;
}

char* TreatmentHeader::getFileInput()
{
    char* FileInputReturn;

    if(this->isCodification())
    {
        if(argc==3)
        {
            FileInputReturn=argv[2];
            this->isCodificationComandBool=true;
        }
        if(argc==5)
        {
            if(QString(argv[3]).contains("-o") && QString(argv[3]).size()==2)
            {
                FileInputReturn=argv[2];
                this->isCodificationComandBool=true;
            }
        }
    }
    else
    {
        if(argc==2)
        {
            FileInputReturn=this->argv[1];
            isCodificationComandBool=true;
        }
        if(argc==4)
        {
            if(QString(argv[2]).contains("-d") && QString(argv[2]).size()==2)
            {
                FileInputReturn=this->argv[1];
                isCodificationComandBool=true;
            }
        }
    }
    return FileInputReturn;
}

char* TreatmentHeader::getFileOutput()
{
    QString ReturnString=QString("");
    if(this->isCodificationBool)
    {
        if(argc==3)
        {
            ReturnString=QString(argv[2]);
            int position=ReturnString.indexOf(QString('.'));
            if(position!=-1)
            {
                ReturnString.remove(position,ReturnString.size()-position);
            }
            ReturnString.append(".huff");
            this->isSuccessBool=true;
            this->isCodificationComandBool=true;

        }
        if(argc==5)
        {
            if(QString(argv[3]).contains("-o") && QString(argv[3]).size()==2)
            {
                ReturnString=QString(argv[4]);
                this->isSuccessBool=true;
                this->isCodificationComandBool=true;
            }
        }
    }
    else
    {

        //qDebug()<<ReturnString;
        if(argc==4 && QString(argv[2]).contains("-d") && QString(argv[2]).size()==2)
        {
            ReturnString = QString(argv[3]).append("/");
            this->isSuccessBool=true;
            this->isCodificationComandBool=true;
        }
        if(argc==3)
        {
            this->isSuccessBool=true;
            this->isCodificationComandBool=true;
        }

    }
    return ReturnString.toLatin1().data();
}
void TreatmentHeader::error()
{
    qDebug()<<"Compaction :";
    qDebug()<<"Format[huffman -c arquivo_origem.x -o arquivo_de_saida.huff]"<<" or";
    qDebug()<<"Format[huffman -c arquivo_origem.x]";
    qDebug()<<"Decofication :";
    qDebug()<<"Format[huffman arquivo.huff]"<<" or";
    qDebug()<<"Format[huffman arquivo.huff -d /home/user/destino]";
}

bool TreatmentHeader::isCodificationComand()
{
    this->getFileInput();
    this->getFileOutput();
    return this->isCodificationComandBool;
}
