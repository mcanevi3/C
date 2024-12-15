#include "augmented_matrix.h"
#include <stdio.h>
#include <malloc.h>

augmatrix* augmatrix_create(matrix* left,matrix* right){
    augmatrix *m=0;
    if(left->size.rows!=right->size.rows)
    {
        fprintf(stderr, "Matrix rows not equal!\n", "string format", 30);
    }
    else
    {
        m=malloc(sizeof(augmatrix));
        m->left=matrix_duplicate(left);
        m->right=matrix_duplicate(right);
    }
    return m;
}
void augmatrix_delete(augmatrix* m){
    matrix_delete(m->left);
    matrix_delete(m->right);
    free(m);
}

void augmatrix_print(augmatrix* m){
    for (int i = 0; i < m->left->size.rows; i++)
    {
        for (int j = 0; j < m->left->size.cols; j++)
        {
            printf("%f ", m->left->data[i * m->left->size.cols + j]);
        }
        printf(" | ");
        for (int j = 0; j < m->right->size.cols; j++)
        {
            printf("%f ", m->right->data[i * m->right->size.cols + j]);
        }
        printf("\n");
    }
    printf("\n");
}
