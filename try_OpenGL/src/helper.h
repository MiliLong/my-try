#pragma once

void* helpGlfwCreateWindow(int width, int height, const char* title,
                           int interval);
void helpImguiInit();
void helpSetupBackends(void* window, const char* glsl_version);
void helpCleanup(void* window);
void helpFrameStart();
void helpFrameEnd(void* window);
void helpViewportsEnable();

int helpGlfwWindowShouldClose(void* window);
void helpDockSpaceOverViewport();
void helpRender();

void helpSetWindowAlwaysOnTop(void* window);

void helpGladLoadGLLoader();