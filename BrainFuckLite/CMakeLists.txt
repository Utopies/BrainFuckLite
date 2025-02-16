cmake_minimum_required(VERSION 3.27)
project(BrainFuckLite)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)
include_directories(Lexer)
include_directories(Parser)

add_executable(BrainFuckLite
        Lexer/Lexer.cpp
        Lexer/Lexer.h
        Lexer/TokenSt.h
        Lexer/TokenType.h
        Parser/Parser.cpp
        Parser/Parser.h
        BrainFuckLite.cpp
        BrainFuckLite.h)
