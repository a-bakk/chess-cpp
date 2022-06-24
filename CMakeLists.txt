cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")

project(chess VERSION 1.0)

add_library(board STATIC board/board.cpp)
target_include_directories(board PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/board/include)

add_library(usr-int STATIC user-interaction/user-interaction.cpp)
target_include_directories(usr-int PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/user-interaction/include)

add_executable(chess ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(chess PUBLIC board)
target_link_libraries(chess PUBLIC usr-int)
