#version 400 core

in vec3 position;
in vec2 textureCoords;

out vec3 color;
out vec2 texCoords;

uniform mat4 transformationMatrix;
uniform mat4 projectionMatrix;

void main(void)
{
    gl_Position = projectionMatrix * transformationMatrix * vec4(position, 1.0f);
    color = vec3(1, 1, 1);
    texCoords = textureCoords;
}