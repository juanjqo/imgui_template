#include "juangui_wrapper.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

JuanGui_Wrapper::JuanGui_Wrapper(const int& width,
                                 const int& height,
                                 const std::string& title,
                                 const JuanGui_Wrapper::SCREEN_MODE& mode ,
                                 const JuanGui_Wrapper::FONT& font,
                                 const double& font_size)
{

    std::string screen_mode;
    if (mode == JuanGui_Wrapper::SCREEN_MODE::DARK_MODE)
    {
        screen_mode = "DARK_MODE";
    }else{
        screen_mode = "LIGHT_MODE";
    }
    std::string font_path = std::string("../../fonts/Ubuntu/Ubuntu-Regular.ttf");

    _start_settings(width, height, title, screen_mode, font_path, font_size);
}

JuanGui_Wrapper::JuanGui_Wrapper(const juangui_wrapper_parameters &parameters)
{
   _start_settings(parameters.width,
                    parameters.height,
                    parameters.title,
                    parameters.screen_mode,
                    parameters.font_path,
                    parameters.font_size);
}


// Simple helper function to load an image into a OpenGL texture with common settings
bool JuanGui_Wrapper::LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height)
{
    // Load from file
    int image_width = 0;
    int image_height = 0;
    unsigned char* image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
    if (image_data == NULL)
        return false;

    // Create a OpenGL texture identifier
    GLuint image_texture;
    glGenTextures(1, &image_texture);
    glBindTexture(GL_TEXTURE_2D, image_texture);

    // Setup filtering parameters for display
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // This is required on WebGL for non power-of-two textures
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Same

// Upload pixels into texture
#if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
    stbi_image_free(image_data);

    *out_texture = image_texture;
    *out_width = image_width;
    *out_height = image_height;

    return true;
}

void JuanGui_Wrapper::_start_settings(const int &width,
                                      const int &height,
                                      const std::string &title,
                                      const std::string &screen_mode,
                                      const std::string &font_path,
                                      const double &font_size)
{
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        throw std::runtime_error("Error in glfwInit()");

// Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
    // GL ES 2.0 + GLSL 100
    const char* glsl_version = "#version 100";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#elif defined(__APPLE__)
    // GL 3.2 + GLSL 150
    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif

    window_ = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (window_ == nullptr)
        throw std::runtime_error("Error in window()");

    glfwMakeContextCurrent(window_);
    glfwSwapInterval(1); // Enable vsync



    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImPlot::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls



    set_screen_mode(screen_mode);

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window_, true);
#ifdef __EMSCRIPTEN__
    ImGui_ImplGlfw_InstallEmscriptenCanvasResizeCallback("#canvas");
#endif
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return a nullptr. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Use '#define IMGUI_ENABLE_FREETYPE' in your imconfig file to use Freetype for higher quality font rendering.
    // - Read 'docs/FONTS.md' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    // - Our Emscripten build process allows embedding fonts to be accessible at runtime from the "fonts/" folder. See Makefile.emscripten for details.
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\segoeui.ttf", 18.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, nullptr, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != nullptr);


    //IM_ASSERT(font != nullptr);
    // Our state


    // This is not working!
    try {
        io.Fonts->AddFontFromFileTTF(font_path.c_str(), static_cast<float>(font_size));

    } catch (std::exception& e) {
        io.Fonts->AddFontDefault();
    }



}

void JuanGui_Wrapper::cleanup()
{
    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImPlot::DestroyContext();
    ImGui::DestroyContext();

    glfwDestroyWindow(window_);
    glfwTerminate();
}


/**
 * @brief JuanGui_Wrapper::window_should_close
 * @return
 */
bool JuanGui_Wrapper::window_should_close()
{
    return glfwWindowShouldClose(window_);
}


/**
 * @brief JuanGui_Wrapper::render
 */
void JuanGui_Wrapper::render()
{
    // Rendering

    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window_, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(clear_color_.x * clear_color_.w, clear_color_.y * clear_color_.w, clear_color_.z * clear_color_.w, clear_color_.w);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(window_);
}


/**
 * @brief JuanGui_Wrapper::loop
 */
void JuanGui_Wrapper::loop()
{
// Main loop
#ifdef __EMSCRIPTEN__
    // For an Emscripten build we are disabling file-system access, so let's not attempt to do a fopen() of the imgui.ini file.
    // You may manually call LoadIniSettingsFromMemory() to load settings from your own storage.
    io.IniFilename = nullptr;
    EMSCRIPTEN_MAINLOOP_BEGIN
#else
    while (!window_should_close())
#endif
    {
        gui();
    }
#ifdef __EMSCRIPTEN__
    EMSCRIPTEN_MAINLOOP_END;
#endif


    cleanup();
}






/**
 * @brief JuanGui_Wrapper::gui
 */
void JuanGui_Wrapper::gui()
{
    // Poll and handle events (inputs, window resize, etc.)
    // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
    // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
    // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
    // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
    glfwPollEvents();
    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    my_custom_gui();
    render();
}

void JuanGui_Wrapper::set_screen_mode(const SCREEN_MODE& mode)
{
    if (mode == JuanGui_Wrapper::SCREEN_MODE::DARK_MODE)
        ImGui::StyleColorsDark();
    else
        ImGui::StyleColorsLight();

}

void JuanGui_Wrapper::set_screen_mode(const std::string &screen_mode)
{
    if (screen_mode == "DARK_MODE"){
        ImGui::StyleColorsDark();
    }else if (screen_mode == "LIGHT_MODE")
    {
        ImGui::StyleColorsLight();
    }else
    {
        //throw std::runtime_error("Wrong screen mode. Use DARK_MODE or LIGHT_MODE");
        std::cerr<<"Wrong screen mode. Use DARK_MODE or LIGHT_MODE"<<std::endl;
        std::cerr<<"LIGHT_MODE was selected instead!"<<std::endl;
        ImGui::StyleColorsLight();
        //throw std::invalid_argument( "received negative value" );
    }
}

GLFWwindow *JuanGui_Wrapper::get_glfw_ptr()
{
    return window_;
}


