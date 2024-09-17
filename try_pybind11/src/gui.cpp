#include "gui.h"

#include "imgui.h"

void drawGui(GLFWwindow *window) {
    static bool main_open = true;

    if (main_open) {
        ImGui::Begin("Demo", &main_open);
        ImGui::Text("hello world!");
        ImGui::Text("你好世界！");
        ImGui::Text("%.2f FPS", ImGui::GetIO().Framerate);
        ImGui::End();
    } else {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}
