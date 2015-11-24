#ifndef DECOMPRESSION_H
#define DECOMPRESSION_H

#include "treatmentheader.h"
#include "treehuffman.h"
#include"file.h"
#include"bitvector.h"
#include"nodes.h"
#include"huffdecotification.h"
#include <iostream>

class decompression
{
public:
    decompression();
    void operation (TreatmentHeader treatmentHeader);
};

#endif // DECOMPRESSION_H
