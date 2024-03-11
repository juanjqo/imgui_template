#pragma once
#include <memory>
#include<my_imgui_definitions.h>
#include <string>
#include <iostream>



class JuanGui_Wrapper
{


protected:

    GLFWwindow* window_;
    ImVec4 clear_color_ = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
public:
    enum class SCREEN_MODE{DARK_MODE, LIGHT_MODE};
    enum class FONT{DEFAULT, UBUNTU};
    JuanGui_Wrapper(const int& width,
                    const int& height,
                    const std::string& title,
                    const JuanGui_Wrapper::SCREEN_MODE& mode = JuanGui_Wrapper::SCREEN_MODE::LIGHT_MODE,
                    const JuanGui_Wrapper::FONT& font = JuanGui_Wrapper::FONT::UBUNTU,
                    const double& font_size = 18.0);


    void check_error_callback();

    void cleanup();

    bool window_should_close();
    void render();

    void gui();

    void set_screen_mode(const JuanGui_Wrapper::SCREEN_MODE& mode);

    GLFWwindow* get_glfw_ptr();



};




