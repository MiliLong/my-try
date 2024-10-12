#include "gui.h"

#include <cstdint>

#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>
#include <imgui.h>
#include <imgui_internal.h>
#include <windows.h>

#include <glm/geometric.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "helper.h"

// 设置窗口为分层并透明
void helpSetWindowTransparent(void *window) {
    HWND hwnd = glfwGetWin32Window((GLFWwindow *)window);
    LONG exStyle = GetWindowLong(hwnd, GWL_EXSTYLE);
    exStyle |= WS_EX_LAYERED;  // 添加分层样式
    SetWindowLong(hwnd, GWL_EXSTYLE, exStyle);

    // 设置透明度，完全透明
    SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 25, LWA_COLORKEY);
}

// 设置窗口支持点击穿透
void SetWindowClickThrough(void *window) {
    HWND hwnd = glfwGetWin32Window((GLFWwindow *)window);
    LONG exStyle = GetWindowLong(hwnd, GWL_EXSTYLE);
    exStyle |= WS_EX_TRANSPARENT | WS_EX_NOACTIVATE;  // 添加点击穿透样式
    SetWindowLong(hwnd, GWL_EXSTYLE, exStyle);
}

int idx = 0;
void *p[1000];

void drawGui(GLFWwindow *window) {
    static bool main_open = true;

    if (main_open) {
        ImGui::Begin("Demo", &main_open, ImGuiWindowFlags_NoDocking);
        ImGui::Text("hello world!");
        ImGui::Text("你好世界！");
        ImGui::Text("%.2f FPS", ImGui::GetIO().Framerate);

        static float x[3] = {1, 1, 1};

        ImGui::SliderFloat3("x", x, 0, 10);

        static float y[3] = {1, 1, 1};

        ImGui::SliderFloat3("y", y, 0, 10);

        glm::vec3 X = glm::make_vec3(x);
        glm::vec3 Y = glm::make_vec3(y);

        glm::vec3 add = X + Y;

        ImGui::Text("x + y = %.3f %.3f %.3f", add.x, add.y, add.z);

        glm::vec3 mul = glm::cross(X, Y);

        ImGui::Text("x cross y = %.3f %.3f %.3f", mul.x, mul.y, mul.z);

        ImGuiContext *g = ImGui::GetCurrentContext();

        static auto id2 = ImGui::GetWindowViewport()->ID;
        ImGui::Text("Viewport ID: %d", ImGui::GetWindowViewport()->ID);

        ImGui::Begin("one");

        static auto id1 = ImGui::GetWindowViewport()->ID;
        ImGui::Text("Viewport ID: %d", ImGui::GetWindowViewport()->ID);
        ImGui::Text("%.2f FPS", ImGui::GetIO().Framerate);
        ImGui::End();

        for (int i = 0; i < g->Viewports.size(); i++) {
            ImGuiViewportP *viewport = g->Viewports[i];
            if (viewport->PlatformHandle != nullptr && viewport->ID == id1) {
                bool exists = false;

                for (int i = 0; i < idx; i++) {
                    if (p[i] == viewport->PlatformHandle) {
                        exists = true;
                        break;
                    }
                }

                if (!exists) {
                    p[idx++] = viewport->PlatformHandle;
                }
            }
        }
        ImGui::End();

    } else {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}
