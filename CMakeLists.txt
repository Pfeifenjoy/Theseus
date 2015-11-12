cmake_minimum_required(VERSION 2.8)
project(theseus)

# Define sources and executable
set(EXECUTABLE_NAME "theseus")
FILE(GLOB_RECURSE SRCS "src/*.cpp")
add_executable(${EXECUTABLE_NAME} ${SRCS} ${CMAKE_CURRENT_SOURCE_DIR}/CMakeRes.rc)

# Set some compiler flags
#if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
if (MSVC)
  set(CMAKE_CXX_FLAGS "/W3 /EHsc /MP")
else ()
  set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -pedantic-errors")
endif()

# Include SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED COMPONENTS graphics window system network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

# Install resources
FILE(COPY resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# group files in Visual Studuo
# source: https://cmake.org/pipermail/cmake/2013-November/056336.html
macro(GroupSources curdir)
  file(GLOB children RELATIVE ${PROJECT_SOURCE_DIR}/${curdir}
  ${PROJECT_SOURCE_DIR}/${curdir}/*)
  foreach(child ${children})
    if(IS_DIRECTORY ${PROJECT_SOURCE_DIR}/${curdir}/${child})
      GroupSources(${curdir}/${child})
    else()
      string(REPLACE "/" "\\" groupname ${curdir})
      source_group(${groupname} FILES
    ${PROJECT_SOURCE_DIR}/${curdir}/${child})
    endif()
  endforeach()
endmacro()

GroupSources(src)
