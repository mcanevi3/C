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
