cmake_minimum_required(VERSION 3.10)

set(PROJECTNAME bitboardca)

project(${PROJECTNAME})

if(UNIX AND NOT APPLE)
  set(LINUX TRUE)
endif()

file(GLOB_RECURSE
  SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
  )

set(LIBNAME ${PROJECTNAME}-lib)
add_library(${LIBNAME} STATIC ${SOURCES})
target_include_directories(${LIBNAME}
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include/
  )
set_property(TARGET ${LIBNAME} PROPERTY CXX_STANDARD 17)

