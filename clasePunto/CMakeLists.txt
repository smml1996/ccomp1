cmake_minimum_required(VERSION 3.6)
project(clasePunto)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    arrPoints.cpp
    arrPoints.h
    arrVectors.cpp
    arrVectors.h
    polygon.h
    polygon.cpp
    rectangle.h
    rectangle.cpp
    main.cpp
    punto.cpp
    punto.h
    vector2.cpp
    vector2.h)

add_executable(clasePunto ${SOURCE_FILES})