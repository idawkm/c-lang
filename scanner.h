#ifndef SCANNER_H
#define SCANNER_H

struct Scanner {
    char *source;
    int tokens_size;
    struct Token *tokens;
    int start;
    int line;
    int current;
};

enum TokenType {

  LEFT_PARENTHESIS, 
  RIGHT_PARENTHESIS, 
  LEFT_BRACE, 
  RIGHT_BRACE,
  COMMA, 
  DOT, 
  MINUS, 
  PLUS, 
  SEMICOLON, 
  SLASH, 
  STAR,

  BANG, 
  BANG_EQUAL,
  EQUAL, 
  EQUAL_EQUAL,
  GREATER, 
  GREATER_EQUAL,
  LESS, 
  LESS_EQUAL,

  IDENTIFIER, 
  STRING, 
  NUMBER,

  AND, 
  CLASS, 
  ELSE, 
  FALSE, 
  FUN, 
  FOR, 
  IF, 
  NIL, 
  OR,
  PRINT, 
  RETURN, 
  SUPER, 
  THIS, 
  TRUE, 
  VAR, 
  WHILE,
  ENDOF
};

struct Token {
    enum TokenType tokenType;
    char lexeme;
    char* literal;
    int line;
};

struct Token* scan_tokens();
void scan_token();
int is_at_end();
char advance();
void add_token(enum TokenType tokenType);
struct Scanner* start_scanner(char *source);
void append_token(enum TokenType tokenType, char *literal);
char* substring(char *source, int start, int end);

#endif