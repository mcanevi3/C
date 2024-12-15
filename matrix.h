#ifndef MATRIX_H
#define MATRIX_H

#include "real.h"
#include "size.h"

struct smatrix{
    real* data;
    size size;
};
typedef struct smatrix matrix;


#endif