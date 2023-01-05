#include "Camera.h"

const static float SPEED       =  2.5f;
const static float SENSITIVITY =  0.1f;
const static float ZOOM        =  45.0f;

// constructor with vectors
Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
{
    Position = position;
    WorldUp = up;
    Yaw = yaw;
    Pitch = pitch;
    MouseSensitivity = SENSITIVITY;
    MovementSpeed = SPEED;
    Zoom = ZOOM;
    updateCameraVectors();
}

// constructor with scalar values
Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch)
{
    Position = glm::vec3(posX, posY, posZ);
    WorldUp = glm::vec3(upX, upY, upZ);
    Yaw = yaw;
    Pitch = pitch;
    MouseSensitivity = SENSITIVITY;
    MovementSpeed = SPEED;
    Zoom = ZOOM;
    updateCameraVectors();
}

glm::mat4 Camera::getViewMatrix() 
{
    return glm::lookAt(Position, Position + Front, Up);
}

void Camera::updateCameraVectors() 
{
    // calculate the new Front vector
    glm::vec3 front;
    front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    Front = glm::normalize(front);
    // also re-calculate the Right and Up vector
    Right = glm::normalize(glm::cross(Front, WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    Up    = glm::normalize(glm::cross(Right, Front));
}


