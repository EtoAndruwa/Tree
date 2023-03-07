#include "tree.h"

size_t graph_start(Tree* tree_struct)
{
    FILE* graph_txt = fopen(graph_txt_name, "a+");
    if(graph_txt == nullptr)
    {
        tree_struct->error_code = ERR_TO_OPEN_GRAPH_TXT;
        tree_dtor(tree_struct);
        return ERR_TO_OPEN_GRAPH_TXT;
    }

    fprintf(graph_txt, "\n");
    fprintf(graph_txt, "digraph\n");
    fprintf(graph_txt, "{\n");
    fprintf(graph_txt, "\trankdir=TB;\n");

    if(fclose(graph_txt) == EOF)
    {
        tree_struct->error_code = ERR_TO_CLOSE_GRAPH_TXT;
        tree_dtor(tree_struct);
        return ERR_TO_CLOSE_GRAPH_TXT;
    }
}

size_t graph_end(Tree* tree_struct)
{
    FILE* graph_txt = fopen(graph_txt_name, "a+");
    if(graph_txt == nullptr)
    {
        tree_struct->error_code = ERR_TO_OPEN_GRAPH_TXT;
        tree_dtor(tree_struct);
        return ERR_TO_OPEN_GRAPH_TXT;
    }

    fprintf(graph_txt, "}\n");

    if(fclose(graph_txt) == EOF)
    {
        tree_struct->error_code = ERR_TO_CLOSE_GRAPH_TXT;
        tree_dtor(tree_struct);
        return ERR_TO_CLOSE_GRAPH_TXT;
    }
}

size_t print_node_data(Tree* tree_struct, Node* node_ptr)
{
    FILE* graph_txt = fopen(graph_txt_name, "a+");
    if(graph_txt == nullptr)
    {
        tree_struct->error_code = ERR_TO_OPEN_GRAPH_TXT;
        tree_dtor(tree_struct);
        return ERR_TO_OPEN_GRAPH_TXT;
    }

    if(node_ptr != nullptr)
    {
        fprintf(graph_txt, "\tnode_%d[shape = record, label =\" value = %d \\n | { right_child = %p \\n} | { left_child = %p }\"];\n", node_ptr->node_value, node_ptr->node_value, node_ptr->right_child, node_ptr->left_child);
        if(node_ptr->left_child != nullptr)
        {
            print_node_data(tree_struct, node_ptr->left_child);
        }
        if(node_ptr->right_child != nullptr)
        {
            print_node_data(tree_struct, node_ptr->right_child);
        }
    }

    if(fclose(graph_txt) == EOF)
    {
        tree_struct->error_code = ERR_TO_CLOSE_GRAPH_TXT;
        tree_dtor(tree_struct);
        return ERR_TO_CLOSE_GRAPH_TXT;
    }
}

size_t print_node_links(Tree* tree_struct, Node* node_ptr)
{
    FILE* graph_txt = fopen(graph_txt_name, "a+");
    if(graph_txt == nullptr)
    {
        tree_struct->error_code = ERR_TO_OPEN_GRAPH_TXT;
        tree_dtor(tree_struct);
        return ERR_TO_OPEN_GRAPH_TXT;
    }

    if(node_ptr->left_child != nullptr)
    {
        fprintf(graph_txt, "\tnode_%d -> node_%d[color=\"blue\", label = \"left_child\"];\n", node_ptr->node_value, node_ptr->left_child->node_value);
        print_node_links(tree_struct, node_ptr->left_child);
    }
    if(node_ptr->right_child != nullptr)
    {
        fprintf(graph_txt, "\tnode_%d -> node_%d[color=\"red\", label = \"right_child\"];\n", node_ptr->node_value, node_ptr->right_child->node_value);
        print_node_links(tree_struct, node_ptr->right_child);
    }

    if(fclose(graph_txt) == EOF)
    {
        tree_struct->error_code = ERR_TO_CLOSE_GRAPH_TXT;
        tree_dtor(tree_struct);
        return ERR_TO_CLOSE_GRAPH_TXT;
    }
}

size_t create_graph_jpg(Tree* tree_ptr)
{
    graph_start(tree_ptr);
    print_node_data(tree_ptr, tree_ptr->root);
    print_node_links(tree_ptr, tree_ptr->root);
    graph_end(tree_ptr);

    system("dot ./graph.txt -Tjpg -o graph.jpg");
    system("explorer.exe graph.jpg");
}
