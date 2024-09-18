#include "gui.h"

#include "imgui.h"

void drawGui() {
    ImGui::Begin("Demo");
    ImGui::Text("hello world!\n");
    ImGui::Text("你好世界！\n");
    ImGui::End();
}