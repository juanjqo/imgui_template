#pragma once
#include <juangui_wrapper.h>

class MinimalExampleImguiDemoWrapper : public JuanGui_Wrapper
{
protected:
    void my_custom_gui() override;
public:
    MinimalExampleImguiDemoWrapper(const juangui_wrapper_parameters& parameters);
};

