#include <Windows.h>
#include <pybind11/pybind11.h>

#include "GLFW/glfw3.h"
#include "gui.h"
#include "helper.h"
#include "imgui.h"

void *helpStart(int width, int height, const char *title, int interval) {
    GLFWwindow *window =
        (GLFWwindow *)helpGlfwCreateWindow(width, height, title, interval);

    helpImguiInit();

    ImGuiIO &io = ImGui::GetIO();

    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    io.ConfigViewportsNoAutoMerge = true;

    io.Fonts->AddFontFromFileTTF("c:/Windows/Fonts/msyh.ttc", 36.0f, NULL,
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

PYBIND11_MODULE(libimgui, m) {
    m.def("helpStart", &helpStart);
    m.def("helpDrawGui", &helpDrawGui);
    m.def("helpGlfwCreateWindow", &helpGlfwCreateWindow);
    m.def("helpImguiInit", &helpImguiInit);
    m.def("helpSetupBackends", &helpSetupBackends);
    m.def("helpCleanup", &helpCleanup);
    m.def("helpFrameStart", &helpFrameStart);
    m.def("helpFrameEnd", &helpFrameEnd);
    m.def("helpViewportsEnable", &helpViewportsEnable);
    m.def("helpGlfwWindowShouldClose", &helpGlfwWindowShouldClose);
    m.def("helpDockSpaceOverViewport", &helpDockSpaceOverViewport);
    m.def("helpRender", &helpRender);
    m.def("helpSetWindowAlwaysOnTop", &helpSetWindowAlwaysOnTop);
}
