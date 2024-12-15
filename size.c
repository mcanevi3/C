#include "size.h"
#include <stdio.h>

size size_create(unsigned int rows,unsigned int cols){
    size s;
    s.cols=cols;
    s.rows=rows;
    return s;
} 

void size_print(size s){
    printf("(%u,%u)",s.rows,s.cols);
}

unsigned short size_is_equal(size a,size b)
{
    return (unsigned short)(a.rows==b.rows)&(a.cols==b.cols);
}

size size_flip(size src)
{
    return size_create(src.cols,src.rows);
}