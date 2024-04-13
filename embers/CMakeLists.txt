cmake_minimum_required(VERSION 3.23)
###
PROJECT(embers VERSION 0.0.1 LANGUAGES CXX)
SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

INCLUDE(GNUInstallDirs)

SET(SOURCES
        src/test.cc
        src/logger.cc
        src/assertions.cc
        src/window.cc
        src/application.cc
)

SET(HEADERS
        include/embers/test.h
)

add_subdirectory(external/glfw)
add_subdirectory(external/glm)

ADD_LIBRARY(
        ${PROJECT_NAME}
        SHARED
        ${SOURCES}
)

TARGET_INCLUDE_DIRECTORIES(
        ${PROJECT_NAME}
        PUBLIC
        glm
        glfw
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE

)

TARGET_LINK_LIBRARIES(
        ${PROJECT_NAME}
        PUBLIC
        glm
        glfw
        PRIVATE

)

