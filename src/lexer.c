#include "include/lexer.h"
#include <stdlib.h>
#include <string.h>

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

    return lexer;
};

//Move c pointer to next character if possible
void lexer_advance(lexer_T* lexer){
    //check if its not null and if we can advance to next character:
    if (lexer->c!='\0' && lexer->i<strlen(lexer->contents)){
        lexer->i+=1;
        lexer->c=lexer->contents[lexer->i];
    }
}

//Ignore certain parts/characters
void lexer_skip_whitespace(lexer_T* lexer){
    //include 10 -> since 10 = newline code
    while(lexer->c==' '||lexer->c==10){
        //advance character while its a blank character
        lexer_advance(lexer);
    }
}

//get to the next recognized token;
token_T* lexer_get_next_token(lexer_T* lexer){
    while (lexer->c!='\0'&&lexer->i < strlen(lexer->contents)){
        //if we encounter a white space, skip all of it...
        if(lexer->c==' '||lexer->c==10){
            lexer_skip_whitespace(lexer);
        }
        //Specific, more detailed check, for string:
        if(lexer->c=='"'){
            token_T* _token = lexer_collect_string(lexer);
            return _token;
        }

        switch(lexer->c){
            //if it is a known token, advance lexer_T* lexer  and return that token with type of that token and lexer char as string, since a token is initiated with a char*
            // used for basic tokens
            case '=': return(lexer_advance_with_token(lexer, init_token(TOKEN_EQUALS, lexer_get_current_char_as_string(lexer)))); break;
            case ';': return(lexer_advance_with_token(lexer, init_token(TOKEN_SEMI, lexer_get_current_char_as_string(lexer)))); break;
            case '(': return(lexer_advance_with_token(lexer, init_token(TOKEN_LPAREN, lexer_get_current_char_as_string(lexer)))); break;
            case ')': return(lexer_advance_with_token(lexer, init_token(TOKEN_RPAREN, lexer_get_current_char_as_string(lexer)))); break;
        }

    }
}

//parse?
token_T* lexer_collect_string(lexer_T* lexer){
    //Skip the quote
    lexer_advance(lexer);

    char* value = calloc(1, sizeof(char));
    //declare as array
    value[0] = "\0";
    while(lexer->c!='"'){
        //return the current char as str
        char* s = lexer_get_current_char_as_string(lexer);
        //reallocate value to be of length s+1 (1 to make space for the end NULL char)*sizeof(type)
        value = realloc(value, strlen(s+1)*sizeof(char));
        //strcat(value, s); -> append s to value
        strcat(value, s);
    }

    //since the loop has ended, skip the last quote
    lexer_advance(lexer);
    token_T* final_string = calloc(1, sizeof(struct TOKEN_STRUCT));
    final_string->type=TOKEN_STRING;
    final_string->value = value;
}

token_T* lexer_advance_with_token(lexer_T* lexer, token_T* token){
    lexer_advance(lexer);
    return token;
}

//return char c -> char c [] / char* c;
char* lexer_get_current_char_as_string(lexer_T* lexer){
}