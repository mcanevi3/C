#include <stdlib.h>
#include <stdio.h>

#include "node.h"

node* create_node(double data)
{
    node* n=0;
    n=(node*)malloc(sizeof(node));
    if(n==0)
    {
        printf("Could not create node!!!\n");
        return 0;
    }
    n->data=data;
    n->next=0;

    return n;
}

void destroy_node(node* n)
{
    if(n!=0)
        free(n);
}
