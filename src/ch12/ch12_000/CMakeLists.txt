cmake_minimum_required(VERSION 3.0.0)
project(test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB PROJECT_SOURCE_FILES src/*.cpp)
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_FILES})
include_directories(/include)

set(FLTK_DIR "/usr/lib/fltk")
find_package(FLTK REQUIRED NO_MODULE)
include_directories(${FLTK_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} fltk fltk_images)

# message(STATUS "Print the available fltk_libraries:")
# message(STATUS "${FLTK_LIBRARIES}")
