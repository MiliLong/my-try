import sys

sys.path.append("build/Release")

import libimgui

window = libimgui.helpStart(1980, 1080, b"PyImgui", 1)

while not libimgui.helpGlfwWindowShouldClose(window):
    libimgui.helpFrameStart()
    libimgui.helpDockSpaceOverViewport()
    libimgui.helpDrawGui(window)
    libimgui.helpRender()
    libimgui.helpViewportsEnable()
    libimgui.helpFrameEnd(window)

libimgui.helpCleanup(window)
