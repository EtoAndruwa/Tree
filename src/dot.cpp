#include "tree.h"

size_t graph_start(Tree* tree_struct)
{
    FILE* graph_txt = fopen(graph_txt_name, "a+");
    if(graph_txt == nullptr)
    {
        tree_struct->error_code = ERR_TO_OPEN_GRAPH_TXT;
        // tree_dump(tree_struct);
        // tree_dtor(tree_struct);
        return ERR_TO_OPEN_GRAPH_TXT;
    }

    fprintf(graph_txt, "\n");
    fprintf(graph_txt, "digraph\n");
    fprintf(graph_txt, "{\n");
    fprintf(graph_txt, "\trankdir=TB;\n");

    if(fclose(graph_txt) == EOF)
    {
        tree_struct->error_code = ERR_TO_CLOSE_GRAPH_TXT;
        // tree_dump(tree_struct);
        // tree_dtor(tree_struct);
        return ERR_TO_CLOSE_GRAPH_TXT;
    }
}

size_t graph_end(Tree* tree_struct)
{
    FILE* graph_txt = fopen(graph_txt_name, "a+");
    if(graph_txt == nullptr)
    {
        tree_struct->error_code = ERR_TO_OPEN_GRAPH_TXT;
        // tree_dump(tree_struct);
        // tree_dtor(tree_struct);
        return ERR_TO_OPEN_GRAPH_TXT;
    }

    fprintf(graph_txt, "\n");
    fprintf(graph_txt, "}\n\n");

    if(fclose(graph_txt) == EOF)
    {
        tree_struct->error_code = ERR_TO_CLOSE_GRAPH_TXT;
        // tree_dump(tree_struct);
        // tree_dtor(tree_struct);
        return ERR_TO_CLOSE_GRAPH_TXT;
    }
}

size_t print_node_data(Tree* tree_struct, Node* node_ptr)
{
    FILE* graph_txt = fopen(graph_txt_name, "a+");
    if(graph_txt == nullptr)
    {
        tree_struct->error_code = ERR_TO_OPEN_GRAPH_TXT;
        // tree_dump(tree_struct);
        // tree_dtor(tree_struct);
        return ERR_TO_OPEN_GRAPH_TXT;
    }

    fprintf(graph_txt, "\tnode_%d[shape = Mrecord, label =\" value = %d \\n right_child = %p \\n left_child = %p\"];\n", node_ptr->node_value, node_ptr->node_value, node_ptr->right_child, node_ptr->left_child);

    if(fclose(graph_txt) == EOF)
    {
        tree_struct->error_code = ERR_TO_CLOSE_GRAPH_TXT;
        // tree_dump(tree_struct);
        // tree_dtor(tree_struct);
        return ERR_TO_CLOSE_GRAPH_TXT;
    }
}

size_t print_node_links(Tree* tree_struct, Node* node_ptr)
{
    FILE* graph_txt = fopen(graph_txt_name, "a+");
    if(graph_txt == nullptr)
    {
        tree_struct->error_code = ERR_TO_OPEN_GRAPH_TXT;
        // tree_dump(tree_struct);
        // tree_dtor(tree_struct);
        return ERR_TO_OPEN_GRAPH_TXT;
    }

    if(node_ptr->left_child != nullptr)
    {
        fprintf(graph_txt, "\tnode_%d -> node_%d;\n", node_ptr->node_value, node_ptr->left_child->node_value);
    }
    if(node_ptr->right_child != nullptr)
    {
        fprintf(graph_txt, "\tnode_%d -> node_%d;\n", node_ptr->node_value, node_ptr->right_child->node_value);
    }

    if(fclose(graph_txt) == EOF)
    {
        tree_struct->error_code = ERR_TO_CLOSE_GRAPH_TXT;
        // tree_dump(tree_struct);
        // tree_dtor(tree_struct);
        return ERR_TO_CLOSE_GRAPH_TXT;
    }
}

void create_graph_jpg()
{
    system("dot ./graph.txt -Tjpg -o graph.jpg");
}
