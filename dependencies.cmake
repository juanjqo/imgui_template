

set (IMGUI_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../../imgui)
set (IMPLOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../implot)


if(UNIX AND NOT APPLE)
    FIND_PACKAGE(Eigen3 REQUIRED)
    INCLUDE_DIRECTORIES(${EIGEN3_INCLUDE_DIR})
    ADD_COMPILE_OPTIONS(-Werror=return-type -Wall -Wextra -Wmissing-declarations -Wredundant-decls -Woverloaded-virtual)
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
)

#find_package(OpenGL REQUIRED)

add_library(imgui ${IMGUI_HEADERS} ${IMGUI_SRC})
add_library(implot ${IMPLOT_HEADERS} ${IMPLOT_SRC})



