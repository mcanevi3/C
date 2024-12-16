#include "matrix.h"
#include <malloc.h>
#include <stdio.h>

matrix *matrix_create(real data[], size size)
{
    matrix *m = malloc(sizeof(matrix));
    m->data = 0;
    m->size = size;
    m->data = malloc(size.cols * size.rows * sizeof(real));
    for (int i = 0; i < size.cols * size.rows; i++)
    {
        m->data[i] = data[i];
    }
    return m;
}

matrix *matrix_zeros(size size)
{
    matrix *m = malloc(sizeof(matrix));
    m->data = 0;
    m->size = size;
    m->data = malloc(size.cols * size.rows * sizeof(real));
    for (int i = 0; i < size.cols * size.rows; i++)
    {
        m->data[i] = 0;
    }
    return m;
}

void matrix_delete(matrix *m)
{
    free(m->data);
    free(m);
}

real *matrix_at(matrix *m, unsigned int i, unsigned int j)
{
    real *data = 0;
    if (m->data == 0)
    {
        Error("Matrix empty!\n");
    }
    else if ((i - 1) >= m->size.rows)
    {
        Error("Row out of range!\n");
    }
    else if ((j - 1) >= m->size.cols)
    {
        Error("Column out of range!\n");
    }
    else
    {
        data = &m->data[(i - 1) * m->size.cols + (j - 1)];
    }
    return data;
}

void matrix_print(matrix *m)
{
    for (int i = 0; i < m->size.rows; i++)
    {
        for (int j = 0; j < m->size.cols; j++)
        {
            printf("%f ", m->data[i * m->size.cols + j]);
        }
        printf("\n");
    }
    printf("\n");
}

matrix *matrix_copy(matrix *src, unsigned int i1, unsigned int j1, size s)
{
    matrix *dest = matrix_zeros(s);
    for (int i = i1; i < i1 + s.rows; i++)
    {
        for (int j = j1; j < j1 + s.cols; j++)
        {
            dest->data[(i - i1) * s.cols + (j - j1)] = src->data[i * src->size.cols + j];
        }
    }
    return dest;
}

matrix *matrix_col(matrix *m, unsigned int j)
{
    matrix *data = 0;
    if (m->data == 0)
    {
        Error("Matrix empty!\n");
    }
    else if ((j - 1) >= m->size.cols)
    {
        Error("Column out of range!\n");
    }
    else
    {
        data = matrix_copy(m, 0, j - 1, size_create(m->size.rows, 1));
    }
    return data;
}

matrix *matrix_row(matrix *m, unsigned int i)
{
    matrix *data = 0;
    if (m->data == 0)
    {
        Error("Matrix empty!\n");
    }
    else if ((i - 1) >= m->size.rows)
    {
        Error("Column out of range!\n");
    }
    else
    {
        data = matrix_copy(m, i - 1, 0, size_create(1, m->size.cols));
    }
    return data;
}

matrix *matrix_duplicate(matrix *src)
{
    return matrix_copy(src, 0, 0, src->size);
}

matrix *matrix_transpose(matrix *src)
{
    matrix *dest = matrix_zeros(size_flip(src->size));
    for (int i = 1; i <= dest->size.rows; i++)
    {
        for (int j = 1; j <= dest->size.cols; j++)
        {
            *matrix_at(dest, i, j) = *matrix_at(src, j, i);
        }
    }
    return dest;
}

matrix *matrix_add(matrix *a, matrix *b)
{
    matrix *c = 0;
    if (!size_is_equal(a->size, b->size))
    {
        Error("Matrix sizes not equal!\n");
    }
    else
    {
        c = matrix_duplicate(a);
        for (int i = 0; i < c->size.rows; i++)
        {
            for (int j = 0; j < c->size.cols; j++)
            {
                c->data[i * c->size.cols + j] = c->data[i * c->size.cols + j] + b->data[i * c->size.cols + j];
            }
        }
    }
    return c;
}

matrix *matrix_substract(matrix *a, matrix *b)
{
    matrix *c = 0;
    if (!size_is_equal(a->size, b->size))
    {
        Error("Matrix sizes not equal!\n");
    }
    else
    {
        c = matrix_duplicate(a);
        for (int i = 0; i < c->size.rows; i++)
        {
            for (int j = 0; j < c->size.cols; j++)
            {
                c->data[i * c->size.cols + j] = c->data[i * c->size.cols + j] - b->data[i * c->size.cols + j];
            }
        }
    }
    return c;
}

matrix *matrix_multiply(matrix *a, matrix *b)
{
    matrix *c = 0;

    if (a->size.cols != b->size.rows)
    {
        Error("Matrix sizes not equal!\n");
    }
    else
    {
        c = matrix_zeros(size_create(a->size.rows, b->size.cols));
        matrix *col;
        matrix *T;
        matrix *res;

        unsigned int len = a->size.cols;
        for (int p = 1; p <= a->size.rows; p++)
        {
            T = matrix_col(b, p);
            col = matrix_col(a, 1);
            res = matrix_zeros(col->size);
            for (int k = 1; k <= len; k++)
            {
                col = matrix_col(a, k);
                res = matrix_add(res, matrix_scale(col, *matrix_at(T, k, 1)));
            }
            for (int k = 1; k <= a->size.rows; k++)
            {
                *matrix_at(c, k, p) = *matrix_at(res, k, 1);
            }
        }
        matrix_delete(T);
        matrix_delete(col);
        matrix_delete(res);
    }
    return c;
}

real matrix_dot_product(matrix *a, matrix *b)
{
    real res = 0;
    if (!size_is_equal(size_flip(a->size), b->size))
    {
        Error("Matrix are not compatible!\n");
    }
    else if (!(b->size.rows == 1 || b->size.cols == 1))
    {
        Error("Matrices need to be vectors!\n");
    }
    else
    {
        unsigned int len = 0;
        if (b->size.rows == 1)
        {
            len = b->size.cols;
            for (int i = 1; i <= len; i++)
            {
                res += (*matrix_at(a, i, 1)) * (*matrix_at(b, 1, i));
            }
        }
        else
        {
            len = b->size.rows;
            for (int i = 1; i <= len; i++)
            {
                res += (*matrix_at(a, 1, i)) * (*matrix_at(b, i, 1));
            }
        }
    }
    return res;
}

matrix *matrix_scale(matrix *src, real scalar)
{
    matrix *res = matrix_duplicate(src);
    for (int i = 1; i <= src->size.rows; i++)
    {
        for (int j = 1; j <= src->size.cols; j++)
        {
            *matrix_at(res, i, j) = scalar * (*matrix_at(src, i, j));
        }
    }
    return res;
}

matrix* matrix_identity(unsigned short size)
{
    matrix *m =0;
    m=matrix_zeros(size_create(size,size));
    for (int i = 0; i < size ; i++)
    {
        m->data[i*size+i] = 1;
    }
    return m;
}

matrix* matrix_diag(real data[],unsigned int len)
{
    matrix* m=matrix_zeros(size_create(len,len));
    for (int i = 0; i < len ; i++)
    {
        m->data[i*len+i] = data[i];
    }

    return m;
}
