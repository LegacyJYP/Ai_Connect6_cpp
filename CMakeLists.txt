cmake_minimum_required(VERSION 3.7)
project(ai_connect6)

set(CMAKE_CXX_STANDARD 11)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -v -stdlib=libc++")


set(SOURCE_FILES main.cpp
        test/Samples.cpp
        consts/GAME_BOARD.h
        test/utils/PrintUtils.cpp test/utils/PrintUtils.h ai/utils/BoardUtils.cpp ai/utils/BoardUtils.h ai/heuristic/JYP/Evaluation_JYP.cpp ai/heuristic/JYP/Evaluation_JYP.h test/utils/LOG_BY_EACHFUNCTION.h test/utils/TimeUtils.cpp test/utils/TimeUtils.h test/utils/LogUtils.cpp test/utils/LogUtils.h test/utils/FunctionCostUtils.cpp test/utils/FunctionCostUtils.h ai/policy/EffectiveRange.cpp ai/policy/EffectiveRange.h ai/policy/NextStonePairs.cpp ai/policy/NextStonePairs.h ai/policy/FilteredByHeuristic.cpp ai/policy/FilteredByHeuristic.h ai/policy/Sort.cpp ai/policy/Sort.h consts/SCORE.h consts/CONFIG.h ai/utils/VectorUtils.cpp ai/utils/VectorUtils.h ai/utils/StoneUtils.cpp ai/utils/StoneUtils.h ai/search/domain/Node.cpp ai/search/domain/Node.h ai/heuristic/onefile/Evaluation_ONEFILE.cpp ai/heuristic/onefile/Evaluation_ONEFILE.h ai/search/Minimax.cpp ai/search/Minimax.h ai/search/IterativeDeepening.cpp ai/search/IterativeDeepening.h test/MinimaxTest.cpp test/MinimaxTest.h ai/heuristic/Evaluation.cpp ai/heuristic/Evaluation.h ai/search/NodeExtend.cpp ai/search/NodeExtend.h GivenMain.cpp)
add_executable(ai_connect6 ${SOURCE_FILES})