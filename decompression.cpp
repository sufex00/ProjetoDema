#include "decompression.h"
#include<QDebug>
decompression::decompression()
{

}

void decompression::operation(TreatmentHeader treatmentHeader)
{
    QString fileIn = QString(treatmentHeader.getFileInput());
    File obj = File(fileIn);
    BitVector bitArray = BitVector();
    QString bucked;
    huffdecotification huffDecodification = huffdecotification (fileIn);
    //crio o arquivo original
    std::ofstream fileObjectOutputDecotification;
    //verifico o caminho do arquivo
    if(QString(treatmentHeader.getFileOutput()).isEmpty())
        fileObjectOutputDecotification.open(huffDecodification.getFileName().toLatin1().data(),std::ios::binary);
    else
        fileObjectOutputDecotification.open(QString(treatmentHeader.getFileOutput()).append(huffDecodification.getFileName()).toLocal8Bit().data(),std::ios::binary);
    //qDebug()<<QString().setNum(obj.toString(17),10);

    //limpa o bit vector
    bitArray.clear();
    bitArray.clearBitVector();

    //gera a arvore aparti da representação
    Nodes rootTreeHuffman=*huffDecodification.generation(huffDecodification.TreeRepresentation());
    Nodes* node=&rootTreeHuffman;

    //Pega uma parte do arquivo codificado
    bucked= obj.toString();

    //decodifica a parte que foi pegada do arquivo, e a coloca no bit vector
    for(int y=3+huffDecodification.TreeRepresentation().size()+huffDecodification.getFileName().size(); y<obj.getSize()-1;y++)
    {
        uchar chartTobit;
        chartTobit=obj.toString(y);
        bitArray.setbit(QString().setNum(chartTobit,2),8);
        qDebug()<<QString().setNum(chartTobit,2);
    }


    //percorre a arvore decodificando os bytes
    for(int y=0; y<bitArray.getsize();y++)
    {
        qDebug()<<bitArray.getsize()-huffDecodification.getTrash();

        //verfica se o arquivo acabou, e se ja chegamos no lixo
        if(y==bitArray.getsize()-huffDecodification.getTrash())
        {
            break;
        }
        if(bitArray.bitVectorAt(y)==0)
        {
            node=node->getLeft();
        }
        if(bitArray.bitVectorAt(y)==1)
        {
            node=node->getRight();
        }
        if(node->isLeaf())
        {
            uchar character=node->getElement();
            fileObjectOutputDecotification<<character;
            node=&rootTreeHuffman;
        }
    }
    //limpa o bit vector
    bitArray.clearBitVector();

}

