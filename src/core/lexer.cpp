#include "lexer.h"
#include "token.h"
#include <string>

namespace cam::core::lexer {

int getTok() {
    static char lastChar = ' ';

    while(isspace(lastChar)) {
        lastChar = getchar();
    }

    if(isalpha(lastChar)) {
        identifierStr += lastChar;
        while(isalnum(lastChar=getchar())) {
            identifierStr += lastChar;
        }

        if(identifierStr == "fn") {
            return tok_fn;
        }   
        if(identifierStr == "extern") {
            return tok_extern;
        }

        return tok_identifier;
    }

    if(isdigit(lastChar) || lastChar == '.') {
        std::string num;
        do {
            num += lastChar;
            lastChar = getchar();
        } while(isdigit(lastChar) || lastChar == '.');

        numVal = strtod(num.c_str(), 0);
        return tok_number;
    }

    if(lastChar == '#') {
        do {
            lastChar = getchar();
        } while(lastChar != EOF && lastChar != '\n' && lastChar != '\r');

        if(lastChar != EOF) {
            return getTok();
        }
    }

    if(lastChar == EOF) {
        return tok_eof;
    }

    char thisChar = lastChar;
    lastChar = getchar();
    return thisChar;
}

}