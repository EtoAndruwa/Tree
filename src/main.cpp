#include "tree.h"

int main()
{   
    Tree tree_ptr = {};

    tree_ctor(&tree_ptr, 10);

    add_node_to_tree(&tree_ptr, tree_ptr.root, 1);
    add_node_to_tree(&tree_ptr, tree_ptr.root, 2);
    add_node_to_tree(&tree_ptr, tree_ptr.root, 3);  
    add_node_to_tree(&tree_ptr, tree_ptr.root, 11);
    add_node_to_tree(&tree_ptr, tree_ptr.root, 15);
    add_node_to_tree(&tree_ptr, tree_ptr.root, 0);

    create_graph_jpg(&tree_ptr, graph_before_txt_name);
    create_graph_jpg(&tree_ptr, graph_after_txt_name);

    // print_sorted_array(tree_ptr.root);
    print_leaves(tree_ptr.root);

    create_graph_jpg(&tree_ptr, graph_txt_name);

    tree_dtor(&tree_ptr);   

    return 0;
}
