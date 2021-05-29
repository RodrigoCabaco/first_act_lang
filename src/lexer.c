#include "include/lexer.h"

lexer_T* init_lexer(char* contents){
    //alocate size for the lexer
    lexer_T* lexer = calloc(1, sizeof(struct LEXER_STRUCT));
    // type* name = calloc(times, sizeof(struct TYPE_STRUCT));
    //define elements
    lexer->contents = contents;
    //0, since currenct character = 0;
    lexer->i = 0;
    //define the currenct character to be the character at index of current
    lexer->c = contents[lexer->i];
};

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