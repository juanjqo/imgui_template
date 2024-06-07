#pragma once
#include <juangui_wrapper.h>

class Implot_Demo_Wrapper: public JuanGui_Wrapper
{
protected:
    void my_custom_gui() override;
public:
    Implot_Demo_Wrapper(const juangui_wrapper_parameters& parameters);
};





