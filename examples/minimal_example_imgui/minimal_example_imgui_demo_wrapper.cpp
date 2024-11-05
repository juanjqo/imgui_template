#include "minimal_example_imgui_demo_wrapper.h"
#include "juangui_wrapper.h"


void MinimalExampleImguiDemoWrapper::my_custom_gui()
{
    ImGui::Begin("Minimal example window");
    ImGui::Text("Hello wordl");
    ImGui::End();

}

MinimalExampleImguiDemoWrapper::MinimalExampleImguiDemoWrapper(const juangui_wrapper_parameters &parameters)
    :JuanGui_Wrapper(parameters)
{

}
