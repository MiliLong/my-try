#include "helper.h"

#ifndef GLAD_ONCE
#define GLAD_ONCE
#include <glad/glad.h>
#endif

#include <GLFW/glfw3.h>

#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

void* helpGlfwCreateWindow(int width, int height, const char* title,
                           int interval) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    GLFWwindow* window =
        glfwCreateWindow(width, height, title, nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(interval);
    return (void*)window;
}

void helpImguiInit() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;
}

void helpSetupBackends(void* window, const char* glsl_version) {
    ImGui_ImplGlfw_InitForOpenGL((GLFWwindow*)window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
};

void helpCleanup(void* window) {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow((GLFWwindow*)window);
    glfwTerminate();
}

void helpFrameStart() {
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void helpFrameEnd(void* window) {
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwPollEvents();
    glfwSwapBuffers((GLFWwindow*)window);
}

void helpViewportsEnable() {
    if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
        GLFWwindow* backup_current_context = glfwGetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glfwMakeContextCurrent(backup_current_context);
    }
}

int helpGlfwWindowShouldClose(void* window) {
    return glfwWindowShouldClose((GLFWwindow*)window);
}

void helpDockSpaceOverViewport() { ImGui::DockSpaceOverViewport(); }

void helpRender() { ImGui::Render(); }

void helpSetWindowAlwaysOnTop(void* window) {
    HWND hwnd = glfwGetWin32Window((GLFWwindow*)window);
    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0,
                 SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
}

void helpGladLoadGLLoader() {
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}