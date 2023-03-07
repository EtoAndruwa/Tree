#include "tree.h"

size_t tree_ctor(Tree* tree_ptr, Node_data root_value)
{
    tree_ptr->root = create_node(tree_ptr, root_value);

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
    new_node_ptr->parent_node = nullptr;
    new_node_ptr->left_child = nullptr;
    new_node_ptr->right_child = nullptr;

    return new_node_ptr;
}

void link_node_left(Node* parent_ptr, Node* child_ptr)
{
    parent_ptr->left_child = child_ptr;
    child_ptr->parent_node = parent_ptr;
}

void link_node_right(Node* parent_ptr, Node* child_ptr)
{
    parent_ptr->right_child = child_ptr;
    child_ptr->parent_node = parent_ptr;
}

size_t add_node_to_tree(Tree* tree_ptr, Node* node_ptr, Node_data node_value)
{
    if((node_ptr->node_value > node_value) && (node_ptr->left_child == nullptr))
    {
        Node* new_node_ptr = create_node(tree_ptr, node_value);
        if(tree_ptr->error_code != TREE_OK)
        {
            return tree_ptr->error_code;
        }
        link_node_left(node_ptr, new_node_ptr); 
    }
    else if((node_ptr->node_value > node_value) && (node_ptr->left_child != nullptr))
    {
        add_node_to_tree(tree_ptr, node_ptr->left_child, node_value);
    }
    else if((node_ptr->node_value < node_value) && (node_ptr->right_child == nullptr))
    {
        Node* new_node_ptr = create_node(tree_ptr, node_value);
        if(tree_ptr->error_code != TREE_OK)
        {
            return tree_ptr->error_code;
        }
        link_node_right(node_ptr, new_node_ptr); 
    }
    else if((node_ptr->node_value < node_value) && (node_ptr->right_child != nullptr))
    {
        add_node_to_tree(tree_ptr, node_ptr->right_child, node_value);
    }
    else    
    {
        return 0;
    }
}

void delete_node(Node* node_ptr, Node_data search_value)
{
    Node* node_delte_ptr = search_node(node_ptr, search_value);

    if(node_delte_ptr == nullptr)
    {
        return;
    }
    else
    {
        if(node_delte_ptr->left_child == nullptr && node_delte_ptr->right_child == nullptr)
        {
            node_delte_ptr->node_value = POISON;
            if(node_delte_ptr->parent_node->left_child->node_value == node_delte_ptr->node_value)
            {
                node_delte_ptr->parent_node->left_child = nullptr;
            }
            else
            {
                node_delte_ptr->parent_node->right_child = nullptr;
            }
            free(node_delte_ptr);
            node_delte_ptr = nullptr;
        }
    }
}

Node* search_node(Node* node_ptr, Node_data search_value)
{
    if(node_ptr->node_value == search_value)
    {
        return node_ptr;
    }
    else if(node_ptr->node_value > search_value && node_ptr->left_child != nullptr)
    {
        search_node(node_ptr->left_child, search_value);
    }
    else if(node_ptr->node_value < search_value && node_ptr->right_child != nullptr)
    {
        search_node(node_ptr->right_child, search_value);
    }
    else    
    {   
        return nullptr;
    }
}
