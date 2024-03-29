#version 330 core

out vec4 outColour;
in  vec2 passTextureCoord;

uniform sampler2D texSampler;

void main()
{
    outColour = texture(texSampler, passTextureCoord);
}