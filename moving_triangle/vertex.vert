#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 Color;

out vec3 aColor;

uniform float xOffset;
uniform mat4 transform;

void main()
{
    gl_Position = transform * vec4(aPos, 1.0f); // just add a - to the y position
    aColor = Color;
}