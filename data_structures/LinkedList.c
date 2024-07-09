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

bool remove_list(LinkedList* list,double data)
{
    if(list->head==0)
    {
        return false;
    }
    else if(list->head->data==data)
    {
        free(list->head);
        list->head=0;
    }
    else
    {
        node* temp=list->head;
        node* temp_old=list->head;
        while(temp->next!=0)
        {
            temp_old=temp;
            temp=temp->next;

            if(temp->data==data)
            {
                temp_old->next=temp->next;
                free(temp);
                return true;
                break;
            }
        }
        return false;
    }
}

bool find_list(LinkedList* list,double data)
{
    if(list->head==0)
    {
        return false;
    }
    else if(list->head->data==data)
    {
        return true;
    }
    else
    {
        node* temp=list->head;
        node* temp_old=list->head;
        while(temp->next!=0)
        {
            temp_old=temp;
            temp=temp->next;

            if(temp->data==data)
            {
                return true;
                break;
            }
        }
        return false;
    }
}

int find_list_index(LinkedList* list,double data)
{
    int index=-1;
    if(list->head==0)
    {
        index=-1;
    }
    else if(list->head->data==data)
    {
        index=0;
    }
    else
    {
        int i=0;
        node* temp=list->head;
        node* temp_old=list->head;
        while(temp->next!=0)
        {
            temp_old=temp;
            temp=temp->next;
            i++;
            if(temp->data==data)
            {
                index=i;
                break;
            }
        }
    }
    return index;
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

