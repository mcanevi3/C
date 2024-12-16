#ifndef MATRIX_H
#define MATRIX_H

#include "real.h"
#include "size.h"

struct smatrix{
    real* data;
    size size;
};
typedef struct smatrix matrix;

matrix* matrix_create(real[],size);
matrix* matrix_zeros(size);
matrix* matrix_identity(unsigned short);
matrix* matrix_diag(real[],unsigned int );

void matrix_delete(matrix*);

void matrix_print(matrix*);

real* matrix_at(matrix*,unsigned int,unsigned int);
matrix* matrix_copy(matrix *,unsigned int,unsigned int,size);
matrix* matrix_duplicate(matrix*);
matrix* matrix_col(matrix*,unsigned int);
matrix* matrix_row(matrix*,unsigned int);

matrix* matrix_transpose(matrix*);
matrix* matrix_add(matrix*,matrix*);
matrix* matrix_substract(matrix*,matrix*);
matrix* matrix_multiply(matrix*,matrix*);
matrix* matrix_scale(matrix*,real);
real matrix_dot_product(matrix*,matrix*);

void matrix_rowop(matrix*,char,real,unsigned int);
void matrix_rowadd(matrix* m,unsigned int,real,unsigned int);

#endif