#include "augmented_matrix.h"
#include <stdio.h>
#include <malloc.h>

augmatrix* augmatrix_create(matrix* left,matrix* right){
    augmatrix *m=0;
    if(left->size.rows!=right->size.rows)
    {
       Error("Matrix rows not equal!\n");
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

matrix* augmatrix_solve(augmatrix* m,unsigned short debug)
{
    augmatrix_order_pivots(m);
    if(debug==1)augmatrix_print(m);

    short type=0;
    matrix* temp=0;
    for(unsigned int k=1;k<m->left->size.rows;k++)
    {
        if(matrix_sum_row(m->left,k)==0)
        {
            temp=matrix_row(m->right,k);
            if(matrix_has(temp,0))
            {
                if(type<2)
                    type=1;
            }
            else
            {
                type=2;
            }
        }
    }
    matrix_delete(temp);

    switch (type)
    {
    case 1:
        printf("Infinetly many solutions!\n");
        return 0;
    case 2:
        printf("No solution!\n");
        return 0;
    default:
        break;
    }


    float factor=0;
    unsigned int col_count_right=m->right->size.cols;
    unsigned int row_count=m->left->size.rows;


    for(unsigned int i=1;i<=row_count;i++)
    {
        // pivot
        factor=*matrix_at(m->left,i,i);
        matrix_rowop(m->left,'/',factor,i);matrix_rowop(m->right,'/',factor,i);

        if(i+1<=row_count)
        {
            //same column
            for(int k=i+1;k<=row_count;k++)
            {
                factor=*matrix_at(m->left,k,i);
                matrix_rowadd(m->left,k,-1.0*factor,i);matrix_rowadd(m->right,k,-1.0*factor,i);
            }
        }

        if(debug==1)augmatrix_print(m);
    }
    
    //now back substitution
    for(unsigned int i=row_count;i>=1;i--)
    {
        //same column
        for(int k=1;k<=i-1;k++)
        {
            factor=*matrix_at(m->left,k,i);
            matrix_rowadd(m->left,k,-1.0*factor,i);matrix_rowadd(m->right,k,-1.0*factor,i);
        }
        if(debug==1)augmatrix_print(m);
    }
    return matrix_duplicate(m->right);
}

void augmatrix_order_pivots(augmatrix* m)
{
    for(int k=1;k<m->left->size.rows;k++)
    {
        if(matrix_sum_row(m->left,k)==0)
        {
            //zero pivot
            matrix_row_interchange(m->left,k,m->left->size.rows);matrix_row_interchange(m->right,k,m->right->size.rows);
        }
    }
}