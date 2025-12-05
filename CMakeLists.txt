cmake_minimum_required(VERSION 4.0)
project(TpAlgo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(SFML_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/src")
list(APPEND CMAKE_PREFIX_PATH "${SFML_ROOT}")

find_package(SFML 3.0 COMPONENTS graphics window system REQUIRED)

include_directories(.)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/lib)

add_executable(${PROJECT_NAME}
        src/GameMap.cpp
        src/GameMap.h
        src/main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
)

if (WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
                "${SFML_ROOT}/bin"
                $<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif ()