#include "tree.h"

int main()
{   
    Tree tree_ptr = {};

    tree_ctor(&tree_ptr);
    graph_start(&tree_ptr);

    tree_ptr.root = create_node(&tree_ptr, 1);
    tree_ptr.root->left_child = create_node(&tree_ptr, 2);
    tree_ptr.root->right_child = create_node(&tree_ptr, 3);

    print_node_data(&tree_ptr, tree_ptr.root);
    print_node_data(&tree_ptr, tree_ptr.root->left_child);
    print_node_data(&tree_ptr, tree_ptr.root->right_child);

    print_node_links(&tree_ptr, tree_ptr.root);

    graph_end(&tree_ptr);

    create_graph_jpg();

    tree_dtor(&tree_ptr);

    return 0;
}

