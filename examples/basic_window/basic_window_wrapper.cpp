#include "basic_window_wrapper.h"


Basic_Window_Wrapper::Basic_Window_Wrapper(const juangui_wrapper_parameters &parameters)
    :JuanGui_Wrapper(parameters)
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
        static float value = 0;

        if (ImGuiKnobs::Knob("Volume", &value, -6.0f, 6.0f, 0.1f, "%.1fdB", ImGuiKnobVariant_Tick)) {
            // value was changed
        }
        ImGui::End();
    }

    {
        int my_image_width = 0;
        int my_image_height = 0;
        GLuint my_image_texture = 0;
        bool ret = LoadTextureFromFile("../../images/example.jpg", &my_image_texture, &my_image_width, &my_image_height);
        IM_ASSERT(ret);

        ImGui::Begin("OpenGL Texture Text");
        //ImGui::Text("pointer = %x", my_image_texture);
        //ImGui::Text("size = %d x %d", my_image_width, my_image_height);
        ImGui::Image((void*)(intptr_t)my_image_texture, ImVec2(my_image_width, my_image_height));
        ImGui::End();
    }

    /*
    static bool my_tool_active = true;
    {


        //const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(ImVec2( ImGui::GetMainViewport()->WorkPos.x + 400,
                                       ImGui::GetMainViewport()->WorkPos.y + 30),
                                ImGuiCond_Once); // ImGuiCond_Once ImGuiCond_FirstUseEver
        ImGui::SetNextWindowSize(ImVec2(550, 680), ImGuiCond_Once);
        ImGui::Begin("Second Window",&my_tool_active,ImGuiWindowFlags_MenuBar);
        ImGui::Text("This is a basic example 2.");

        ImGui::PushItemWidth(ImGui::GetFontSize() * -12);
        // Menu Bar
        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("Menu"))
            {
                ImGui::Text("This is a basic menu.");
            }
            if (ImGui::BeginMenu("Examples"))
            {
                ImGui::Text("This is a basic example.");
            }
            //if (ImGui::MenuItem("MenuItem")) {} // You can also use MenuItem() inside a menu bar!
            if (ImGui::BeginMenu("Tools"))
            {
                ImGui::Text("This is a basic tool.");
            }
            ImGui::EndMenuBar();
        }

        ImGui::End();
    }*/
}
