#include "scanner.h"
#include <stdlib.h>

struct Scanner* new_scanner(char *source) {

    struct Scanner *scanner = (struct Scanner*) malloc(2 * sizeof(struct Scanner));
    return scanner;
}

struct Token* scan_tokens() {


}