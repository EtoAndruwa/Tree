#include "tree.h"

int main()
{   
    Tree tree_ptr = {};
    tree_ctor(&tree_ptr);

    tree_ptr.root = create_node(&tree_ptr, 7);
    add_node_to_tree(&tree_ptr, tree_ptr.root, 2);
    add_node_to_tree(&tree_ptr, tree_ptr.root, 9);
    add_node_to_tree(&tree_ptr, tree_ptr.root, 8);
    add_node_to_tree(&tree_ptr, tree_ptr.root, 3);
    add_node_to_tree(&tree_ptr, tree_ptr.root, 1);

    create_graph_jpg(&tree_ptr);

    tree_dtor(&tree_ptr);

    return 0;
}

