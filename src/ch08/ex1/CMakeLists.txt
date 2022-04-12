cmake_minimum_required(VERSION 3.0.0)
project(ch08_ex1 VERSION 0.1.0)

include_directories(/include)
# file(GLOB PROJECT_SOURCE_FILES CONFIGURE_DEPENDS src/*.cpp)
file(GLOB PROJECT_SOURCE_FILES src/*.cpp)
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_FILES})
