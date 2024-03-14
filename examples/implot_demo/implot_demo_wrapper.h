#pragma once
#include <juangui_wrapper.h>

class Implot_Demo_Wrapper: public JuanGui_Wrapper
{
public:

    Implot_Demo_Wrapper(const juangui_wrapper_parameters& parameters);

    void my_custom_gui() override;
};





