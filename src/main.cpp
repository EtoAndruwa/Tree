#include "tree.h"

int main()
{   
    Tree tree_ptr = {};

    tree_ctor(&tree_ptr);
    graph_start(&tree_ptr);
    print_node_data(&tree_ptr, tree_ptr.root);
    graph_end(&tree_ptr);

    free(tree_ptr.root);

    return 0;
}

