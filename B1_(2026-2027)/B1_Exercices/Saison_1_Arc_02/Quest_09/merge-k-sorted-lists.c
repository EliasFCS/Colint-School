#ifndef STRUCT_LISTNODE
#define STRUCT_LISTNODE
typedef struct s_listnode
{
    int val;
    struct s_listnode* next;
} listnode;
#endif

#ifndef STRUCT_LISTNODE_ARRAY
#define STRUCT_LISTNODE_ARRAY
typedef struct s_listnode_array
{
    int size;
    listnode **array;
} listnode_array;
#endif

static listnode* merge_two_lists(listnode* l1, listnode* l2)
{
    listnode dummy;
    dummy.val = 0;
    dummy.next = ((void*)0);
    listnode* tail = &dummy;

    while (l1 != ((void*)0) && l2 != ((void*)0)) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != ((void*)0)) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }

    return dummy.next;
}

static listnode* merge_k_helper(listnode** array, int start, int end)
{
    if (start > end) {
        return ((void*)0);
    }
    if (start == end) {
        return array[start];
    }

    int mid = start + (end - start) / 2;
    listnode* left = merge_k_helper(array, start, mid);
    listnode* right = merge_k_helper(array, mid + 1, end);

    return merge_two_lists(left, right);
}

listnode* merge_k_sorted_lists(listnode_array* param_1)
{
    if (param_1 == ((void*)0) || param_1->size == 0 || param_1->array == ((void*)0)) {
        return ((void*)0);
    }

    return merge_k_helper(param_1->array, 0, param_1->size - 1);
}