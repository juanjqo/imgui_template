#include "implot_demo_wrapper.h"

// Main code
int main(int, char**)
{

    juangui_wrapper_parameters parameters;
    parameters.width = 1280;
    parameters.height = 720;
    parameters.title = "Juanchotronics";
    parameters.screen_mode = "LIGHT_MODE";
    parameters.font_path = "../../../imgui_template/fonts/Ubuntu/Ubuntu-Regular.ttf";
    parameters.font_size = 16;
    Implot_Demo_Wrapper implot_demo_wrapper(parameters);


    implot_demo_wrapper.loop();
    return 0;
}
