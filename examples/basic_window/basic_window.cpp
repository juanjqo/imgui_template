#include "basic_window_wrapper.h"


int main(int, char**)
{
    juangui_wrapper_parameters parameters;
    parameters.width = 1280;
    parameters.height = 720;
    parameters.title = "Juanchotronics";
    parameters.screen_mode = "LIGHT_MODE";
    parameters.font_path = "../../../imgui_template/fonts/Ubuntu/Ubuntu-Regular.ttf";
    parameters.font_size = 18;

    Basic_Window_Wrapper basic_window_wrapper(parameters);

    basic_window_wrapper.loop();

    return 0;
}
