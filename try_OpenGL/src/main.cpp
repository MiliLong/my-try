#ifndef GLAD_ONCE
#define GLAD_ONCE
#include <glad/glad.h>
#endif

#include <GLFW/glfw3.h>
#include <imgui.h>

#include "gui.h"
#include "helper.h"

void *helpStart(int width, int height, const char *title, int interval) {
    GLFWwindow *window =
        (GLFWwindow *)helpGlfwCreateWindow(width, height, title, interval);

    helpGladLoadGLLoader();

    helpImguiInit();

    ImGuiIO &io = ImGui::GetIO();

    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    io.ConfigViewportsNoAutoMerge = true;

    io.Fonts->AddFontFromFileTTF("c:/Windows/Fonts/msyh.ttc", 36.0f, nullptr,
                                 io.Fonts->GetGlyphRangesChineseFull());

    ImGui::StyleColorsClassic();

    ImGuiStyle &style = ImGui::GetStyle();
    style.WindowBorderSize = 1;
    style.FrameBorderSize = 0;
    style.PopupBorderSize = 1;

    style.FramePadding = {16, 16};

    style.FrameRounding = 12;
    style.PopupRounding = 12;
    style.ScrollbarRounding = 12;
    style.GrabRounding = 12;

    style.ScrollbarSize = 16;

    style.WindowMenuButtonPosition = ImGuiDir_Right;

    helpSetupBackends(window, "#version 330");

    return (void *)window;
}

void helpDrawGui(void *window) { drawGui((GLFWwindow *)window); }

extern int idx;
extern void *p[];

int main() {
    GLFWwindow *window = (GLFWwindow *)helpStart(1920, 1200, "Imgui", 1);

    while (!helpGlfwWindowShouldClose(window)) {
        helpFrameStart();

        helpDockSpaceOverViewport();

        helpDrawGui(window);

        helpRender();

        for (int i = 0; i < idx; i++) {
            helpSetWindowAlwaysOnTop(p[i]);
            helpSetWindowTransparent(p[i]);
            SetWindowClickThrough(p[i]);
        }

        helpViewportsEnable();

        helpFrameEnd(window);
    }

    helpCleanup(window);

    return 0;
}