cmake_minimum_required(VERSION 3.5)

project(basic_window LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include(${CMAKE_CURRENT_SOURCE_DIR}/../../dependencies.cmake)

add_library (basic_window_wrapper basic_window_wrapper.h basic_window_wrapper.cpp)
target_link_libraries(basic_window_wrapper juangui_wrapper)

add_executable(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}.cpp
    )


if (WIN32)
    target_link_libraries(${CMAKE_PROJECT_NAME}
                            imgui
                            implot
                            glfw
                            OpenGL::GL
                            basic_window_wrapper
                            )
endif()

if(UNIX AND NOT APPLE)
    target_link_libraries(${CMAKE_PROJECT_NAME}
                            imgui
                            implot
                            glfw
                            OpenGL::GL
                            basic_window_wrapper)
endif()

if(APPLE)
    target_link_libraries(${CMAKE_PROJECT_NAME}
                            imgui
                            implot
                            basic_window_wrapper
                            glfw
                            "-framework Cocoa"
                            "-framework OpenGL"
                            "-framework IOKit")
endif()

