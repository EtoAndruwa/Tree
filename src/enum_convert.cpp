#include "tree.h"

const char* enum_error_string(size_t error_code)  
{
    switch(error_code)
    {
        #define DEF_ERROR_STRING(error_code)      \
            case error_code:                      \
                return #error_code;               \

        DEF_ERROR_STRING(TREE_OK)
        DEF_ERROR_STRING(ERR_TO_OPEN_GRAPH_TXT)
        DEF_ERROR_STRING(ERR_TO_CLOSE_GRAPH_TXT)
        DEF_ERROR_STRING(ERR_TO_CALLOC_ROOT)
        
        #undef DEF_ERROR_STRING
        default:
            return "NEW_ERROR_CODE";
    }
}

