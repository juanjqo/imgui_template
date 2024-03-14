#pragma once
#include <juangui_wrapper.h>

class Imgui_Demo_Wrapper: public JuanGui_Wrapper
{
public:

    Imgui_Demo_Wrapper(const juangui_wrapper_parameters& parameters);

    void my_custom_gui() override;
};

