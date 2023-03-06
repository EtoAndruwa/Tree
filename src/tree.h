#ifndef TREE_H
#define TREE_h

#include <stdio.h>
#include <stdlib.h>

static const char* graph_txt_name = "graph.txt";

typedef int Node_data; 

enum error_codes
{
    TREE_OK                = 0,
    ERR_TO_OPEN_GRAPH_TXT  = 1,
    ERR_TO_CLOSE_GRAPH_TXT = 2,
    ERR_TO_CALLOC_ROOT     = 3,
};

typedef struct Node
{
    Node_data node_value = 0;
    Node* left_child = nullptr;
    Node* right_child = nullptr;
}Node;

typedef struct Tree
{
    Node* root = nullptr;
    size_t error_code = TREE_OK;
}Tree;




size_t tree_ctor(Tree* tree_ptr);

size_t link_node_left();
size_t link_node_right();
size_t create_node();
size_t delete_node();
const char* enum_error_string(size_t error_code);
size_t graph_start(Tree* tree_struct);
size_t print_node_data(Tree* tree_struct, Node* node_ptr);
size_t print_node_links(Tree* tree_struct, Node* node_ptr);

size_t tree_dtor();
size_t graph_end(Tree* tree_struct);

#endif
