cmake_minimum_required(VERSION 3.18) # Must be the first line

project(GuessTheNumber) 

set(CMAKE_CXX_STANDARD 20) # Before Executable and Target 
# Specify the version of C++ to use.

add_executable(${PROJECT_NAME}) # 

target_sources(${PROJECT_NAME} PRIVATE
  src/main.cpp
)