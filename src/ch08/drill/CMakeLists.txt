cmake_minimum_required(VERSION 3.0.0)
project(ch08_drill VERSION 0.1.0)

# include(CTest)
# enable_testing()
# add_executable(ch08_drill_01 main.cpp)
# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)

file(GLOB PROJECT_SOURCE_FILES CONFIGURE_DEPENDS src/*.cpp)
include_directories(/include)
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_FILES})

