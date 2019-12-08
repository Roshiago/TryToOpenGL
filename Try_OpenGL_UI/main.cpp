#include <iostream>
#include <string>

#include "Window.h"

static void error_callback(int error, const char* description)
{
    puts(description);
    std::cout << std::endl;
}

int main()
{
    glfwSetErrorCallback(error_callback);

    if (!GLFW::InitGLFW()) {
        return -1;
    }

    Window window;
    
    if (!GLEW::InitGLEW()) {
        return -1;
    }

    window.MainLoop();
    
    return 0;
};