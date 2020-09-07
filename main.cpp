#include <iostream>
#include <fstream>
#include "include/lexer.hpp"


int main(int arg, char** argc){
  std::ifstream file(argc[1]);
  std::string file_str = std::string(
      (std::istreambuf_iterator<char>(file)), 
      std::istreambuf_iterator<char>());
  //std::cout << file_str << std::endl;
  rcpy::lex::rcpy_lexer(file_str.begin(), file_str.end());

  return 0;
}
