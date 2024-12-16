#include "real.h"
#include "augmented_matrix.h"
#include <stdio.h>

int main(){
    matrix* A=matrix_create(List(1,1,3,2,4,5,6,0,1),size_create(3,3));
    matrix* b=matrix_create(List(1,7,9),size_create(3,1));
    augmatrix* prob=augmatrix_create(A,b);
    
    matrix* x=augmatrix_solve(prob,0);
    matrix_print(x);
    matrix* res=matrix_multiply(A,x);

    matrix_delete(res);
    matrix_delete(x);
    matrix_delete(A);
    matrix_delete(b);
    augmatrix_delete(prob);
    return 0;
}