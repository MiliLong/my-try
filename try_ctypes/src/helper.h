#pragma once

#include "GLFW/glfw3.h"

extern "C" {
GLFWwindow* helpGlfwCreateWindow(int width, int height, const char* title,
                                 int interval);
void helpImguiInit();
void helpSetupBackends(GLFWwindow* window, const char* glsl_version);
void helpCleanup(GLFWwindow* window);
void helpFrameStart();
void helpFrameEnd(GLFWwindow* window);
void helpViewportsEnable();
}

extern "C" {
int helpGlfwWindowShouldClose(GLFWwindow* window);
void helpDockSpaceOverViewport();
void helpRender();
}

extern "C" {
void helpSetWindowAlwaysOnTop(GLFWwindow* window);
}