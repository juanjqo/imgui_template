#include "basic_window_wrapper.h"


int main(int, char**)
{


    Basic_Window_Wrapper basic_window_wrapper(1280, 720, "Juanchotronics", JuanGui_Wrapper::SCREEN_MODE::LIGHT_MODE);


    basic_window_wrapper.loop();

    basic_window_wrapper.cleanup();

    return 0;
}
