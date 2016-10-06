attribute vec3 inPosition;
attribute vec4 inColor;

varying vec4 fragmentColor;

void main()
{
	gl_Position = vec4(inPosition.xyz, 1.0);
	fragmentColor = inColor;
}