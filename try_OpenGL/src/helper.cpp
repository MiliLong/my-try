#ifndef HEAD
#include "glad/glad.h"
#endif
#include "helper.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

GLFWwindow* helpGlfwCreateWindow(int width, int height, const char* title,
                                 int interval) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    GLFWwindow* window =
        glfwCreateWindow(width, height, title, nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(interval);
    return window;
}

void helpGladLoadGLLoader() {
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}

void helpImguiInit() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;
}

void helpSetupBackends(GLFWwindow* window, const char* glsl_version) {
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
};

void helpCleanup(GLFWwindow* window) {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
}

void helpFrameStart() {
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void helpFrameEnd(GLFWwindow* window) {
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwPollEvents();
    glfwSwapBuffers(window);
}

void helpViewportsEnable() {
    if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
        GLFWwindow* backup_current_context = glfwGetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glfwMakeContextCurrent(backup_current_context);
    }
}