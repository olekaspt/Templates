project(Lab01)
cmake_minimum_required(VERSION 3.10)
 
# Locate GTest
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_compile_options(-std=c++17)  

add_library (applibrary SHARED NodeNonTemplate.cpp LinkedListNonTemplate.cpp )
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTestsOld testsOld.cpp)
target_link_libraries(runTestsOld ${GTEST_LIBRARIES} pthread applibrary ) 

add_executable(runMainOld mainOld.cpp)
target_link_libraries(runMainOld applibrary)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread ) 

add_executable(runMain main.cpp)
target_link_libraries(runMain )
