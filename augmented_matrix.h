#ifndef AUGMENTED_MATRIX_H
#define AUGMENTED_MATRIX_H

#include "matrix.h"

struct saugmatrix{
    matrix* left;
    matrix* right;
};
typedef struct saugmatrix augmatrix;

augmatrix* augmatrix_create(matrix*,matrix*);
void augmatrix_delete(augmatrix*);

void augmatrix_print(augmatrix*);

#endif