#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node_;
typedef struct node_ node;

struct LinkedList_
{
    node* head;
};
typedef struct LinkedList_ LinkedList;

LinkedList* create_list();
void destroy_list(LinkedList*);

void add_list(LinkedList* list,double data);
void print_list(LinkedList* list);
int count_list(LinkedList* list);

#endif