#include "minimal_example_imgui_demo_wrapper.h"

// Main code
int main(int, char**)
{

    juangui_wrapper_parameters parameters;
    parameters.width = 1280;
    parameters.height = 720;
    parameters.title = "Minimal Example";
    parameters.screen_mode = "DARK_MODE";
    parameters.font_path = "../../../imgui_template/fonts/Ubuntu/Ubuntu-Regular.ttf";
    parameters.font_size = 18;
    MinimalExampleImguiDemoWrapper imgui_demo_wrapper(parameters);

    //imgui_demo_wrapper.set_rgb_background_color(1, 0.79, 0.96);
    imgui_demo_wrapper.loop();
    return 0;
}
