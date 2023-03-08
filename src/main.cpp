#include "tree.h"

int main()
{   
    Tree tree_ptr = {};

    tree_ctor(&tree_ptr, 10);

    add_node_to_tree(&tree_ptr, tree_ptr.root, 5);  
    add_node_to_tree(&tree_ptr, tree_ptr.root, 7);
    add_node_to_tree(&tree_ptr, tree_ptr.root, 6);

    // add_node_to_tree(&tree_ptr, tree_ptr.root, 1);
    // add_node_to_tree(&tree_ptr, tree_ptr.root, 9);
    add_node_to_tree(&tree_ptr, tree_ptr.root, 13);




    create_graph_jpg(&tree_ptr, graph_before_txt_name);
    search_and_delete_node(tree_ptr.root, 5);
    create_graph_jpg(&tree_ptr, graph_after_txt_name);
    // add_node_to_tree(&tree_ptr, tree_ptr.root, 4);
    // add_node_to_tree(&tree_ptr, tree_ptr.root, 6);
    // add_node_to_tree(&tree_ptr, tree_ptr.root, 8);
    // add_node_to_tree(&tree_ptr, tree_ptr.root, 6);
    // add_node_to_tree(&tree_ptr, tree_ptr.root, 6);
   

    // print_sorted_array(tree_ptr.root);
    //print_leaves(tree_ptr.root);
    //printf("Depth= %d\n", get_depth_tree(tree_ptr.root));

    create_graph_jpg(&tree_ptr, graph_txt_name);
    //is_balanced(tree_ptr.root);

    tree_dtor(&tree_ptr);   

    return 0;
}
