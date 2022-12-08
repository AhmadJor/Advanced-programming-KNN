cmake_minimum_required(VERSION 3.20.2)
project(Advanced_programming_KNN)

set(CMAKE_CXX_STANDARD 11)

add_executable(Advanced_Programming_hw1 main.cpp Euclidean.cpp Euclidean.h Manhatin.cpp  Manhatin.h DistanceFunction.h Chebyshev.cpp Chebyshev.h Canberra.cpp Canberra.h Minkowski.cpp Minkowski.h Flower.cpp Flower.h)

