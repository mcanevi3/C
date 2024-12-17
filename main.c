#include "real.h"
#include "augmented_matrix.h"
#include <stdio.h>

int main(){
    matrix* A=matrix_create(List(1,1,3,2,4,5,6,0,1),size_create(3,3));
    // matrix* A=matrix_create(List(0,1,0,1,0,0,0,0,1),size_create(3,3));
    matrix* b=matrix_create(List(1,0,9),size_create(3,1));

    matrix* Ainv=matrix_inv(A);
    matrix_print(Ainv);

    matrix_delete(Ainv);
    matrix_delete(A);
    matrix_delete(b);
    return 0;
}