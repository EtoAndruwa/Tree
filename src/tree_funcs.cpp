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

void tree_dtor(Tree* tree_ptr)
{
    dtor_childs(tree_ptr->root);

    tree_ptr->error_code = TREE_OK;

    free(tree_ptr);
}

void dtor_childs(Node* node_ptr)
{
    node_ptr->node_value = POISON;
    if(node_ptr->left_child != nullptr)
    {
        dtor_childs(node_ptr->left_child);
        node_ptr->left_child = nullptr;
    }
    if(node_ptr->right_child != nullptr)
    {
        dtor_childs(node_ptr->right_child);
        node_ptr->right_child = nullptr;
    }

    free(node_ptr);
    node_ptr = nullptr;
}

Node* create_node(Tree* tree_ptr, Node_data node_value)
{
    Node* new_node_ptr = (Node*)calloc(1, sizeof(Node));

    if(new_node_ptr == nullptr)
    {   
        tree_ptr->error_code = ERR_TO_CALLOC_NODE;
    }

    new_node_ptr->node_value = node_value;
    new_node_ptr->left_child = nullptr;
    new_node_ptr->right_child = nullptr;

    return new_node_ptr;
}



