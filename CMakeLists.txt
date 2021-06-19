cmake_minimum_required(VERSION 3.17)
project(hzhz)

set(CMAKE_CXX_STANDARD 14)

add_executable(hzhz main.cpp DynamicArray.h LinkedList.h Sequence.h ArraySequence.cpp ArraySequence.h LinkedListSequence.h "Tests_DA_and_LL.cpp" "Tests_DA_and_LL.h" "Tests_AS_and_LLS.cpp" "Tests_AS_and_LLS.h" Vector.h MenuVector.h MenuVector.cpp)