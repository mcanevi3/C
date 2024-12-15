#include "augmented_matrix.h"
#include <stdio.h>

int main(){
    matrix* A=matrix_create((real[]){1,0,0,0,1,0,0,0,1},size_create(3,3));
    matrix* b=matrix_create((real[]){1,2,3},size_create(3,1));
    augmatrix* prob=augmatrix_create(A,b);

    augmatrix_print(prob);
    
    matrix_delete(A);
    matrix_delete(b);
    augmatrix_delete(prob);
    return 0;
}