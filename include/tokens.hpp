#include <unordered_map>

namespace rcpy::lex {

  enum class tokens {
    RESERVED,         // "RESERVED"
    INT,              // "INT"
    FLOAT,            // "FLOAT"

    MINUS,            // "MINUS"
    PLUS,             // "PLUS"
    MULTIPLY,         // "MULTIPLY"
    DIVIDE,           // "DIVIDE"
    ASSIGN,           // "ASSIGN"

    EOL,              // "EOL"
    SPACE,            // "SPACE"

    PRINT,            // "PRINT"

    NAME,             // "NAME"

    IF,               // "IF"
    ELSE,             // "ELSE"
    WHILE,            // "WHILE"

    EQ,               // "EQ"
    GT,               // "GT"
    LT,               // "LT"

    POSSIBLE_IMPLICID,// "POSSIBLE_IMPLICID"
    FUNCTION_DEC,     // "FUNCTION_DEC"
    FUNCTION_CALL,    // "FUNCTION_CALL"
    PARAMETER_START,  // "PARAMETER_START"
    PARAMETER_END,    // "PARAMETER_END"
    SCOPE_START,      // "SCOPE_START"
    SCOPE_END,        // "SCOPE_END"
    RETURN,           // "RETURN"
    DIVIDER           // "DIVIDER"
  };

  std::unordered_map<std::string, tokens> standard_name_tokens = {
        {"howto", tokens::FUNCTION_DEC},
        {"if", tokens::IF},
        {"else", tokens::ELSE},
        {"while", tokens::WHILE},
        {"equal", tokens::EQ},
        {"return", tokens::RETURN},
        {"serve", tokens::RETURN}
  };

  std::unordered_map<char, tokens> standard_tokens {
    {' ', tokens::POSSIBLE_IMPLICID},
    {':', tokens::PARAMETER_START},
    {';', tokens::PARAMETER_END},
    {'(', tokens::SCOPE_START},
    {')', tokens::SCOPE_END},
    {',', tokens::DIVIDER},
    {'-', tokens::MINUS},
    {'+', tokens::PLUS},
    {'*', tokens::MULTIPLY},
    {'/', tokens::DIVIDE},
    {'<', tokens::GT},
    {'>', tokens::LT},
    {'=', tokens::ASSIGN},
    {'\n', tokens::EOL}
  };
}
