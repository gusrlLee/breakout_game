#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "GameLevel.h"
#include "BallObject.h"

// Represents the current state of the game
enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
}; 

// for direction.
enum Direction {
	UP,
	RIGHT,
	DOWN,
	LEFT
};    

typedef std::tuple<bool, Direction, glm::vec2> Collision;  

class Game
{
    public:
        // game state
        GameState    State;	
        bool         Keys[1024];
        unsigned int Width, Height;
        std::vector<GameLevel> Levels;
        unsigned int Level;

        // constructor/destructor
        Game(unsigned int width, unsigned int height);
        ~Game();
        // initialize game state (load all shaders/textures/levels)
        void Init();
        // game loop
        void ProcessInput(float dt);
        void Update(float dt);
        void Render();
        void DoCollisions();

        void ResetLevel();
        void ResetPlayer();
};

#endif