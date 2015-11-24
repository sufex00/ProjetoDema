#ifndef CELL_H
#define CELL_H


class Cell
{
    int size;
    char element;
    bool leaf;
public:

    Cell* left;
    Cell* right;

    Cell(int size, char element);
    Cell (int size, Cell* left, Cell* right);



};

#endif // CELL_H
