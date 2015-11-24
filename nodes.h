#ifndef NODES_H
#define NODES_H
#include <QString>


class Nodes
{
    char element;
    unsigned frequency;
    bool leaf;
    Nodes *Right;
    Nodes *Left;
    char codification[11]; // teríamos no máximo 2^8 elementos, mas para garantir ...11


public:
    Nodes();
    Nodes(Nodes *Right, Nodes *Left, int frequency);
    Nodes(char element, unsigned int frequency);

    char getElement() const;
    int getFrequency() const;
    bool isLeaf() const;

    Nodes *getRight();
    Nodes *getLeft();



    bool operator <(Nodes secondelement) const;
    bool operator >(Nodes secondelemnet) const;
    bool operator ==(Nodes secondelement) const;

    void setCodification(long int codification);
    QString getCodification();
};

#endif // NODES_H
