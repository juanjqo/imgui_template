#include "imgui_demo_wrapper.h"

// Main code
int main(int, char**)
{


    Imgui_Demo_Wrapper imgui_demo_wrapper(1280, 720, "Juanchotronics", JuanGui_Wrapper::SCREEN_MODE::LIGHT_MODE);


    imgui_demo_wrapper.loop();

   imgui_demo_wrapper.cleanup();
    return 0;
}
