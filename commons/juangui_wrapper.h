#pragma once
#include <imgui_definitions.h>
#include <memory>
#include <string>
#include <iostream>
#include <filesystem>

struct juangui_wrapper_parameters
{
    int width{1280};
    int height{720};
    std::string title{"Title"};
    std::string screen_mode{"LIGHT_MODE"};
    std::string font_path;
    int font_size{18};
    bool high_resolution_display{false};
};


class JuanGui_Wrapper
{


protected:
    //ImGuiIO& io_ = ImGui::GetIO();
    //ImGuiIO& io_ = 0;
    GLFWwindow* window_;
    std::shared_ptr<ImGuiViewport> main_viewport_;

    ImVec4 background_color_ = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    double dpi_ = 1.0;

    int width_;
    int height_;
    std::string title_;
    std::string screen_mode_;
    std::string font_path_;
    int font_size_;
    bool high_resolution_display_;


    bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height);

    void _start_settings();

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

    void set_screen_mode(const std::string& screen_mode);
    void gui();

    void select_font(const std::string font_path, const int& font_size);
    void stop_and_quit(const bool& break_main_loop_flag);

    ImGuiCond_ remember_window_positions_ = ImGuiCond_Once;
    void set_next_window_position(const int& x, const int& y);
    void set_next_window_size(const int& width, const int& height);
    void add_help_marker(const std::string& desc);

    virtual void my_custom_gui() = 0;

public:
    void loop();
    void set_screen_mode(const JuanGui_Wrapper::SCREEN_MODE& mode);
    void set_background_color(const ImVec4& background_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f));
    void set_rgb_background_color(const double& r, const double& g, const double& b);
    void remember_window_positions(const bool& remember_window_positions_flag = true);
};




