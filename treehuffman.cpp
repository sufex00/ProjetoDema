#include "treehuffman.h"
#include"treatmentheader.h"
#include "file.h"
#include <QDebug>
#include <algorithm>
#include <QFileInfo>
#include <iostream>
#include<QString>

using namespace std;


TreeHuffman::TreeHuffman()
{
    this-> BagHuffman.reserve(260);   // escolhemos 260 para que não haja eventuais problemas de estouro de memória
}
void TreeHuffman::ordena() // função de ordenação
{
    std::sort (this->BagHuffman.begin(), this->BagHuffman.end());
}

void TreeHuffman::addNodes(Nodes newNodes){
    if(newNodes.getFrequency()>0)
    {
        this->BagHuffman.append(newNodes); // adiconando em filas o que estamos recebendo
        this->ordena();
    }
    sort (this->BagHuffman.begin(), this->BagHuffman.end());
}
void TreeHuffman::Teste() //Função feita para testar se ele está ordenando tudo ok
{
    this->ordena();
    for(int i = 0; i < BagHuffman.size(); i++)
    {
        qDebug() << "Elemento: " << BagHuffman.at(i).getElement()<< "Frequencia :" << BagHuffman.at(i).getFrequency();
    }
}
void TreeHuffman::BuildHuffman() // Função feita para a parte mais importante a construção da árvore.
{
    int last;
    int beforeLast;
    int PlusLasts; // varável para a soma dos ultimos números.

    while(this->BagHuffman.size()!=1)
    {
        last = this->BagHuffman.at(this->BagHuffman.size() -1).getFrequency();
        beforeLast = this->BagHuffman.at(this->BagHuffman.size() -2).getFrequency();

        PlusLasts = last + beforeLast;

        Nodes *NodeL = new Nodes(); // criando esse node para transformar os elementos em ponteiros;; Node esquerdo
        Nodes *NodeR = new Nodes(); // Node direito

        *NodeL = this->BagHuffman.at(this->BagHuffman.size()-1);
        *NodeR = this->BagHuffman.at(this->BagHuffman.size() -2);

        Nodes LastNode = Nodes(NodeL, NodeR,PlusLasts);

        this->BagHuffman.remove(this->BagHuffman.size()-2, 2 );
        this->addNodes(LastNode);

    }
    this->root = this->BagHuffman[0];//Não pode ser usado o .at porque o valor dele não pode ser 'const'
}
void TreeHuffman::printTree(Nodes* node, int level)
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

void TreeHuffman::BuildCodification(Nodes *root,long int level)
{
    if(root->isLeaf() == false)
    {
        BuildCodification(root->getRight(), 10*level + 1);
        BuildCodification(root->getLeft(),10*level);
    }

    if(root->isLeaf() == true)
    {

        root->setCodification(level);
        unsigned int character = root->getElement();
        this->huffmanRepresentationArray.insert(root->getElement(),root->getCodification());
    }
}

    QByteArray TreeHuffman::Sequency(Nodes *root)
    {


    }

void TreeHuffman::TreeHuffamanRepresetation(Nodes *root)
{
    if(root->isLeaf() == false)
    {
        this->treerepresetation.append(QString('*'));
        TreeHuffamanRepresetation(root->getLeft());
        TreeHuffamanRepresetation(root->getRight());
    }
    if(root->isLeaf()== true)
    {
        if(root->getElement() == '*'|| root->getElement()=='!')
        {
            this->treerepresetation.append(QString('!'));
        }
        this->treerepresetation.append((char)root->getElement());
    }

}
Nodes *TreeHuffman::getRoot()
{
    return  &this->BagHuffman[0];
}

QString TreeHuffman::getHuffmanRepresetation(char position)
{
    return this->huffmanRepresentationArray[position];

}

int TreeHuffman::TrashCalcutalion(TreatmentHeader tre)
{
    int numberBits=0;

    int trash;
    File obj = File(tre.getFileInput());

    for(unsigned int i=0; i<256; i++)
    {
        char p=i;
        numberBits += this->huffmanRepresentationArray[p].size() * obj.getFrequency((int)i);

    }
    trash= 8-(numberBits%8);
    if(trash ==8)
        trash=0;
    return trash;
}

QByteArray TreeHuffman::getTreeRepresetation()
{
    return this->treerepresetation;
}

