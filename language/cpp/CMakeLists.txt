cmake_minimum_required(VERSION 3.20)
project(kaya-model)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(kaya-model
        src/nerd4ever/kaya/model/Event.cpp
        src/nerd4ever/kaya/model/Event.h
        )
