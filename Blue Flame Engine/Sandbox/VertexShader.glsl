#version 450 core
layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inColor;

out vec3 fragmentColor;

layout (std140) uniform shader_data
{
	mat4 buffer_modelMatrix;
	vec4 buffer_color;
};

void main()
{
	gl_Position = buffer_modelMatrix * vec4(inPosition.xyz, 1.0f);
	fragmentColor = inColor + buffer_color.xyz;
}