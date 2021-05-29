//basic define-once check

#ifndef LEXER_H
#define LEXER_H
#include "token.h"

//create a "class" of a lexer
typedef struct LEXER_STRUCT
{
    char c;
    unsigned int i;
    char* contents;
} lexer_T;
//methods

//Returns a lexer (initiate)
lexer_T* init_lexer(char* contents);

//Move c pointer to next character if possible
void lexer_advance(lexer_T* lexer);

//Ignore certain parts/characters
void lexer_skip_whitespace(lexer_T* lexer);

//get to the next recognized token;
token_T* lexer_get_next_token(lexer_T* lexer);

//parse?
token_T lexer_collect_string(lexer_T* lexer);

//return char c -> char c [] / char* c;
char* lexer_get_current_char_as_string(lexer_T* lexer);
#endif