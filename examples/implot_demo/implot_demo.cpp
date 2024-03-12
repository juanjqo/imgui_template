#include "implot_demo_wrapper.h"

// Main code
int main(int, char**)
{

    Implot_Demo_Wrapper implot_demo_wrapper(1280, 720, "Juanchotronics", JuanGui_Wrapper::SCREEN_MODE::LIGHT_MODE);


    implot_demo_wrapper.loop();

    implot_demo_wrapper.cleanup();
    return 0;
}
