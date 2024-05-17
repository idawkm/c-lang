#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"

void run_file(char *argc);
void run_prompt();
void run(char *buffer);

int main(int argc, char *argv[]) {
    
    if (argc > 2) {
        printf("usage: cinterpreter");
        exit(64);
    }

    if (argc == 2) {
        run_file(argv[1]);
        return 0;
    }

    run_prompt();

    return 0;
}

void run_file(char *path) {

    FILE *file_ptr = fopen(path, "r+");

    if (file_ptr == NULL) {
        printf("could not open the file\n");
        exit(1);
    }

    fseek(file_ptr, 0, SEEK_END);
    long file_size = ftell(file_ptr);
    rewind(file_ptr);

    char *buffer = (char *) malloc(file_size * sizeof(char));
    fread(buffer, file_size, 1, file_ptr);

    run(buffer);
    free(buffer);
    fclose(file_ptr);
}

void run_prompt() {

    while(1) {

        printf("> ");
        int size = 25;
        char *line = (char *) malloc(size * sizeof(char));
        fgets(line, size, stdin);

        if (line == NULL) {
            break;
        }

        run(line);
        free(line);
    }
    printf("running the prompt\n");
}

void run(char *buffer) {

    struct Scanner *scanner = start_scanner(buffer);
    struct Token *tokens = scan_tokens();
    
    printf("token size: %d\n", scanner->tokens_size);

    for (int i = 0; i < scanner->tokens_size; i++) {
        struct Token token = tokens[i];
        printf("%d = %c\n", (int) token.tokenType, token.lexeme);
        
    }

    free(scanner->tokens);
    free(scanner);
}