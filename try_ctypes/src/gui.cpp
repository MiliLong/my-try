#include "gui.h"

#include "imgui.h"

void drawGui(GLFWwindow *window) {
    static bool main_open = true;

    if (main_open) {
        ImGui::Begin("Demo", &main_open);
        ImGui::Text("hello world!\n");
        ImGui::Text("你好世界！\n");
        ImGui::Text("%.2f FPS", ImGui::GetIO().Framerate);
        ImGui::End();
    } else {
        exit(0);
    }
}
