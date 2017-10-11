struct BF_API PVertexData
{
	Math::Vector3 position;

	PVertexData() :
		position(0) { }

	PVertexData(Math::Vector3 position) :
		position(position)
	{
	}
};

struct BF_API PUVVertexData
{
	Math::Vector3 position;
	Math::Vector2 texcoord;

	PUVVertexData() :
		position(0), texcoord(0) { }

	PUVVertexData(Math::Vector3 position, Math::Vector2 texcoord) :
		position(position), texcoord(texcoord)
	{
	}
};

struct BF_API PNVertexData
{
	Math::Vector3 position;
	Math::Vector3 normal;

	PNVertexData() :
		position(0), normal(0) { }

	PNVertexData(Math::Vector3 position, Math::Vector3 normal) :
		position(position), normal(normal)
	{
	}
};

struct BF_API PUVNVertexData
{
	Math::Vector3 position;
	Math::Vector2 texcoord;
	Math::Vector3 normal;

	PUVNVertexData() :
		position(0), texcoord(0), normal(0) { }

	PUVNVertexData(Math::Vector3 position, Math::Vector2 texcoord, Math::Vector3 normal) :
		position(position), texcoord(texcoord), normal(normal)
	{
	}
};

struct BF_API PUVNTBVertexData
{
	Math::Vector3 position;
	Math::Vector2 texcoord;
	Math::Vector3 normal;
	Math::Vector3 tangent;
	Math::Vector3 binormal;

	PUVNTBVertexData() :
		position(0), texcoord(0), normal(0), tangent(0), binormal(0) { }

	PUVNTBVertexData(Math::Vector3 position, Math::Vector2 texcoord, Math::Vector3 normal, Math::Vector3 tangent, Math::Vector3 binormal) :
		position(position), texcoord(texcoord), normal(normal), tangent(tangent), binormal(binormal)
	{
	}
};