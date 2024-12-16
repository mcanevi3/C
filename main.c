#include "real.h"
#include "augmented_matrix.h"
#include <stdio.h>

int main(){
    matrix* A=matrix_create(List(1,1,3,2,4,5,6,0,1),size_create(3,3));
    matrix* b=matrix_create(List(1,7,9),size_create(3,1));

    printf("det:%f\n",matrix_det(A));    

    matrix_delete(A);
    matrix_delete(b);
    return 0;
}