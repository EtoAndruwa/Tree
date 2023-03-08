#ifndef TREE_H
#define TREE_h

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @file tree.h
 * @author EtoAndruwa (https://github.com/EtoAndruwa)
 * @brief 
 * @version v1.0
 * @date 2023-03-07
 * 
 * @copyright Copyright (c) 2023
 */

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

static const char* graph_txt_name = "graph.txt";               /// \brief The name of the file containing structure of the graph
static const char* graph_after_txt_name  = "graph_after.txt";  /// \brief The name of the file containing structure of the graph
static const char* graph_before_txt_name = "graph_before.txt"; /// \brief The name of the file containing structure of the graph
typedef int Node_data;                                         /// \brief The type of the node's value
const Node_data POISON = 0xDED;                                /// \brief The Poison value which is used in order to delete node's values  

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief 
 * 
 */
enum error_codes
{
    TREE_OK                = 0,
    ERR_TO_OPEN_GRAPH_TXT  = 1,
    ERR_TO_CLOSE_GRAPH_TXT = 2,
    ERR_TO_CALLOC_ROOT     = 3,
    ERR_TO_CALLOC_NODE     = 4,
};

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief The struct of the node 
 * 
 */
typedef struct Node
{
    Node_data node_value = 0;
    Node* parent_node = nullptr;
    Node* left_child = nullptr;
    Node* right_child = nullptr;
}Node;

/**
 * @brief This struct contains error code of the tree and the pointer to the tree's node
 * 
 */
typedef struct Tree
{
    Node* root = nullptr;
    size_t error_code = TREE_OK;
}Tree;

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Creates and initializes the tree struct
 * 
 * @param tree_ptr The pointer to the tree struct
 * @param root_value The value of the root node
 * @return size_t Returns the error code of the function
 */
size_t tree_ctor(Tree* tree_ptr, Node_data root_value);

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Deletes the tree struct and calls the dtor_childs function to delete all child nodes recursively
 * 
 * @param tree_ptr The pointer to the tree struct
 */
void tree_dtor(Tree* tree_ptr);

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Deletes all children nodes of the tree
 * 
 * @param node_ptr The pointer to the root node
 */
void dtor_childs(Node* node_ptr);

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Sets child_ptr as left child of the parent_ptr
 * 
 * @param parent_ptr The pointer to the parent node
 * @param child_ptr  The pointer to the child node
 */
void link_node_left(Node* parent_ptr, Node* child_ptr);

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Sets child_ptr as right child of the parent_ptr
 * 
 * @param parent_ptr The pointer to the parent node
 * @param child_ptr  The pointer to the child node
 */
void link_node_right(Node* parent_ptr, Node* child_ptr);

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Creates the new node with given value 
 * 
 * @param tree_ptr The pointer to the tree struct
 * @param node_value The value of the node 
 * @return Node* The pointer to the created node
 */
Node* create_node(Tree* tree_ptr, Node_data node_value);

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Convert the enum code to the string equivalent 
 * 
 * @param error_code The enum code of the error
 * @return const char* The string equivalent of the error code 
 */
const char* enum_error_string(size_t error_code);

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Prints the start of the graph into the description file
 * 
 * @param tree_ptr The pointer to the tree struct
 * @param file_name 
 * @return size_t Returns the error code of the funciton
 */
size_t graph_start(Tree* tree_ptr, const char* file_name);

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Prints all data about the given node into the description file 
 * 
 * @param tree_ptr The pointer to the tree struct
 * @param node_ptr The pointer to the node that must be described
 * @param file_name 
 * @return size_t Returns the error code of the funciton
 */
size_t print_node_data(Tree* tree_ptr, Node* node_ptr, const char* file_name);

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Prints the links of current node with its children
 * 
 * @param tree_ptr The pointer to the tree struct
 * @param node_ptr The pointer to the node that must be described
 * @param file_name 
 * @return size_t Returns the error code of the funciton
 */
size_t print_node_links(Tree* tree_ptr, Node* node_ptr, const char* file_name);

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Calls all functions that create the structure of the graph in the description file
 * 
 * @param tree_ptr The pointer to the tree struct
 * @param file_name 
 * @return size_t Returns the error code of the funciton
 */
size_t create_graph_jpg(Tree* tree_ptr, const char* file_name);

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Closes the struct of the graph in the file
 * 
 * @param tree_ptr The pointer to the tree struct
 * @param file_name 
 * @return size_t Returns the error code of the funciton
 */
size_t graph_end(Tree* tree_ptr, const char* file_name);

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/**
 * @brief Recursively checks all nodes in order to add new nodes as in binary search tree 
 * 
 * @param tree_ptr The pointer to the tree struct
 * @param node_ptr The pointer to the node to which new node must be added
 * @param node_value The value of the new node
 * @return size_t Returns the error code of the tree struct 
 */
size_t add_node_to_tree(Tree* tree_ptr, Node* node_ptr, Node_data node_value);

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief 
 * 
 * @param node_ptr 
 * @param search_value 
 * @return Node* 
 */
Node* search_node(Node* node_ptr, Node_data search_value);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief 
 * 
 */
void delete_node(Node* node_ptr, Node_data search_value);

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void print_sorted_array(Node* node_ptr);

void print_leaves(Node* node_ptr);

size_t get_depth_tree(Node* node_ptr);

void is_balanced(Node* node_ptr);

Node* delete_node(Node* deleted_node, Node* replacing_node);

void search_and_delete_node(Node* root_node, Node_data node_value);

Node* search_left(Node* node_ptr);


#endif
