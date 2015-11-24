#ifndef COMPRESSION_H
#define COMPRESSION_H

#include "treehuffman.h"
#include "file.h"
#include "bitvector.h"
#include<QDebug>
#include <fstream>
#include"treatmentheader.h"

class compression
{

public:
    compression();
    void operation(TreatmentHeader TreatmentHeader);
};

#endif // COMPRESSION_H
