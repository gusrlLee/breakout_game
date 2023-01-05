#ifndef CAMERA_H
#define CAMERA_H

#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include <vector>
#include <algorithm>

enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

// Default camera values
// const float YAW         = -90.0f;
// const float PITCH       =  0.0f;
// const float SPEED       =  2.5f;
// const float SENSITIVITY =  0.1f;
// const float ZOOM        =  45.0f;

class Camera 
{
    public:
        Camera(glm::vec3 position, glm::vec3 up, float yaw, float picth);
        Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);
        float Zoom;

        glm::mat4 getViewMatrix();
        void processKeyboard();
    
    private: 
        void updateCameraVectors();

        glm::vec3 Position;
        glm::vec3 Front;
        glm::vec3 Up;
        glm::vec3 Right;
        glm::vec3 WorldUp;

        // euler Angles
        float Yaw;
        float Pitch;
        // camera options
        float MovementSpeed;
        float MouseSensitivity;

};

#endif // CAMERA_H