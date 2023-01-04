#ifndef LIGHT_H
#define LIGHT_H

#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Light 
{
    public:
        Light();

    private:
        void updateLightPosition();
        glm::vec3 position;
        glm::vec3 intensity;
};


#endif 