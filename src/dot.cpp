#include "tree.h"

size_t graph_start(Tree* tree_struct, const char* file_name)
{
    FILE* graph_txt = fopen(file_name, "a+");
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

size_t graph_end(Tree* tree_struct, const char* file_name)
{
    FILE* graph_txt = fopen(file_name, "a+");
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

size_t print_node_data(Tree* tree_struct, Node* node_ptr, const char* file_name)
{
    FILE* graph_txt = fopen(file_name, "a+");
    if(graph_txt == nullptr)
    {
        tree_struct->error_code = ERR_TO_OPEN_GRAPH_TXT;
        tree_dtor(tree_struct);
        return ERR_TO_OPEN_GRAPH_TXT;
    }

    if(node_ptr != nullptr)
    {
        if(node_ptr->parent_node == nullptr)
        {
            fprintf(graph_txt, "\tnode_%d[shape = record, label =\" value = %d \\n | { right_child = %p \\n} | { left_child = %p } | { parent = %p }\", style=\"filled\", fillcolor=\"lightgrey\"];\n", node_ptr->node_value, node_ptr->node_value, node_ptr->right_child, node_ptr->left_child, node_ptr->parent_node);
        }
        else
        {
            fprintf(graph_txt, "\tnode_%d[shape = record, label =\" value = %d \\n | { right_child = %p \\n} | { left_child = %p } | { parent = %p }\"];\n", node_ptr->node_value, node_ptr->node_value, node_ptr->right_child, node_ptr->left_child, node_ptr->parent_node);
        }
        if(node_ptr->left_child != nullptr)
        {
            print_node_data(tree_struct, node_ptr->left_child, file_name);
        }
        if(node_ptr->right_child != nullptr)
        {
            print_node_data(tree_struct, node_ptr->right_child, file_name);
        }
    }

    if(fclose(graph_txt) == EOF)
    {
        tree_struct->error_code = ERR_TO_CLOSE_GRAPH_TXT;
        tree_dtor(tree_struct);
        return ERR_TO_CLOSE_GRAPH_TXT;
    }
}

size_t print_node_links(Tree* tree_struct, Node* node_ptr, const char* file_name)
{
    FILE* graph_txt = fopen(file_name, "a+");
    if(graph_txt == nullptr)
    {
        tree_struct->error_code = ERR_TO_OPEN_GRAPH_TXT;
        tree_dtor(tree_struct);
        return ERR_TO_OPEN_GRAPH_TXT;
    }

    if(node_ptr->left_child != nullptr)
    {
        fprintf(graph_txt, "\tnode_%d -> node_%d[color=\"blue\", label = \"left_child\"];\n", node_ptr->node_value, node_ptr->left_child->node_value);
        print_node_links(tree_struct, node_ptr->left_child, file_name);
    }
    if(node_ptr->right_child != nullptr)
    {
        fprintf(graph_txt, "\tnode_%d -> node_%d[color=\"red\", label = \"right_child\"];\n", node_ptr->node_value, node_ptr->right_child->node_value);
        print_node_links(tree_struct, node_ptr->right_child, file_name);
    }
    // if(node_ptr->parent_node != nullptr)
    // {
    //     fprintf(graph_txt, "\tnode_%d -> node_%d[color=\"green\", label = \"parent\"];\n", node_ptr->node_value, node_ptr->parent_node->node_value);
    // }

    if(fclose(graph_txt) == EOF)
    {
        tree_struct->error_code = ERR_TO_CLOSE_GRAPH_TXT;
        tree_dtor(tree_struct);
        return ERR_TO_CLOSE_GRAPH_TXT;
    }
}

size_t create_graph_jpg(Tree* tree_ptr, const char* file_name)
{
    graph_start(tree_ptr, file_name);
    print_node_data(tree_ptr, tree_ptr->root, file_name);
    print_node_links(tree_ptr, tree_ptr->root, file_name);
    graph_end(tree_ptr, file_name);

    if(strcmp(file_name, graph_before_txt_name) == 0)
    {
        system("dot ./graph_before.txt -Tjpg -o graph_before.jpg");
        system("explorer.exe graph_before.jpg");
    }
    else if(strcmp(file_name, graph_after_txt_name) == 0)
    {
        system("dot ./graph_after.txt -Tjpg -o graph_after.jpg");
        system("explorer.exe graph_after.jpg");
    }
    else
    {
        system("dot ./graph.txt -Tjpg -o graph.jpg");
        system("explorer.exe graph.jpg");
    }
}

