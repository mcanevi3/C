#ifndef NODE_H
#define NODE_H

struct node_ {
    double data;
    struct node_* next;
};
typedef struct node_ node;

node* create_node(double data);
void destroy_node(node* node);

#endif