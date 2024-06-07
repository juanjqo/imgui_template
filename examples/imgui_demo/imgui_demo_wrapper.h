#pragma once
#include <juangui_wrapper.h>

class Imgui_Demo_Wrapper: public JuanGui_Wrapper
{
protected:
    void my_custom_gui() override;
public:
    Imgui_Demo_Wrapper(const juangui_wrapper_parameters& parameters);
};

