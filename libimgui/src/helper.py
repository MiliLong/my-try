import ctypes

helper = ctypes.CDLL('../build/libimgui.dll')

helper.helpStart.argtypes = [ctypes.c_int32, ctypes.c_int32, ctypes.c_char_p, ctypes.c_int32]
helper.helpStart.restype = ctypes.c_void_p

helper.helpGlfwWindowShouldClose.argtypes = [ctypes.c_void_p]
helper.helpGlfwWindowShouldClose.restype = ctypes.c_int32

helper.helpFrameEnd.argtypes = [ctypes.c_void_p]

helper.helpCleanup.argtypes = [ctypes.c_void_p]

helper.helpDrawGui.argtypes = [ctypes.c_void_p]