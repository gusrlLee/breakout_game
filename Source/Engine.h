#ifndef ENGINE_H
#define ENGINE_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "ShaderProgram.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <thread>
#include <mutex>

class Engine {
    public:
        Engine(char* windowName, int width, int height);
        void init();
        void processInput(float dt);
        void Update(float dt);
        void Render();

    private:
        GLFWwindow* mainWindow;
        char* mainWindowName;
        int mainWindowWidth;
        int mainWindowHeight;


};

#endif // ENGINE_H