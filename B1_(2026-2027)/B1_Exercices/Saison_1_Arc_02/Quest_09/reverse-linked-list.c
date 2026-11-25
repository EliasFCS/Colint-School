#ifndef STRUCT_LISTNODE
#define STRUCT_LISTNODE
typedef struct s_listnode
{
    int val;
    struct s_listnode* next;
} listnode;
#endif

listnode* reverse_linked_list(listnode* param_1)
{
    listnode* prev = ((void*)0);
    listnode* curr = param_1;
    listnode* next = ((void*)0);

    while (curr != ((void*)0)) {
        next = curr->next;    
        curr->next = prev;    
        prev = curr;          
        curr = next;          
    }

    return prev;
}