#pragma once
#include <juangui_wrapper.h>



class Basic_Window_Wrapper: public JuanGui_Wrapper
{
public:

    Basic_Window_Wrapper(const juangui_wrapper_parameters& parameters);
    void my_custom_gui() override;
};


