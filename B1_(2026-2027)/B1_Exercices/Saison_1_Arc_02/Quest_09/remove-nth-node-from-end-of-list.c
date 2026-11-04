#ifndef STRUCT_LISTNODE
#define STRUCT_LISTNODE
typedef struct s_listnode
{
    int val;
    struct s_listnode* next;
} listnode;
#endif

listnode* remove_nth_node_from_end_of_list(listnode* param_1, int param_2)
{
    if (param_1 == ((void*)0)) {
        return ((void*)0);
    }

    listnode dummy;
    dummy.val = 0;
    dummy.next = param_1;

    listnode* fast = &dummy;
    listnode* slow = &dummy;

    for (int i = 0; i < param_2; i++) {
        if (fast != ((void*)0)) {
            fast = fast->next;
        }
    }

    while (fast != ((void*)0) && fast->next != ((void*)0)) {
        fast = fast->next;
        slow = slow->next;
    }

    if (slow != ((void*)0) && slow->next != ((void*)0)) {
        listnode* temp = slow->next;
        slow->next = slow->next->next;
    }

    return dummy.next;
}