cmake_minimum_required(VERSION 3.17)
project(DAC)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(FILESYSTEM stdc++fs)

include_directories(src)
################   Project files  ################
file(GLOB_RECURSE CPP_SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS  "src/*.h")

add_executable(DAC ${HEADERS} ${CPP_SOURCES})
target_link_libraries(DAC ${FILESYSTEM})
