#include "tree.h"

int main()
{   
    Tree tree_ptr = {};

    tree_ctor(&tree_ptr, 5);

    add_node_to_tree(&tree_ptr, tree_ptr.root, 2);
    add_node_to_tree(&tree_ptr, tree_ptr.root, 1);
    add_node_to_tree(&tree_ptr, tree_ptr.root, 4);
    add_node_to_tree(&tree_ptr, tree_ptr.root, 3);
    add_node_to_tree(&tree_ptr, tree_ptr.root, 8);
    add_node_to_tree(&tree_ptr, tree_ptr.root, 10);
    add_node_to_tree(&tree_ptr, tree_ptr.root, 11);
    add_node_to_tree(&tree_ptr, tree_ptr.root, 12);
    add_node_to_tree(&tree_ptr, tree_ptr.root, 9);
    add_node_to_tree(&tree_ptr, tree_ptr.root, 19);

    // print_sorted_array(tree_ptr.root);
    //print_leaves(tree_ptr.root);
    printf("Depth= %d", get_depth_tree(tree_ptr.root));

    create_graph_jpg(&tree_ptr, graph_txt_name);

    tree_dtor(&tree_ptr);   

    return 0;
}
