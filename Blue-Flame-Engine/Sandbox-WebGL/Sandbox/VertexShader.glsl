#version 300 es
in vec3 inPosition;
in vec4 inColor;
in vec2 inUV;

out vec4 fragmentColor;
out vec2 UV;

void main()
{
	gl_Position = vec4(inPosition.xyz, 1.0);
	fragmentColor = inColor;
	UV = inUV;
}