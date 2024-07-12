#version 400 core

in vec3 position;
in vec2 textureCoords;

out vec3 color;
out vec2 texCoords;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 transformationMatrix;

void main(void)
{
    gl_Position = projectionMatrix * viewMatrix * transformationMatrix * vec4(position, 1.0f);
    color = vec3(1, 1, 1);
    texCoords = textureCoords;
}