#ifndef SCANNER_H
#define SCANNER_H

struct Scanner {
    char *source;
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

  EOF
};

struct Token {
    char *value;
};

struct Token* scan_tokens();
struct Scanner* new_scanner();

#endif