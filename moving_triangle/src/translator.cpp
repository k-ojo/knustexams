#include "main.h"


/**
 * translate- computes the translation matrix each time
 * @x- x-coord
 * @y- y-coord
 * @z- z-coord
 * 
 * Return: maxtix (4x4)
*/
glm::mat4 translate(float x, float y, float z) {
    return glm::translate(glm::mat4(1.0f), glm::vec3(x, y, z));
}

void updatePos(float& numX, float& numY, bool& incrementingX, bool& incrementingY)
{
    // Update position along X axis
    if (incrementingX) {
        if (numX < 0.9)  
            numX += 0.009;
        else 
            incrementingX = false; 
    }
    else {
        if (numX > -0.9) 
            numX -= 0.009;
        else 
            incrementingX = true;
    }

    // Update position along Y axis
    if (incrementingY) {
        if (numY < 0.9)  
            numY += 0.015;
        else 
            incrementingY = false;
    }
    else {
        if (numY > -0.9) 
            numY -= 0.015;
        else 
            incrementingY = true;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(60));
}