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

    //Basic_Window_Wrapper basic_window_wrapper(1280, 720, "Juanchotronics", JuanGui_Wrapper::SCREEN_MODE::LIGHT_MODE);


    basic_window_wrapper.loop();

    basic_window_wrapper.cleanup();

    return 0;
}
