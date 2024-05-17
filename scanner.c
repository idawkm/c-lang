#include "scanner.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Scanner *scanner;

struct Scanner* start_scanner(char *source) {
    scanner = (struct Scanner *) malloc(2 * sizeof(struct Scanner));
    scanner->start = 0;
    scanner->current = 0;
    scanner->tokens_size = 0;
    scanner->line = 1;
    scanner->source = source;
    scanner->tokens = (struct Token*) malloc(10 * sizeof(struct Token));

    return scanner;
}

struct Token* scan_tokens() {

    while (!is_at_end()) {
        scanner->start = scanner->current;
        scan_token();
    }

    struct Token token;
    token.tokenType = ENDOF;
    token.line = scanner->line;
    token.lexeme = '\0';

    scanner->tokens[scanner->tokens_size++] = token;

    return scanner->tokens;
}

void scan_token() {

    char c = advance();

    switch(c) {

        case '(':
            add_token(LEFT_PARENTHESIS);
            break;
        case ')':
            add_token(RIGHT_PARENTHESIS);
            break;
        case '{':
            add_token(LEFT_BRACE);
            break;
        case '}':
            add_token(RIGHT_BRACE);
            break;
        case ',':
            add_token(COMMA);
            break;
        case '.':
            add_token(DOT);
            break;
        case '-':
            add_token(MINUS);
            break;
        case '+':
            add_token(PLUS);
            break;
        case ';':
            add_token(SEMICOLON);
            break;
        case '*':
            add_token(STAR);
            break;
    }
}

void add_token(enum TokenType tokenType) {

    append_token(tokenType, NULL);
}

void append_token(enum TokenType tokenType, char *literal) {
    
    char text = scanner->source[scanner->current];
    struct Token token;
    token.tokenType = tokenType;
    token.line = scanner->line;
    token.lexeme = text;
    scanner->tokens[scanner->tokens_size++] = token;
}

char* substring(char *source, int start, int end) {

    int size = end - start;
    char *substr = (char *) malloc(size * sizeof(char));

    for (int i=start; i < end; i++) {
        substr[i] = source[i];
    }

    return substr;
}

int is_at_end() {

    return scanner->current >= strlen(scanner->source);   
}

char advance() {

    return scanner->source[scanner->current++];
}