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
void matrix_rowadd(matrix*,unsigned int,real,unsigned int);
void matrix_row_interchange(matrix*,unsigned int,unsigned int);
void matrix_col_interchange(matrix*,unsigned int,unsigned int);

real matrix_sum_row(matrix*,unsigned int);
real matrix_sum_col(matrix*,unsigned int);

unsigned short matrix_is_square(matrix*);
void matrix_order_pivots(matrix*);
real matrix_det(matrix*);
matrix* matrix_inv(matrix*);

unsigned short matrix_has(matrix*,real);
#endif