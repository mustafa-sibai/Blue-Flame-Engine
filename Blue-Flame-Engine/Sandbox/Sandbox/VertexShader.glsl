#version 450 core
layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec4 inColor;
layout(location = 2) in vec2 inUV;

out vec4 fragmentColor;
out vec2 UV;

layout (std140) uniform shader_data
{
	mat4 buffer_modelMatrix;
	mat4 buffer_viewMatrix;
	mat4 buffer_projectionMatrix;
	vec4 buffer_color;
};

void main()
{
	gl_Position =  /*buffer_projectionMatrix * buffer_viewMatrix * */ buffer_projectionMatrix * buffer_modelMatrix * vec4(inPosition.xyz, 1.0f);
	fragmentColor = inColor + buffer_color;
	UV = inUV;
}