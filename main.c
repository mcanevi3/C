#include "real.h"
#include "augmented_matrix.h"
#include <stdio.h>

int main(){
    matrix* A=matrix_create(List(1,0,0,0,1,0,0,0,1),size_create(3,3));
    matrix* b=matrix_create(List(1,2,3),size_create(3,1));
    augmatrix* prob=augmatrix_create(A,b);

    augmatrix_print(prob);

    matrix* c=matrix_diag(Vector(1,2,3));
    matrix_print(c);
    
    matrix_delete(A);
    matrix_delete(b);
    matrix_delete(c);
    augmatrix_delete(prob);
    return 0;
}