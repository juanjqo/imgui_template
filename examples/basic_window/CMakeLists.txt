cmake_minimum_required(VERSION 3.5)

project(basic_window LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include(${CMAKE_CURRENT_SOURCE_DIR}/../../dependencies.cmake)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)




if(UNIX AND NOT APPLE)
    target_link_libraries(${CMAKE_PROJECT_NAME}
                            imgui
                            implot
                            glfw )
endif()

if(APPLE)
    target_link_libraries(${CMAKE_PROJECT_NAME}
                            imgui
                            glfw
                            "-framework Cocoa"
                            "-framework OpenGL"
                            "-framework IOKit")
endif()

