cmake_minimum_required(VERSION 3.25)

project(dancing-shapes)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

file(GLOB_RECURSE SOURCES ${SRC_DIR}/*.cpp ${CMAKE_SOURCE_DIR}/main.cpp)

include_directories(${INCLUDE_DIR})

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

file(COPY ${RESOURCES_DIR} DESTINATION ${CMAKE_BINARY_DIR})

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)
