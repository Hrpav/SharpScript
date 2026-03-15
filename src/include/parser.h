/*
    Copyright (c) 2024-2026 SharpScript Programming Language
    
    Licensed under the MIT License
*/

// START OF parser.h

#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "ast.h"

typedef struct
{
    Lexer *lexer;
    Token *current_token;
    char **include_paths;
    int include_count;
    int include_capacity;
} Parser;

Parser *parser_create(Lexer *lexer);
void parser_free(Parser *parser);
ASTNode *parser_parse(Parser *parser);

#endif // PARSER_H

// END OF parser.h