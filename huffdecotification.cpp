#include "huffdecotification.h"
#include"file.h"
#include"bitvector.h"
#include<math.h>
#include<iostream>

#include<QDebug>

using namespace std;

huffdecotification::huffdecotification(QString FileOutput)
{
    this->FileObjectInput=FileOutput.toLatin1().data();
    File* FileInput = new File(FileOutput);
    BitVector bitVector = BitVector();
    bitVector.setbit(QString().setNum(FileInput->toString(0),2),8);
    bitVector.setbit(QString().setNum(FileInput->toString(1),2),8);
    bitVector.setbit(QString().setNum(FileInput->toString(2),2),8);
    this->trash=0;
    this->sizeTree=0;
    this->sizeName=0;
    for(int i=2;i>=0;i--)
    {
        this->trash+=pow(2,2-i)*bitVector.bitVectorAt(i);
    }
    for(int i=15;i>=3;i--)
    {
        this->sizeTree+=pow(2,15-i)*bitVector.bitVectorAt(i);
    }
    for(int i=23;i>=16;i--)
    {
        this->sizeName+=pow(2,23-i)*bitVector.bitVectorAt(i);
    }
    for(int i=0;i<this->sizeName;i++)
    {
        this->fileName.append(FileInput->toString().at(3+i));
    }
    for(int i=3+this->sizeName;i<3+this->sizeName+this->sizeTree;i++)
    {
        this->treeRepresetation.append(FileInput->toString().at(i));
    }
    this->position=3+this->sizeName+this->sizeTree;
    this->isEndBool=false;
}

QByteArray huffdecotification::TreeRepresentation()
{
    return this->treeRepresetation;
}

bool huffdecotification::isEnd()
{
    return this->isEndBool;
}

bool huffdecotification::isElement(Nodes* node,QByteArray HuffmanCodification)
{
    bool boolReturn;
    if(HuffmanCodification.size()!=0)
    {
        if(node->isLeaf() != true)
        {
            if(HuffmanCodification.at(0)=='0')
            {
                boolReturn=isElement(node->getLeft(), HuffmanCodification.remove(0,1));
            }
            if(HuffmanCodification.at(0)=='1')
            {
                boolReturn=isElement(node->getRight(),HuffmanCodification.remove(0,1));
            }
        }
        if(node->isLeaf())
        {
            return true;
        }
    }
    else
        return false;
}

char huffdecotification::getElementTree(Nodes* node, QByteArray HuffmanCodification)
{
    char charReturn;
    if(node->isLeaf() != true)
    {
        if(HuffmanCodification.at(0)=='0')
        {
            charReturn=isElement(node->getLeft(), HuffmanCodification.remove(0,1));
        }
        if(HuffmanCodification.at(0)=='1')
        {
            charReturn=isElement(node->getRight(),HuffmanCodification.remove(0,1));
        }
    }
    if(node->isLeaf())
    {
        return node->getElement();
    }
}

int huffdecotification::getTrash()
{
    return this->trash;
}
int huffdecotification::getSize()
{
    return this->sizeFile;
}

void huffdecotification::printTree(Nodes* node, int level)
{
    if(node->isLeaf() != true)
    {
        printTree(node->getLeft(), level +1);
        cout << qPrintable(QString("\t").repeated(level)) << node->getFrequency() << endl;
        printTree(node->getRight(), level +1);
    }
    if(node->isLeaf())
    {
        cout << qPrintable(QString("\t").repeated(level)) << "c=" << node->getCodification().toLatin1().data() << "e=" <<  node->getElement() <<endl;
    }
}

QByteArray huffdecotification::TreeHuffmanTreeLeft(QByteArray huff)
{
    QByteArray leftTree;
    QList<char> verification;
    if(huff.at(0)=='*' && huff.at(1)=='*')
    {
        verification.push_back('*');
        for(int i=1; i<huff.size();i++)
        {
            if(huff.at(i)=='*' && huff.at(i-1)!='!')
            {
                verification.push_back('*');
            }
            else
            {
                if(huff.at(i)!='!')
                    verification.pop_back();
            }
            leftTree.append(huff.at(i));
            if(verification.isEmpty())
            {
                break;
            }
        }
    }
    else {
        leftTree.clear();

        leftTree.append(huff.at(1));
        if(huff.at(1)=='!'){
            leftTree.clear();
            leftTree.append(huff.at(2));
        }
    }
    return leftTree;
}

QByteArray huffdecotification::TreeHuffmanTreeRight(QByteArray huff)
{
    QString TreeHuffmanDecodificationLeft=TreeHuffmanTreeLeft(huff);
    if(TreeHuffmanDecodificationLeft.size()==1)
    {
        if(TreeHuffmanDecodificationLeft.at(0).toLatin1()=='*' || TreeHuffmanDecodificationLeft.at(0).toLatin1()=='!')
            huff.remove(1,TreeHuffmanDecodificationLeft.size());
    }
    huff.remove(1,TreeHuffmanDecodificationLeft.size());
    QByteArray TreeHuffmanDecodificationRight=TreeHuffmanTreeLeft(huff);
    return TreeHuffmanDecodificationRight;
}

Nodes* huffdecotification::generation(QByteArray Tree)
{
    Nodes* Left;
    Nodes* Right;
    QByteArray TreeLeft=TreeHuffmanTreeLeft(Tree);
    QByteArray TreeRight=TreeHuffmanTreeRight(Tree);
    if(TreeLeft.size()>1)
    {
        Left = generation(TreeLeft);
    }
    else
    {
        Left=new Nodes(TreeLeft.at(0),0);
    }
    if(TreeRight.size()>1)
    {
        Right = generation(TreeRight);
    }
    else
    {
        Right = new Nodes(TreeRight.at(0),0);
    }
    return new Nodes(Right,Left,0);
}

QString huffdecotification::getFileName()
{
    return this->fileName;
}
