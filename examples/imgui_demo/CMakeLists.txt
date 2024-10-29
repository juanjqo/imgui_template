cmake_minimum_required(VERSION 3.5)

project(imgui_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(IMGUI_TEMPLATE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../.././../imgui_template/)
include(${IMGUI_TEMPLATE_DIR}/dependencies.cmake)

set(CUSTOM_JUANGUI_WRAPPER imgui_demo_wrapper) # Change here the name of your wrapper subclass
add_library (${CUSTOM_JUANGUI_WRAPPER} ${CUSTOM_JUANGUI_WRAPPER}.h ${CUSTOM_JUANGUI_WRAPPER}.cpp)
target_link_libraries(${CUSTOM_JUANGUI_WRAPPER} juangui_wrapper)


add_executable(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} ${IMGUI_TOOL_LIBS} ${CUSTOM_JUANGUI_WRAPPER})


