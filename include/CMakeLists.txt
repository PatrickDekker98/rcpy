set(CMAKE_CXX_STANDARD 17)

add_library(rcpy_lib tokens.hpp lexer.hpp)

SET_TARGET_PROPERTIES(rcpy_lib PROPERTIES LINKER_LANGUAGE CXX)

