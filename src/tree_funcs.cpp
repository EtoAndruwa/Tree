#include "tree.h"

size_t tree_ctor(Tree* tree_ptr)
{
    tree_ptr->root = (Node*)calloc(1, sizeof(Node));

    if(tree_ptr->root == nullptr)
    {
        tree_ptr->error_code = ERR_TO_CALLOC_ROOT;
        return ERR_TO_CALLOC_ROOT;
    }

    tree_ptr->error_code = TREE_OK;
}


