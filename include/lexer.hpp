#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <functional>
#include <ctype.h>
#include "tokens.hpp"

namespace rcpy::lex{

  // checker funcs start
  
  bool is_standard_token(std::string::iterator it) {
    std::unordered_map<char, tokens>::iterator ti = standard_tokens.find(char(*it)); 
    if (ti != standard_tokens.end()) {
      return true;
    }
    return false;
  }

  bool is_name(std::string::iterator it) {
    return isalpha(*it);
  }

  // checker funcs done
  // parsers funcs start
  
  std::pair<tokens, std::string> get_standard_token(std::string::iterator it) {
    std::string s = "";
    s = s + *it;
    return std::make_pair(standard_tokens[char(*it)], s);
  }

  struct generic_parser {
    std::string str;

    void reset() {
      str.clear();
    }
  };

  struct parse_name : public generic_parser {
    std::pair<tokens, std::string> operator()(std::string::iterator it) {
      if (isalpha(*it)) {
        str += *it;
        ++it;
        return this->operator()(it);
      } else {
        return str;
      }
    } 
  } get_name ;


  // parsers funcs done
  


  std::vector<std::pair<
    std::function<bool(std::string::iterator)>, 
    std::function<std::pair<tokens, std::string>(std::string::iterator)>
    >> if_vec = {
      {is_standard_token, get_standard_token}
    };

  struct if_function {
  
    void operator()(std::string::iterator it){
    
    }
  } if_func;

  struct lexer {
    void operator()(std::string::iterator it, std::string::iterator end) {
      if (it == end) {
        return;
      } 
      std::cout << *it;
      ++it;
      return this->operator()(it, end);
    
    }
  } rcpy_lexer;
}
