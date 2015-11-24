#include "cell.h"

Cell::Cell(int size, char element)
{
    this->size = size;
    this->element=element;
    this->leaf=true;
}

Cell::Cell(int size, Cell* left, Cell* right)
{
    this->size=size;
    this->left=left;
    this->right=right;
    this->leaf=false;
}
