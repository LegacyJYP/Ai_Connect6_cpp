cmake_minimum_required(VERSION 3.7)
project(ai_connect6)

set(CMAKE_CXX_STANDARD 11)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -v -stdlib=libc++")


set(SOURCE_FILES main.cpp
        test/Samples.cpp
        consts/GAME_BOARD.h
        test/utils/PrintUtils.cpp test/utils/PrintUtils.h test/utils/BoardUtils.cpp test/utils/BoardUtils.h ai/heuristic/Evaluation.cpp ai/heuristic/Evaluation.h test/utils/LOG_BY_EACHFUNCTION.h test/utils/TimeUtils.cpp test/utils/TimeUtils.h test/utils/LogUtils.cpp test/utils/LogUtils.h test/utils/FunctionCostUtils.cpp test/utils/FunctionCostUtils.h ai/policy/EffectiveRange.cpp ai/policy/EffectiveRange.h ai/policy/NextStonePairs.cpp ai/policy/NextStonePairs.h)
add_executable(ai_connect6 ${SOURCE_FILES})