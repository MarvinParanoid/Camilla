#ifndef __TOKEN_H_
#define __TOKEN_H_

#include <string>

namespace cam::core::lexer {

enum Token {
    // end of file
    tok_eof = -1,

    // commands
    tok_fn = -2, 
    tok_extern = -3,

    // priamry
    tok_identifier = -4, 
    tok_number = -5,
};

// TODO remove global variables
static std::string identifierStr;
static double numVal;

}

#endif