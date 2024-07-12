#version 400 core

in vec3 color;
in vec2 texCoords;

out vec4 outColor;

uniform sampler2D outTexture;

void main(void)
{
    //outColor = vec4(color, 1.0);
    outColor = texture(outTexture, texCoords);
}