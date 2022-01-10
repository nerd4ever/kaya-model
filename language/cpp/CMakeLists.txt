cmake_minimum_required(VERSION 3.20)
project(kaya-model)

set(CMAKE_CXX_STANDARD 17)
find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)
message(NOTICE "JSONCPP Library ${JSONCPP_LIBRARIES}")
include_directories(src)

include_directories(${JSONCPP_INCLUDE_DIRS})
set(kaya-model-deps ${kaya-model-deps} ${JSONCPP_LIBRARIES})
add_library(kaya-model STATIC
        src/nerd4ever/kaya/model/Event.cpp
        src/nerd4ever/kaya/model/Event.h
        src/nerd4ever/kaya/model/IWebhook.h
        )
target_link_libraries(kaya-model  ${kaya-model-deps})