#include <stdio.h>
#include "include/lexer.h"
int main(int arc, char* argv[])
{
    lexer_T* lexer = init_lexer(
       "var name = \"Rodrigo\";\n"
        "print(name);");

    token_T* token = (void*)0;
    while((token=lexer_get_next_token(lexer))!=(void*)0) 
    {
        printf("TOKEN(%d,%s)\n", token->type, token->value);
    }
    return 0;
}