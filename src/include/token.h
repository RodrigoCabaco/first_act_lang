//basic define-once def
#ifndef TOKEN_H
#define TOKEN_H
typedef struct TOKEN_STRUCT
{
    enum{
        TOKEN_ID, // var "name" -> id = "something";
        TOKEN_EQUALS,// var name "=" -> equal "something";
        TOKEN_STRING, // "
        TOKEN_SEMI, // ;
        TOKEN_LPAREN, // (
        TOKEN_RPAREN // )
    } type;
    char* value;
} token_T;
// init token;
token_T* init_token(int type, char* value);
#endif