#pragma once
#include <juangui_wrapper.h>



class Basic_Window_Wrapper: public JuanGui_Wrapper
{
protected:
    void my_custom_gui() override;
    void show_output_leds();
    void show_other_artifacts();
public:
    Basic_Window_Wrapper(const juangui_wrapper_parameters& parameters);

};


