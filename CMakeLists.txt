cmake_minimum_required(VERSION 3.5)
project(logsim)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wno-unused-parameter -Wall -Wextra -Wpedantic)
endif()

add_library(UsecaseDryRun SHARED src/dry_run.cpp)
add_executable(evaluation src/evaluation.cpp)
target_link_libraries(evaluation ${CMAKE_DL_LIBS})

