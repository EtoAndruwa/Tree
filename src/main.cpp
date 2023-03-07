#include "tree.h"

int main()
{   
    Tree tree_ptr = {};
    tree_ctor(&tree_ptr);

    Node* node1 = create_node(&tree_ptr, 2);
    Node* node2 = create_node(&tree_ptr, 3);
    Node* node3 = create_node(&tree_ptr, 4);
    Node* node4 = create_node(&tree_ptr, 5);
    Node* node5 = create_node(&tree_ptr, 6);
    Node* node6 = create_node(&tree_ptr, 7);
    Node* node7 = create_node(&tree_ptr, 8);

    tree_ptr.root = create_node(&tree_ptr, 1);
    link_node_left(tree_ptr.root, node1);
    link_node_right(tree_ptr.root, node2);
    link_node_left(node1, node5);
    link_node_right(node2, node3);
    link_node_right(node1, node4);

    create_graph_jpg(&tree_ptr);

    tree_dtor(&tree_ptr);

    return 0;
}

