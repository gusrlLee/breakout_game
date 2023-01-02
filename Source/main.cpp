#include "Engine.h"

#include <iostream>
#define SCR_WIDTH 1280
#define SCR_HEIGHT 720

int main()
{
    Engine engine("gemgemEngine", SCR_WIDTH, SCR_HEIGHT);
    engine.init();
    std::cout << "[SYSTEM]::INFO SUCCESS Initialization." << std::endl;
    engine.Render(); 
    return 0; 
}
