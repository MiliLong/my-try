#ifndef HEAD
#include "glad/glad.h"
#endif
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "gui.h"
#include "imgui.h"

void drawGui() {
    ImGui::Begin("OpenGL Square");

    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    ImVec2 p = ImGui::GetCursorScreenPos();
    float width = ImGui::GetContentRegionAvail().x;
    float height = ImGui::GetContentRegionAvail().y;

    ImVec2 top_left = ImVec2(p.x + 50, p.y + 50);
    ImVec2 bottom_right = ImVec2(top_left.x + 200, top_left.y + 200);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(top_left.x, top_left.y, 0.0f));
    model = glm::scale(model, glm::vec3(bottom_right.x - top_left.x,
                                        bottom_right.y - top_left.y, 1.0f));

    glEnable(GL_SCISSOR_TEST);
    glScissor((GLint)top_left.x, (GLint)(height - bottom_right.y),
              (GLint)(bottom_right.x - top_left.x),
              (GLint)(bottom_right.y - top_left.y));
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_SCISSOR_TEST);

    draw_list->AddRectFilled(top_left, bottom_right, IM_COL32(255, 0, 0, 255));

    ImGui::Text("This is an example of rendering a square.");
    ImGui::End();
}