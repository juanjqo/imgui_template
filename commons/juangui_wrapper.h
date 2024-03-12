#pragma once
#include <my_imgui_definitions.h>
#include <memory>
#include<my_imgui_definitions.h>
#include <string>
#include <iostream>




class JuanGui_Wrapper
{


protected:
    //ImGuiIO& io_ = ImGui::GetIO();
    //ImGuiIO& io_ = 0;
    GLFWwindow* window_;
    ImVec4 clear_color_ = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height);

public:
    enum class SCREEN_MODE{DARK_MODE, LIGHT_MODE};
    enum class FONT{DEFAULT, UBUNTU};
    JuanGui_Wrapper(const int& width,
                    const int& height,
                    const std::string& title,
                    const JuanGui_Wrapper::SCREEN_MODE& mode = JuanGui_Wrapper::SCREEN_MODE::LIGHT_MODE,
                    const JuanGui_Wrapper::FONT& font = JuanGui_Wrapper::FONT::UBUNTU,
                    const double& font_size = 18.0);
    JuanGui_Wrapper() = delete;
    JuanGui_Wrapper(const JuanGui_Wrapper&) = delete;
    JuanGui_Wrapper& operator= (const JuanGui_Wrapper&) = delete;

    GLFWwindow* get_glfw_ptr();
    void check_error_callback();

    void cleanup();
    void render();
    bool window_should_close();
    void set_screen_mode(const JuanGui_Wrapper::SCREEN_MODE& mode);
    void gui();
    void loop();





    virtual void my_custom_gui() = 0;







};




