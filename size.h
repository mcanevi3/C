#ifndef SIZE_H
#define SIZE_H

struct ssize{
    unsigned int rows;
    unsigned int cols;
};

typedef struct ssize size;

size size_create(unsigned int,unsigned int); 
void size_print(size);
#endif