cmake_minimum_required(VERSION 3.7)
project(ai_connect6)

set(CMAKE_CXX_STANDARD 11)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -v -stdlib=libc++")


set(SOURCE_FILES main.cpp
        test/Samples.cpp
        consts/GAME_BOARD.h
        test/utils/PrintUtils.cpp test/utils/PrintUtils.h test/utils/BoardUtils.cpp test/utils/BoardUtils.h)
add_executable(ai_connect6 ${SOURCE_FILES})