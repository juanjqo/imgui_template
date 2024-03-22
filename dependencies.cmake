
if (WIN32)
    include(C:/Tools/vcpkg/scripts/buildsystems/vcpkg.cmake)
    set(CMAKE_TOOLCHAIN_FILE C:/Tools/vcpkg/scripts/buildsystems/vcpkg.cmake)
endif()


set (IMGUI_DIR  ${IMGUI_TEMPLATE_DIR}/submodules/imgui)
set (IMPLOT_DIR ${IMGUI_TEMPLATE_DIR}/submodules/implot)
set (COMMONS_DIR ${IMGUI_TEMPLATE_DIR}/commons)
set (STB_DIRS    ${IMGUI_TEMPLATE_DIR}/submodules/stb)
set (IMGUI_KNOBS ${IMGUI_TEMPLATE_DIR}/submodules/imgui-knobs)

if (WIN32)
    # GLFW
    ADD_DEFINITIONS(-D_USE_MATH_DEFINES)
    FIND_PACKAGE(Eigen3 CONFIG REQUIRED)
    #FIND_PACKAGE(glfw3 CONFIG REQUIRED)

    find_package(OpenGL REQUIRED)
    INCLUDE_DIRECTORIES(
            ${EIGEN3_INCLUDE_DIR}
            #${GLFW3_INCLUDE_DIRS}
            # Default path when using cmake .., cmake --build ., cmake --install .
            # "C:/Program Files (x86)/dqrobotics/include"
            #"C:/Tools/vcpkg/installed/x64-windows/include/"
            )

    # GLFW
    set(GLFW_DIR ${IMGUI_TEMPLATE_DIR}/submodules/glfw) # Set this to point to an up-to-date GLFW repo
    option(GLFW_BUILD_EXAMPLES "Build the GLFW example programs" OFF)
    option(GLFW_BUILD_TESTS "Build the GLFW test programs" OFF)
    option(GLFW_BUILD_DOCS "Build the GLFW documentation" OFF)
    option(GLFW_INSTALL "Generate installation target" OFF)
    option(GLFW_DOCUMENT_INTERNALS "Include internals in documentation" OFF)
    add_subdirectory(${GLFW_DIR} binary_dir EXCLUDE_FROM_ALL)



    include_directories(${GLFW_DIR}/include)

    message(STATUS "GLFW3_INCLUDE_PATH=${GLFW_DIR}")
    #if(GLFW_FOUND) # Works with some other methods
    #        message(STATUS "GLFW3_INCLUDE_PATH=${GLFW3_INCLUDE_PATH}")
    #        message(STATUS "GLFW_LIBRARIES=${GLFW_LIBRARIES}")
    #else( GLFW_FOUND )
    #    message(FATAL_ERROR "GLFW3 not found")
    #endif( GLFW_FOUND )
endif()



if(UNIX AND NOT APPLE)
    FIND_PACKAGE(Eigen3 REQUIRED)
    INCLUDE_DIRECTORIES(${EIGEN3_INCLUDE_DIR})
    find_package(OpenGL REQUIRED)
    #FIND_PACKAGE(GLFW3 REQUIRED)
    ADD_COMPILE_OPTIONS(-Werror=return-type -Wall -Wextra -Wmissing-declarations -Wredundant-decls -Woverloaded-virtual)

    # GLFW
    set(GLFW_DIR ${IMGUI_TEMPLATE_DIR}/submodules/glfw) # Set this to point to an up-to-date GLFW repo
    option(GLFW_BUILD_EXAMPLES "Build the GLFW example programs" OFF)
    option(GLFW_BUILD_TESTS "Build the GLFW test programs" OFF)
    option(GLFW_BUILD_DOCS "Build the GLFW documentation" OFF)
    option(GLFW_INSTALL "Generate installation target" OFF)
    option(GLFW_DOCUMENT_INTERNALS "Include internals in documentation" OFF)
    add_subdirectory(${GLFW_DIR} binary_dir EXCLUDE_FROM_ALL)

    # sudo apt-get update
    # sudo apt install xorg-dev
    # sudo apt install libwayland-dev libxkbcommon-dev wayland-protocols extra-cmake-modules

    include_directories(${GLFW_DIR}/include)
    #set(LIBRARIES "glfw")
    # FETCH CONTENT LIBS
    #include(FetchContent)
    #FetchContent_Declare(glfw GIT_REPOSITORY https://github.com/glfw/glfw)
    #FetchContent_MakeAvailable(glfw)
endif()

if(APPLE)
    INCLUDE_DIRECTORIES(
        /usr/local/include/
        /usr/local/include/eigen3
        # Most recent versions of brew install here
        /opt/homebrew/include
        /opt/homebrew/include/eigen3
        /opt/howebrew/include/fmt
        /opt/howebrew/include/GLFW   #OPENGL 3
        #/opt/howebrew/include/SDL2   #METAL
        #/System/Library/Frameworks
    )
ADD_COMPILE_OPTIONS(-Werror=return-type -Wall -Wextra -Wmissing-declarations -Wredundant-decls -Woverloaded-virtual)
# The library is installed here when using the regular cmake ., make, sudo make install
LINK_DIRECTORIES(
    /usr/local/lib/
    /opt/homebrew/lib
    )
endif()

include_directories(${IMGUI_DIR})
include_directories(${IMGUI_DIR}/backends)
include_directories(${IMPLOT_DIR})
include_directories(${COMMONS_DIR})
include_directories(${STB_DIRS})
include_directories(${IMGUI_KNOBS})


set(IMGUI_HEADERS
     ${IMGUI_DIR}/imconfig.h
     ${IMGUI_DIR}/imgui_internal.h
     ${IMGUI_DIR}/imgui.h
     ${IMGUI_DIR}/imstb_rectpack.h
     ${IMGUI_DIR}/imstb_textedit.h
     ${IMGUI_DIR}/imstb_truetype.h
     ${IMGUI_DIR}/backends/imgui_impl_glfw.h
     ${IMGUI_DIR}/backends/imgui_impl_opengl3.h
     ${IMGUI_DIR}/backends/imgui_impl_opengl3_loader.h
     ${IMGUI_DIR}/misc/cpp/imgui_stdlib.h
)

set(IMGUI_SRC
     ${IMGUI_DIR}/imgui_demo.cpp
     ${IMGUI_DIR}/imgui_draw.cpp
     ${IMGUI_DIR}/imgui_tables.cpp
     ${IMGUI_DIR}/imgui_widgets.cpp
     ${IMGUI_DIR}/imgui.cpp
     ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
     ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
     ${IMGUI_DIR}/misc/cpp/imgui_stdlib.cpp
)


set(IMPLOT_HEADERS
    ${IMPLOT_DIR}/implot.h
    ${IMPLOT_DIR}/implot_internal.h
)
set(IMPLOT_SRC
    ${IMPLOT_DIR}/implot.cpp
    ${IMPLOT_DIR}/implot_items.cpp
    ${IMPLOT_DIR}/implot_demo.cpp
)

add_library(imgui-knobs
    ${IMGUI_KNOBS}/imgui-knobs.h
    ${IMGUI_KNOBS}/imgui-knobs.cpp
)

add_library(juancho-tools
    ${COMMONS_DIR}/juancho_tools.h
    ${COMMONS_DIR}/juancho_tools.cpp)


add_library(imgui ${IMGUI_HEADERS} ${IMGUI_SRC})
add_library(implot ${IMPLOT_HEADERS} ${IMPLOT_SRC})
add_library(juangui_wrapper ${COMMONS_DIR}/juangui_wrapper.cpp)

if(UNIX AND NOT APPLE)
    target_link_libraries(juangui_wrapper
        imgui
        implot
        imgui-knobs
        glfw
        OpenGL::GL)

    target_link_libraries(imgui-knobs
        imgui
    )
endif()

#add_definitions( -DIMGUI_TEMPLATE_DIR=${IMGUI_TEMPLATE_DIR})

set(IMGUI_TEMPLATE_DIR ${IMGUI_TEMPLATE_DIR})
configure_file(${COMMONS_DIR}/my_imgui_custom_definitions.h.in
               ${COMMONS_DIR}/my_imgui_custom_definitions.h)

#include_directories(${COMMONS_DIR}/my_imgui_custom_definitions.h)




