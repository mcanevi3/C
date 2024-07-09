#include <stdio.h>
#include "LinkedList.h"

int main()
{
    LinkedList* list=create_list();

    add_list(list,4);
    add_list(list,5);
    add_list(list,6);
    add_list(list,7);
    
    printf("count:%d\n",count_list(list));

    destroy_list(list);

    return 0;
}