cmake_minimum_required(VERSION 3.5)

project(implot_demo LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include(${CMAKE_CURRENT_SOURCE_DIR}/../../dependencies.cmake)

add_library (implot_demo_wrapper implot_demo_wrapper.h implot_demo_wrapper.cpp)
target_link_libraries(implot_demo_wrapper juangui_wrapper)

add_executable(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}.cpp
                )


if (WIN32)
    target_link_libraries(${CMAKE_PROJECT_NAME}
                            imgui
                            implot
                            implot_demo_wrapper
                            glfw
                            OpenGL::GL
                            )
endif()

if(UNIX AND NOT APPLE)
    target_link_libraries(${CMAKE_PROJECT_NAME}
                            imgui
                            implot
                            glfw
                            implot_demo_wrapper)
endif()

if(APPLE)
    target_link_libraries(${CMAKE_PROJECT_NAME}
                            imgui
                            implot
                            glfw
                            implot_demo_wrapper
                            "-framework Cocoa"
                            "-framework OpenGL"
                            "-framework IOKit")
endif()
