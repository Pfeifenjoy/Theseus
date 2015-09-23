cmake_minimum_required(VERSION 2.6)
project(theseus)

# Define sources and executable
set(EXECUTABLE_NAME "theseus")
add_executable(${EXECUTABLE_NAME} src/main.cpp)

# Set Compiler flags for G++
set(CMAKE_CXX_FLAGS "-Wall -std=c++11")

# Include SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2 REQUIRED COMPONENTS graphics window system network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_DEPENDENCIES})
endif()

# Install images
configure_file(src/ball.png ${CMAKE_CURRENT_BINARY_DIR}/ball.png COPYONLY)
