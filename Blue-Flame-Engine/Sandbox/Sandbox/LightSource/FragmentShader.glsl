#version 450 core

in vec4 fragmentColor;
in vec2 UV;
out vec4 color;

uniform sampler2D myTextureSampler;

void main() 
{
	//color = fragmentColor;
	color = texture(myTextureSampler, UV);
}