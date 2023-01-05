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
    glsl_version = "#version 150";
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
    glEnable(GL_DEPTH_TEST);
    camera = new Camera(glm::vec3(0.0f, 0.0f, 5.0f), glm::vec3(0.0, 1.0, 0.0), -90.0f, 0.0f); // pos, up, yaw, pitch
    model = new Model(FileSystem::getPath("../../Resource/Mesh/cube/cube.obj").c_str());
    shader = new ShaderProgram("../../Resource/Shader/v_edit_mode.glsl", "../../Resource/Shader/f_edit_mode.glsl");

} 

void Engine::Update(float dt) 
{

}

void Engine::processInput(float dt)
{

}

void Engine::Render() 
{
    // create IMGUI library
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(mainWindow, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    while (!glfwWindowShouldClose(mainWindow))
    {
        glfwPollEvents();

        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        shader->use();
        glm::mat4 projection = glm::perspective(glm::radians(camera->Zoom), (float)mainWindowWidth / (float)mainWindowHeight, 0.1f, 100.0f);
        glm::mat4 view = camera->getViewMatrix();
        shader->setMat4("projection", projection);
        shader->setMat4("view", view);
        glm::mat4 model_pos = glm::mat4(1.0f);
        shader->setMat4("model", model_pos);
        model->Draw(*shader);

        // input
        // -----
        if(glfwGetKey(mainWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(mainWindow, true);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

            ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
            ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
            ImGui::Checkbox("Another Window", &show_another_window);

            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

            if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
        }
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(mainWindow);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();
}