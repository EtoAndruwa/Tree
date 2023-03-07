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
    ERR_TO_CALLOC_NODE     = 4,
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

const Node_data POISON = 0xDED;


size_t tree_ctor(Tree* tree_ptr);
void tree_dtor(Tree* tree_ptr);
void dtor_childs(Node* node_ptr);
void link_node_left(Node* parent_ptr, Node* child_ptr);
void link_node_right(Node* parent_ptr, Node* child_ptr);
Node* create_node(Tree* tree_ptr, Node_data node_value);
size_t delete_node();
const char* enum_error_string(size_t error_code);
size_t graph_start(Tree* tree_struct);
size_t print_node_data(Tree* tree_struct, Node* node_ptr);
size_t print_node_links(Tree* tree_struct, Node* node_ptr);
void create_graph_jpg(Tree* tree_ptr);

size_t graph_end(Tree* tree_struct);

#endif
