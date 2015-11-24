#include "nodes.h"
#include <cstdio>
#include<QDebug>

Nodes::Nodes(Nodes *Right, Nodes *Left, int frequency)
{

    this->Right = Right;
    this->Left = Left;
    this->frequency = frequency;
    this->leaf = false;

}

Nodes::Nodes(char element, unsigned int frequency)
{
    this->element = element;
    this->frequency = frequency;
    this->leaf = true;
}

char Nodes::getElement() const{
    return this->element;

}

int Nodes::getFrequency()const{
    return this->frequency;
}

bool Nodes::isLeaf()const{
    return this->leaf;
}

Nodes *Nodes::getRight() //Retorna um ponteiro de uma célula.
{
    return this->Right;
}
Nodes *Nodes::getLeft() // Retora um ponteiro de uma célula.
{
    return this->Left;
}
bool Nodes::operator > (Nodes secondelement) const
{
    bool retorna;

    if(this->getFrequency() != secondelement.getFrequency())
    {
        //qDebug()<<this->getElement()<<'='<<this->getFrequency()<<' '<<secondelement.getElement()<<'='<<secondelement.getFrequency();
        if(this->getFrequency() > secondelement.getFrequency())
        {
            retorna = true;
        }
        else retorna = false;

    }
    else
    {
        if(this->isLeaf() && !secondelement.isLeaf())
        {
            retorna = false;
        }
        if(!this->isLeaf() && secondelement.isLeaf())
        {
            retorna = true;
        }
        if(this->isLeaf() && secondelement.isLeaf())
        {
            if ((unsigned int)this->getElement() > (unsigned int)secondelement.getElement())
            {
                retorna = true;
            }

            else  retorna = false;
        }
    }

    return !retorna;


}

bool Nodes::operator < (Nodes secondelement) const
{

    return !(*this > secondelement); // Negação da primeira definição dos sinais.
}

bool Nodes::operator ==(Nodes secondelement) const // Esse const serve para manter essa referÊncia para smp no código
{
    if((*this > secondelement) == false && ((*this < secondelement) == false)){ // se ele não é maior que ou menor que então ele é igual.

        return true;
    }
    else false;
}

Nodes::Nodes()
{

}
void Nodes::setCodification(long int codification)
{
    sprintf(this->codification, "%ld", codification);
}

QString Nodes::getCodification()
{
   return QString (this->codification).remove(0,1);

}
