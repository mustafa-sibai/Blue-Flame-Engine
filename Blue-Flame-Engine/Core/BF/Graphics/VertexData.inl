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

struct BFE_API PUVVertexData
{
	BF::Math::Vector3f position;
	BF::Math::Vector2f texcoord;

	PUVVertexData() :
		position(0.0f), texcoord(0.0f) { }

	PUVVertexData(const BF::Math::Vector3f& position, const BF::Math::Vector2f& texcoord) :
		position(position), texcoord(texcoord)
	{
	}
};

struct BFE_API PNVertexData
{
	BF::Math::Vector3f position;
	BF::Math::Vector3f normal;

	PNVertexData() :
		position(0.0f), normal(0.0f) { }

	PNVertexData(const BF::Math::Vector3f& position, const BF::Math::Vector3f& normal) :
		position(position), normal(normal)
	{
	}
};

struct BFE_API PUVNVertexData
{
	BF::Math::Vector3f position;
	BF::Math::Vector2f texcoord;
	BF::Math::Vector3f normal;

	PUVNVertexData() :
		position(0.0f), texcoord(0.0f), normal(0.0f) { }

	PUVNVertexData(const BF::Math::Vector3f& position, const BF::Math::Vector2f& texcoord, const BF::Math::Vector3f& normal) :
		position(position), texcoord(texcoord), normal(normal)
	{
	}
};

struct BFE_API PUVNTBVertexData
{
	BF::Math::Vector3f position;
	BF::Math::Vector2f texcoord;
	BF::Math::Vector3f normal;
	BF::Math::Vector3f tangent;
	BF::Math::Vector3f binormal;

	PUVNTBVertexData() :
		position(0.0f), texcoord(0.0f), normal(0.0f), tangent(0.0f), binormal(0.0f) { }

	PUVNTBVertexData(const BF::Math::Vector3f& position, const BF::Math::Vector2f& texcoord, const BF::Math::Vector3f& normal, const BF::Math::Vector3f& tangent, const BF::Math::Vector3f& binormal) :
		position(position), texcoord(texcoord), normal(normal), tangent(tangent), binormal(binormal)
	{
	}
};