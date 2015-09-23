cmake_minimum_required(VERSION 2.8)
project(theseus)
include(ExternalProject)

set(sfml_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/sfml")
set(sfml_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/sfml")
set(sfml_CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${sfml_INSTALL_DIR})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(EXECUTABLE_NAME "theseus")

message("sfml_PREFIX='${sfml_PREFIX}'")
message("sfml_INSTALL_DIR='${sfml_INSTALL_DIR}'")
message("sfml_CMAKE_ARGS='${sfml_CMAKE_ARGS}'")
message("GIT_EXECUTABLE='${GIT_EXECUTABLE}'")

ExternalProject_Add(sfml
  PREFIX ${sfml_PREFIX}
  GIT_REPOSITORY https://github.com/SFML/SFML
  GIT_TAG "2.3"
  INSTALL_DIR ${sfml_INSTALL_DIR}
  CMAKE_ARGS ${sfml_CMAKE_ARGS}
)

include_directories(${sfml_INSTALL_DIR}/include)
link_directories(${sfml_INSTALL_DIR}/lib)

configure_file(ball.png ${CMAKE_CURRENT_BINARY_DIR}/ball.png COPYONLY)

add_executable(${EXECUTABLE_NAME} main.cpp)

target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-window sfml-system)

install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

include(InstallRequiredSystemLibraries)
include(CPack)
