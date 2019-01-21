struct BFE_API PVertexData
{
	int materialIndex;
	BF::Math::Vector3f position;

	PVertexData() :
		materialIndex(0), position(0.0f) { }

	PVertexData(int materialIndex, BF::Math::Vector3f position) :
		materialIndex(materialIndex), position(position)
	{
	}
};

struct BFE_API PUVVertexData : PVertexData
{
	BF::Math::Vector2f texcoord;

	PUVVertexData() :
		PVertexData(0, BF::Math::Vector3f(0.0f)),
		texcoord(0.0f) { }

	PUVVertexData(int materialIndex, const BF::Math::Vector3f& position, const BF::Math::Vector2f& texcoord) :
		PVertexData(materialIndex, position),
		texcoord(texcoord)
	{
	}
};

struct BFE_API PNVertexData : PVertexData
{
	BF::Math::Vector3f normal;

	PNVertexData() :
		PVertexData(0, BF::Math::Vector3f(0.0f)),
		normal(0.0f) { }

	PNVertexData(int materialIndex, const BF::Math::Vector3f& position, const BF::Math::Vector3f& normal) :
		PVertexData(materialIndex, position), 
		normal(normal)
	{
	}
};

struct BFE_API PUVNVertexData : PVertexData
{
	BF::Math::Vector2f texcoord;
	BF::Math::Vector3f normal;

	PUVNVertexData() :
		PVertexData(0, BF::Math::Vector3f(0.0f)),
		texcoord(0.0f), normal(0.0f) { }

	PUVNVertexData(int materialIndex, const BF::Math::Vector3f& position, const BF::Math::Vector2f& texcoord, const BF::Math::Vector3f& normal) :
		PVertexData(materialIndex, position), 
		texcoord(texcoord), normal(normal)
	{
	}
};

struct BFE_API PUVNTBVertexData : PVertexData
{
	BF::Math::Vector2f texcoord;
	BF::Math::Vector3f normal;
	BF::Math::Vector3f tangent;
	BF::Math::Vector3f binormal;

	PUVNTBVertexData() :
		PVertexData(0, BF::Math::Vector3f(0.0f)),
		texcoord(0.0f), normal(0.0f), tangent(0.0f), binormal(0.0f) { }

	PUVNTBVertexData(int materialIndex, const BF::Math::Vector3f& position, const BF::Math::Vector2f& texcoord, const BF::Math::Vector3f& normal, const BF::Math::Vector3f& tangent, const BF::Math::Vector3f& binormal) :
		PVertexData(materialIndex, position),
		texcoord(texcoord), normal(normal), tangent(tangent), binormal(binormal)
	{
	}
};