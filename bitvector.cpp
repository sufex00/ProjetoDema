#include "bitvector.h"
#include <QByteArray>
#include <QString>
#include <QBitArray>
#include<QDebug>

BitVector::BitVector()
{
    this->biTvector.resize(200000); //O resize faz com que possamos deixar o bitvector com tamanho 2000
    size =0; // zerar o "array"
}

void BitVector::setbit(int posicion, int value) //Ao invés de trabalharmos com true or false
{                                               // trabalhamos com 0 e 1
     bool boolreturn;

    if(value == 0)
    {
        boolreturn = false;
    }
    else
    {
        boolreturn = true;
    }

    biTvector.setBit(posicion, boolreturn);
    if(posicion>size)
    {
        size=posicion;
    }
}

int BitVector::bitVectorAt(int pos)
{
    int boolReturn;
    if(biTvector.at(pos))
    {
        boolReturn = 1;
    }
    else
    {
        boolReturn = 0;
    }
    return boolReturn;
}

void BitVector::setbit(QString value, int sizemax, int pos)
{
    if(sizemax==-1)
    {
        sizemax=value.size();
    }
    if(pos == -1)
    {
        pos = size;
    }
    int i=sizemax-value.size();
    int j;
    for(j = 0; j < value.size();j++)
    {
        if(value.at(j)=='0')
        {
            biTvector[pos+i+j] = false;
        }
        if(value.at(j)=='1')
        {
            biTvector[pos+i+j] = true;
        }
    }
    size=pos+i+j;
}

int BitVector::setbit(int posicion)
{
    int boolreturn;
    if(biTvector.at(posicion))
    {
        boolreturn = 1;
    }

    else
    {
        boolreturn = 0;;
    }

    return boolreturn;
}


//QString BitVector::returnInBinary(bool trash) // É custoso para memória compactar tudo na memória e voltar// separamos o processo em treds
//{
//    unsigned int bit;
//    QString bitreturn=QString();
//    int i=0;

//    while(size-i>=8)
//    {
//        bit = 0x000;
//        for (int j = 0; j < 8; ++j)
//        {
//            bit = (bit<<1)|1; // deslocador de bits ta adicionando um bit da esquerda para direita
//        }
//        else
//        {
//            bit = bit<<1; // deslocador de bits ta adicionando um bit da esquerda para direita
//        }
//    }
//    i = i+8;
//    bitreturn.append(bit);

//if(trash) //aqui se tem uma sutileza note que o if não tem condição nenhuma, porem por se tratar de um boleano se ele for verdadeiro será executado
//{
//    bit = 0;
//    for (int j = 0; j < size; ++j)
//    {
//    if(BitVector[i+j])
//    {
//        bit = (bit<<1)|1; // deslocador de bits ta adicionando um bit da esquerda para direita
//    }
//        else
//    {
//        bit = bit <<1; // deslocador de bits ta adicionando um bit da esquerda para direita
//    }
//    }

//}

void BitVector::clear()
{
    biTvector.clear();
    this->biTvector.resize(200000);
}

int BitVector::getsize()
{
    return this->size;
}

int BitVector::resize()
{
    int position=size%8;
    QBitArray buffer;
    buffer.resize(2000);
    for (int i = 0; i < position; ++i)
    {
        buffer[i] = this->bitVectorAt(size-position +1);
    }
    biTvector.clear();


    this->biTvector=buffer;
    this->size=position;
}

void BitVector::setsize(int size)
{
    this->size=size;
}

QString BitVector::getQbitarray(bool WithTrash)
{
    unsigned int bit;
    QString bitReturn=QString();
    int i= 0;
    while(size-i>=8)
    {
        bit = 0x0000;
        for(int j= 0; j<8;j++ )
        {
            if (biTvector[i+j])
            {
                bit = (bit<<1)|1;

            }
            else
            {
                bit = bit<<1;
            }

        }
        i=i+8;
        bitReturn.append(bit);
    }
    if(WithTrash)
    {
        bit= 0;
        for(int j= 0; j<size-i;j++ )
        {
            if (biTvector[i+j])
            {
                bit = (bit<<1)|1;

            }
            else
            {
                bit = bit<<1;
            }

        }
        bit = bit<<(8-(size-i));
        bitReturn.append(bit);
    }
    return bitReturn;
}

void BitVector::clearBitVector()
{
    biTvector.clear();
    this->biTvector.resize(200000);
    size=0;
}
