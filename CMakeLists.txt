cmake_minimum_required(VERSION 3.16)
project(hvml)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

option(UPDATE_SUBMODULES
       "if you don't wanna update submodules, set -DUPDATE_SUBMODULES=OFF"
       ON)

if(UPDATE_SUBMODULES)
    message(STATUS "update_submodules is set")
    add_custom_target(git-submodules ALL
        COMMAND git submodule update --init)
else()
    message(STATUS "update_submodules is NOT set")
endif()

add_subdirectory(third-party)
add_subdirectory(parser)
#add_subdirectory(interpreter)
add_subdirectory(json-eval)
add_subdirectory(json-objects)
add_subdirectory(test)
add_subdirectory(bindings)
