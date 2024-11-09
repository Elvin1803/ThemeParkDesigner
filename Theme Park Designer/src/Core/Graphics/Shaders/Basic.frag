R""(#version 330 core

in vec3 outNorm;
in vec2 outUVCoords;

out vec4 FragColor;

void main()
{
    FragColor = vec4(outUVCoords, 1.0f, 1.0f);
}
)""