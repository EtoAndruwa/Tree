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

Node* delete_node(Node* deleted_node, Node* replacing_node)
{
    if(deleted_node == nullptr)
    {
        return nullptr;
    }
    else
    {
        if(replacing_node->left_child == nullptr && replacing_node->right_child == nullptr)
        {   
            if(replacing_node->parent_node->left_child == replacing_node)
            {
                replacing_node->parent_node->left_child = nullptr;
            }
            else 
            {
                replacing_node->parent_node->right_child = nullptr;
            }

            return replacing_node;          
        }

        if(replacing_node->left_child != nullptr && replacing_node->right_child != nullptr)
        {
            Node* new_node = search_left(replacing_node->right_child);

            if(new_node->parent_node->left_child == new_node)
            {
                new_node->parent_node->left_child = nullptr;
            }
            else 
            {
                new_node->parent_node->right_child = nullptr;
            }

            if(deleted_node->parent_node->left_child == deleted_node)
            {
                deleted_node->parent_node->left_child = new_node;
            }
            else 
            {
                deleted_node->parent_node->right_child = new_node;
            }

            if(deleted_node->right_child != new_node)
            {
                new_node->right_child = deleted_node->right_child;
            }
            if(deleted_node->left_child != new_node)
            {
                new_node->left_child = deleted_node->left_child;
            }

            deleted_node->node_value = POISON;
            free(deleted_node);
        }
        if(replacing_node->left_child != nullptr && replacing_node->right_child == nullptr)
        {
            Node* new_left_node = delete_node(deleted_node, replacing_node->left_child);
            return new_left_node;
        }
        if(replacing_node->left_child == nullptr && replacing_node->right_child != nullptr)
        {
            Node* new_right_node = delete_node(deleted_node, replacing_node->right_child);
            return new_right_node;
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

void print_sorted_array(Node* node_ptr)
{
    if(node_ptr->left_child == nullptr && node_ptr->right_child == nullptr)
    {
        printf("%d ", node_ptr->node_value);
        return;
    }
    if(node_ptr->left_child != nullptr)
    {
        print_sorted_array(node_ptr->left_child);
    }
    printf("%d ", node_ptr->node_value);
    if(node_ptr->right_child != nullptr)
    {
        print_sorted_array(node_ptr->right_child);
    }
}

void print_leaves(Node* node_ptr)
{
    if(node_ptr->left_child == nullptr && node_ptr->right_child == nullptr)
    {
        printf("%d ", node_ptr->node_value);
        return;
    }
    if(node_ptr->left_child != nullptr)
    {
        print_leaves(node_ptr->left_child);
    }
    if(node_ptr->right_child != nullptr)
    {
        print_leaves(node_ptr->right_child);
    }
}

size_t get_depth_tree(Node* node_ptr)
{
    if(node_ptr->left_child == nullptr && node_ptr->right_child == nullptr)
    {
        return 1;
    }
    else
    {
        size_t Depth_left = 0;
        size_t Depth_right = 0;

        if(node_ptr->left_child != nullptr)
        {
            Depth_left = get_depth_tree(node_ptr->left_child);    
        }
        Depth_left++;

        if(node_ptr->right_child != nullptr)
        {
            Depth_right = get_depth_tree(node_ptr->right_child); 
        }
        Depth_right++;

        return ((Depth_right >= Depth_left)? Depth_right: Depth_left);
    }
}

void is_balanced(Node* node_ptr)
{
    int Depth_left_sub_t  = 0;
    int Depth_right_sub_t = 0;

    if(node_ptr->left_child != nullptr)
    {
        Depth_left_sub_t = get_depth_tree(node_ptr->left_child);
    }
    if(node_ptr->right_child != nullptr)
    {
        Depth_right_sub_t = get_depth_tree(node_ptr->right_child);
    }

    // printf("Node_ptr: %d\n", node_ptr->node_value);
    // printf("Depth_left_sub_t: %d\n", Depth_left_sub_t);
    // printf("Depth_right_sub_t: %d\n", Depth_right_sub_t);

    if((Depth_left_sub_t - Depth_right_sub_t) > 1 || (Depth_right_sub_t - Depth_left_sub_t) > 1)
    {
        printf("Disbalanced\n");
        return;
    }
    else
    {
        printf("Balanced\n");
    }
}

void search_and_delete_node(Node* root_node, Node_data node_value)
{
    Node* node_delete_ptr = search_node(root_node, node_value);
    Node* replacing_node = delete_node(node_delete_ptr, node_delete_ptr);

}

Node* search_left(Node* node_ptr)
{
    if(node_ptr->left_child == nullptr && node_ptr->right_child == nullptr)
    {
        return node_ptr;
    }
    else if(node_ptr->left_child != nullptr && node_ptr->right_child != nullptr)
    {
        search_left(node_ptr->left_child);
    }
    else if(node_ptr->left_child != nullptr && node_ptr->right_child == nullptr)
    {
        search_left(node_ptr->left_child);
    }
    else if(node_ptr->left_child == nullptr && node_ptr->right_child != nullptr)
    {
        search_left(node_ptr->right_child);
    }
}

