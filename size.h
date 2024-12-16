#ifndef SIZE_H
#define SIZE_H

struct ssize{
    unsigned int rows;
    unsigned int cols;
};

typedef struct ssize size;

size size_create(unsigned int,unsigned int); 
void size_print(size);
unsigned short size_is_equal(size,size);
size size_flip(size);
unsigned short size_is_square(size);
#endif