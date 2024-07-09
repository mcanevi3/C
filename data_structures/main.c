#include <stdio.h>
#include "LinkedList.h"

int main()
{
    LinkedList* list=create_list();

    add_list(list,4);
    add_list(list,5);
    add_list(list,6);
    add_list(list,7);
    add_list(list,7);
    add_list(list,7);
    
    print_list(list);
    printf("\n");

    printf("index:%d\n",find_list_index(list,15));

    destroy_list(list);

    return 0;
}