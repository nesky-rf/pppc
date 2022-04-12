cmake_minimum_required(VERSION 3.0.0)
project(ch12_drill VERSION 0.1.0 LANGUAGES CXX)


include_directories(/include)
file(GLOB PROJECT_SOURCE_FILES src/*.cpp)
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_FILES})

set(FLTK_DIR "/usr/lib/fltk")
find_package(FLTK REQUIRED NO_MODULE)
include_directories(${FLTK_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} fltk fltk_images)

message(STATUS "----------------------------:")
message(STATUS "PROJECT_NAME: ${PROJECT_NAME}")
message(STATUS "PROJECT_SOURCE_FILES:\n\t${PROJECT_SOURCE_FILES}")
message(STATUS "----------------------------:")
