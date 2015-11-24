#ifndef BITVECTOR_H
#define BITVECTOR_H
#include <QString>
#include<QBitArray>


class BitVector
{
    QBitArray biTvector; //BitVector
    int size; //Tamanho do BitVector

public:
    BitVector();

    void setbit(int posisicion,int value);

    void setbit(QString value, int sizemax=-1, int pos=-1);

    int setbit(int posicion);

    int bitVectorAt(int pos);

    QString returnInBinary(bool trash);

    void clearBitVector();

    int getsize();

    void setsize();

    void clear();

    int resize();

    void setsize(int size);

    QString getQbitarray(bool WithTrash=true);


};

#endif // BITVECTOR_H
