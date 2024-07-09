#include "node.h"
#include "LinkedList.h"

#include <stdlib.h>
#include <stdio.h>

LinkedList* create_list()
{
    LinkedList* list=0;
    list=malloc(sizeof(LinkedList));
    list->head=0;
    return list;
}

void destroy_list(LinkedList* list)
{
    node *temp,*temp_old;
    while(list->head->next!=0)
    {
        temp=list->head;
        temp_old=temp;

        while(temp->next!=0)
        {
            temp_old=temp;
            temp=temp->next;
        }
        free(temp);
        temp_old->next=0;
    }
    free(list->head);
    list->head=0;

    free(list);
}

void add_list(LinkedList* list,double data)
{
    if(list->head==0)
    {
        list->head=create_node(data);
    }
    else if(list->head->next==0)
    {
        list->head->next=create_node(data);
    }
    else
    {
        node* temp=list->head;
        while(temp->next!=0)
        {
            temp=temp->next;
        }
        temp->next=create_node(data);
    }
}

void print_list(LinkedList* list)
{
    if(list->head==0)
    {
        printf("List is empty!");
    }
    else if(list->head->next==0)
    {
        printf("%f ",list->head->data);
    }
    else
    {
        node* temp=list->head;
        printf("%f ",temp->data);
        while(temp->next!=0)
        {
            temp=temp->next;
            printf("%f ",temp->data);
        }
    }
}

int count_list(LinkedList* list)
{
    if(list->head==0)
    {
        return 0;
    }
    else if(list->head->next==0)
    {
        return 1;
    }
    else
    {
        node* temp=list->head;
        int len=1;
        while(temp->next!=0)
        {
            temp=temp->next;
            len++;
        }
        return len;
    }
}
