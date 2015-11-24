#include "compression.h"
#include<QFile>

compression::compression()
{

}

void compression::operation(TreatmentHeader TreatmentHeader)
{
    BitVector bitArray = BitVector();
    QString fileIn=QString(TreatmentHeader.getFileInput());
    //qDebug()<<fileIn;
    QString fileOut=QString(TreatmentHeader.getFileOutput());
    File obj = File(fileIn);
    TreeHuffman teste = TreeHuffman();
    std::ofstream fileObjectOutput;
    for(unsigned int i=0 ; i<256 ; i++)
    {
        char p = i;
        Nodes aux = Nodes(p, obj.getFrequency((int)i));
        teste.addNodes(aux);
    }
    //teste.Teste();
    teste.BuildHuffman();
    teste.BuildCodification(teste.getRoot());
    //teste.printTree(teste.getRoot());
    teste.TreeHuffamanRepresetation(teste.getRoot());
    //qDebug()<<teste.getTreeRepresetation();teste.getTreeRepresetation().toLocal8Bit()
    bitArray.setbit(QString().setNum(teste.TrashCalcutalion(TreatmentHeader),2),3);
    bitArray.setbit(QString().setNum(teste.getTreeRepresetation().size(),2),13);
    bitArray.setbit(QString().setNum(obj.getNome().size(),2),8);
    fileObjectOutput.open(fileOut.toLatin1().data(),std::ios::binary);
    QFile file(fileOut.toLatin1().data());
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    for(int i=0; i<bitArray.getQbitarray(false).size();i++)
    {

        uchar character = bitArray.getQbitarray(false).at(i).toLatin1();
        fileObjectOutput<<bitArray.getQbitarray(false).at(i).toLatin1();
        //out<<bitArray.getQbitarray(false).at(i).toLatin1();
    }
    fileObjectOutput<<obj.getNome().toStdString();
    for(int i=0; i<teste.getTreeRepresetation().size();i++)
    {
        uchar character = teste.getTreeRepresetation().at(i);
        fileObjectOutput<<character;
        //out <<teste.getTreeRepresetation().at(i).toLatin1();
        //qDebug()<<character;
    }

    bitArray.clearBitVector();
    for(int i=0 ; i<obj.getSize() ; i++)
    {
        //qDebug()<<(float)i/obj.getSize();
        uchar character = obj.toString(i);
        bitArray.setbit(teste.getHuffmanRepresetation(character));
    }
    for(int i=0; i<bitArray.getQbitarray().size();i++)
    {
        qDebug()<<(float)i/bitArray.getQbitarray().size();
        uchar character = bitArray.getQbitarray().at(i).toLatin1();
        if(!(teste.TrashCalcutalion(TreatmentHeader)==0 && bitArray.getQbitarray().size()==i+1))
            fileObjectOutput<<character;
        //out<<bitArray.getQbitarray(false).at(i).toLatin1();
    }
    bitArray.resize();
}

