#pragma once

#include "GLFW/glfw3.h"

GLFWwindow* helpGlfwCreateWindow(int width, int height, const char* title,
                                 int interval);
void helpGladLoadGLLoader();
void helpImguiInit();
void helpSetupBackends(GLFWwindow* window, const char* glsl_version);
void helpCleanup(GLFWwindow* window);
void helpFrameStart();
void helpFrameEnd(GLFWwindow* window);
void helpViewportsEnable();