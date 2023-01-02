#include "Engine.h"

Engine::Engine(char* windowName, int width, int height)  
{
    mainWindowName = windowName;
    mainWindowWidth = width;
    mainWindowHeight = height;
}



void Engine::init() 
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__ // for APPLE 
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // make mainwindow
    mainWindow = glfwCreateWindow(mainWindowWidth, mainWindowHeight, mainWindowName, NULL, NULL);
    if (mainWindow == NULL) 
    {
        std::cout << "[SYSTEM]::[ERROR] Cannot create GLFW window, try check again." << std::endl;
        glfwTerminate();
        exit(-1);
    }
    glfwMakeContextCurrent(mainWindow);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
    {
        std::cout << "[SYSTEM]::[ERROR] Failed to initialization GLAD." << std::endl;
        exit(-1);
    }
} 

void Engine::Update(float dt) 
{

}

void Engine::processInput(float dt)
{

}

void Engine::Render() 
{
    while (!glfwWindowShouldClose(mainWindow))
    {
        // input
        // -----
        if(glfwGetKey(mainWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(mainWindow, true);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(mainWindow);
        glfwPollEvents();
    }

    glfwTerminate();
}