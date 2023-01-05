#ifndef ENGINE_H
#define ENGINE_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_glfw.h"

#include "ShaderProgram.h"
#include "Camera.h"

#include "Model.h"
#include "FileSystem.h"
#include "Light.h"

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
        char* glsl_version;
        char* mainWindowName;
        int mainWindowWidth;
        int mainWindowHeight;

        // scene data
        std::vector<Camera> cameraList;
        Camera* camera;
        ShaderProgram* shader;
        Model* model;
};

#endif // ENGINE_H