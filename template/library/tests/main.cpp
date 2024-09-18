#include "GLFW/glfw3.h"
#include "helper.h"
#include "imgui.h"

int main() {
    GLFWwindow* window = helpGlfwCreateWindow(1920, 1200, "Imgui", 1);

    helpImguiInit();

    ImGuiIO& io = ImGui::GetIO();

    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    io.ConfigFlags |= ImGuiViewportFlags_NoDecoration;

    io.Fonts->AddFontFromFileTTF("c:/Windows/Fonts/msyh.ttc", 36.0f, NULL,
                                 io.Fonts->GetGlyphRangesChineseFull());

    ImGui::StyleColorsDark();

    helpSetupBackends(window, "#version 330");

    while (!glfwWindowShouldClose(window)) {
        helpFrameStart();

        ImGui::DockSpaceOverViewport();

        ImGui::Begin("Demo");
        ImGui::Text("hello world!\n");
        ImGui::Text("你好世界！\n");
        ImGui::End();

        ImGui::Render();

        helpViewportsEnable();

        helpFrameEnd(window);
    }

    helpCleanup(window);

    return 0;
}