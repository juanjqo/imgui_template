#pragma once
#include <imgui_definitions.h>
#include <memory>
#include <string>
#include <iostream>
#include <filesystem>

struct juangui_wrapper_parameters
{
    int width;
    int height;
    std::string title;
    std::string screen_mode;
    std::string font_path;
    int font_size;
};


class JuanGui_Wrapper
{


protected:
    //ImGuiIO& io_ = ImGui::GetIO();
    //ImGuiIO& io_ = 0;
    GLFWwindow* window_;
    ImVec4 clear_color_ = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height);

    void _start_settings(const int& width,
                         const int& height,
                         const std::string& title,
                         const std::string& screen_mode,
                         const std::string& font_path,
                         const double& font_size
                         );

    enum class SCREEN_MODE{DARK_MODE, LIGHT_MODE};

    void cleanup();
    void render();
    bool break_main_loop_flag_ = false;

    JuanGui_Wrapper(const juangui_wrapper_parameters& parameters);
    JuanGui_Wrapper() = delete;
    JuanGui_Wrapper(const JuanGui_Wrapper&) = delete;
    JuanGui_Wrapper& operator= (const JuanGui_Wrapper&) = delete;

    void check_error_callback();
    bool window_should_close();
    void set_screen_mode(const JuanGui_Wrapper::SCREEN_MODE& mode);
    void set_screen_mode(const std::string& screen_mode);
    void gui();

    void select_font(const std::string font_path, const int& font_size);
    void stop_and_quit(const bool& break_main_loop_flag);

    virtual void my_custom_gui() = 0;

public:
    void loop();
};




