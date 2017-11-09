struct BF_API PVertexData
{
	Math::Vector3f position;

	PVertexData() :
		position(0.0f) { }

	PVertexData(Math::Vector3f position) :
		position(position)
	{
	}
};

struct BF_API PUVVertexData
{
	Math::Vector3f position;
	Math::Vector2f texcoord;

	PUVVertexData() :
		position(0.0f), texcoord(0.0f) { }

	PUVVertexData(const Math::Vector3f& position, const Math::Vector2f& texcoord) :
		position(position), texcoord(texcoord)
	{
	}
};

struct BF_API PNVertexData
{
	Math::Vector3f position;
	Math::Vector3f normal;

	PNVertexData() :
		position(0.0f), normal(0.0f) { }

	PNVertexData(const Math::Vector3f& position, const Math::Vector3f& normal) :
		position(position), normal(normal)
	{
	}
};

struct BF_API PUVNVertexData
{
	Math::Vector3f position;
	Math::Vector2f texcoord;
	Math::Vector3f normal;

	PUVNVertexData() :
		position(0.0f), texcoord(0.0f), normal(0.0f) { }

	PUVNVertexData(const Math::Vector3f& position, const Math::Vector2f& texcoord, const Math::Vector3f& normal) :
		position(position), texcoord(texcoord), normal(normal)
	{
	}
};

struct BF_API PUVNTBVertexData
{
	Math::Vector3f position;
	Math::Vector2f texcoord;
	Math::Vector3f normal;
	Math::Vector3f tangent;
	Math::Vector3f binormal;

	PUVNTBVertexData() :
		position(0.0f), texcoord(0.0f), normal(0.0f), tangent(0.0f), binormal(0.0f) { }

	PUVNTBVertexData(const Math::Vector3f& position, const Math::Vector2f& texcoord, const Math::Vector3f& normal, const Math::Vector3f& tangent, const Math::Vector3f& binormal) :
		position(position), texcoord(texcoord), normal(normal), tangent(tangent), binormal(binormal)
	{
	}
};