#include <my_imgui_definitions.h>
#include <juangui_wrapper.h>

// Main code
int main(int, char**)
{


    JuanGui_Wrapper juangui(1280, 720, "Dear ImGui GLFW+OpenGL3 example", JuanGui_Wrapper::SCREEN_MODE::DARK_MODE);


// Main loop
#ifdef __EMSCRIPTEN__
    // For an Emscripten build we are disabling file-system access, so let's not attempt to do a fopen() of the imgui.ini file.
    // You may manually call LoadIniSettingsFromMemory() to load settings from your own storage.
    io.IniFilename = nullptr;
    EMSCRIPTEN_MAINLOOP_BEGIN
#else
    //while (!glfwWindowShouldClose(window))
    while (!juangui.window_should_close())
    //while (!glfwWindowShouldClose(juangui.get_glfw_ptr()))
#endif
    {

        juangui.gui();
        juangui.render();

    }
#ifdef __EMSCRIPTEN__
    EMSCRIPTEN_MAINLOOP_END;
#endif

    juangui.cleanup();

    return 0;
}
