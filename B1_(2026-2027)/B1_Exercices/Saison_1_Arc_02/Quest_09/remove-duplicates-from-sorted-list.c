#ifndef STRUCT_LISTNODE
#define STRUCT_LISTNODE
typedef struct s_listnode
{
    int val;
    struct s_listnode* next;
} listnode;
#endif

listnode* remove_duplicates_from_sorted_list(listnode* param_1)
{
    if (param_1 == ((void*)0)) {
        return ((void*)0);
    }

    listnode* curr = param_1;

    
    while (curr != ((void*)0) && curr->next != ((void*)0)) {
        if (curr->val == curr->next->val) {
            
            listnode* duplicate = curr->next;
            curr->next = curr->next->next;
            
        } else {
            
            curr = curr->next;
        }
    }

    return param_1;
}