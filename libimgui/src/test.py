from helper import *

window = helper.helpStart(1980, 1080, b"PyImgui", 1)

while not helper.helpGlfwWindowShouldClose(window) :
    helper.helpFrameStart()
    helper.helpDockSpaceOverViewport()
    helper.helpDrawGui(window)
    helper.helpRender()
    helper.helpViewportsEnable()
    helper.helpFrameEnd(window)

helper.helpCleanup(window)