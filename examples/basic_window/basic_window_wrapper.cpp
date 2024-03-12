#include "basic_window_wrapper.h"

Basic_Window_Wrapper::Basic_Window_Wrapper(const int& width,
                                            const int& height,
                                            const std::string& title,
                                            const JuanGui_Wrapper::SCREEN_MODE& mode,
                                            const JuanGui_Wrapper::FONT& font,
                                           const double& font_size)
    :JuanGui_Wrapper(width, height, title, mode, font, font_size)
{

}

void Basic_Window_Wrapper::my_custom_gui()
{
    // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
    {
        static float f = 0.0f;
        static int counter = 0;

        ImGui::Begin("Hello, Juanchito!");                          // Create a window called "Hello, world!" and append into it.

        ImGui::Text("This is a basic example.");               // Display some text (you can use a format strings too)
        //ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
        //ImGui::Checkbox("Another Window", &show_another_window);

        ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
        ImGui::ColorEdit3("clear color", (float*)&clear_color_); // Edit 3 floats representing a color

        if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
            counter++;
        ImGui::SameLine();
        ImGui::Text("counter = %d", counter);

        //ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
        ImGui::End();


    }
}
