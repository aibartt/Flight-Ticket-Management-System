cmake_minimum_required(VERSION 3.21)
project(HashTable)

set(CMAKE_CXX_STANDARD 17)

add_executable(HashTable main.cpp flighthashtable.cpp flighthashtable.h flightticket.cpp flightticket.h MyList.cpp MyList.h)
