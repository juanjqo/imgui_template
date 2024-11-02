#include "basic_window_wrapper.h"


int main()
{
    juangui_wrapper_parameters parameters;
    parameters.width = 1280;
    parameters.height = 720;
    parameters.title = "Juanchotronics";
    parameters.screen_mode = "DARK_MODE";
    //parameters.font_path = "../../../imgui_template/fonts/Ubuntu/Ubuntu-Regular.ttf"; //your custom font
    parameters.font_path = "default";
    parameters.font_size = 18;
    parameters.high_resolution_display = true;

    Basic_Window_Wrapper basic_window_wrapper(parameters);
    basic_window_wrapper.remember_window_positions(false);

    basic_window_wrapper.loop();

    return 0;
}
