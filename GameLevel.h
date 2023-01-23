#ifndef GAMELEVEL_H
#define GAMELEVEL_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <iostream>
#include <vector>

#include "GameObject.h"
#include "SpriteRenderer.h"
#include "ResourceManager.h"

class GameLevel
{
public: 

    GameLevel() { }

    std::vector<GameObject> Bricks;

    void Load(const char* file, unsigned int levelWidth, unsigned int levelHeights);

    void Draw(SpriteRenderer &renderer);

    bool IsCompleted();

private:
    void init(std::vector<std::vector<unsigned int>> tileData, unsigned int levelWidth, unsigned int levelHight);
};

#endif