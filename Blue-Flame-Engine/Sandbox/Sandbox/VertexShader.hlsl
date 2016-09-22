cbuffer shader_data
{
	float4x4 buffer_modelMatrix;
	float4 buffer_color;
};

struct VOut
{
	float4 position : SV_POSITION;
	float4 color : COLOR;
};

VOut main(float4 position : POSITION, float4 color : COLOR)
{
	VOut output;

	output.position = mul(buffer_modelMatrix, position);
	output.color = color + buffer_color;

	return output;
}