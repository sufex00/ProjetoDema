#ifndef HUFFDECOTIFICATION_H
#define HUFFDECOTIFICATION_H
#include<QString>
#include"nodes.h"


class huffdecotification
{
    int sizeName;              //Tamanho do nome original do arquivo
    int sizeTree;              //Tamanho da representação da arvore
    int trash;                 //Tamanho do lixo
    int sizeFile;              //Tamanho
    QString fileName;          //Nome original do arquivo
    QByteArray treeRepresetation; //Representação da arvore
    int position;              //Posição atual do curso
    char *FileObjectInput;     //Nome do arquivo
    bool isEndBool;            //Verificador se o arquivo acabou
public:
    huffdecotification(QString FileOutput);
    QByteArray TreeRepresentation();
    bool isEnd();
    bool isElement(Nodes* node,QByteArray HuffmanCodification);
    char getElementTree(Nodes* node,QByteArray HuffmanCodification);
    int getTrash();
    int getSize();
    void printTree(Nodes* node, int level=0);
    QByteArray TreeHuffmanTreeLeft(QByteArray huff);
    QByteArray TreeHuffmanTreeRight(QByteArray huff);
    Nodes* generation(QByteArray Tree);
    QString getFileName();
};

#endif // HUFFDECOTIFICATION_H
