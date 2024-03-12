#pragma once
#include <juangui_wrapper.h>

class Imgui_Demo_Wrapper: public JuanGui_Wrapper
{
public:
    Imgui_Demo_Wrapper(const int& width,
                       const int& height,
                       const std::string& title,
                       const JuanGui_Wrapper::SCREEN_MODE& mode = JuanGui_Wrapper::SCREEN_MODE::LIGHT_MODE,
                       const JuanGui_Wrapper::FONT& font = JuanGui_Wrapper::FONT::UBUNTU,
                       const double& font_size = 18.0);

    void my_custom_gui() override;
};
