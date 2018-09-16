cmake_minimum_required(VERSION 3.12)

project(coin_change)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Werror")
#set(CMAKE_CXX_COMPILER "gcc")

add_definitions(-std=c++14 -Wall -Werror -v)
add_executable(
	coin_change
	main.cpp
)
