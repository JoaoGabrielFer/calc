cmake_minimum_required(VERSION 3.15)

project(Calc++ LANGUAGES CXX)

set(SOURCES
    src/main.cpp
    src/lexer.cpp
)

add_executable(Calc++ ${SOURCES})

target_include_directories(Calc++ PUBLIC
    src/include
)

target_compile_features(Calc++ PUBLIC cxx_std_17)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(Calc++ PRIVATE
        -finput-charset=UTF-8
        -fexec-charset=UTF-8
    )

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(Calc++ PRIVATE /utf-8)
endif()
