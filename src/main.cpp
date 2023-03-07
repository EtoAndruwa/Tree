#include "tree.h"

int main()
{   
    Tree tree_ptr = {};

    tree_ctor(&tree_ptr, 10);

    add_node_to_tree(&tree_ptr, tree_ptr.root, 1);
    add_node_to_tree(&tree_ptr, tree_ptr.root, 11);
    add_node_to_tree(&tree_ptr, tree_ptr.root, 15);
    add_node_to_tree(&tree_ptr, tree_ptr.root, 0);
    add_node_to_tree(&tree_ptr, tree_ptr.root, 2);

    create_graph_jpg(&tree_ptr);

    tree_dtor(&tree_ptr);

    return 0;
}
