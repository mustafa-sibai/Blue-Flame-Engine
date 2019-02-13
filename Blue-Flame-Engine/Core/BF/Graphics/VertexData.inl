struct BFE_API PVertexData
{
	BF::Math::Vector3f position;

	PVertexData() :
		position(0.0f) { }

	PVertexData(const BF::Math::Vector3f& position) :
		position(position)
	{
	}
};

struct BFE_API PUVVertexData : PVertexData
{
	BF::Math::Vector2f texcoord;

	PUVVertexData() :
		PVertexData(BF::Math::Vector3f(0.0f)),
		texcoord(0.0f) { }

	PUVVertexData(const BF::Math::Vector3f& position, const BF::Math::Vector2f& texcoord) :
		PVertexData(position),
		texcoord(texcoord)
	{
	}
};

struct BFE_API PNVertexData : PVertexData
{
	BF::Math::Vector3f normal;

	PNVertexData() :
		PVertexData(BF::Math::Vector3f(0.0f)),
		normal(0.0f) { }

	PNVertexData(const BF::Math::Vector3f& position, const BF::Math::Vector3f& normal) :
		PVertexData(position), 
		normal(normal)
	{
	}
};

struct BFE_API PUVNVertexData : PVertexData
{
	BF::Math::Vector2f texcoord;
	BF::Math::Vector3f normal;

	PUVNVertexData() :
		PVertexData(BF::Math::Vector3f(0.0f)),
		texcoord(0.0f), normal(0.0f) { }

	PUVNVertexData(const BF::Math::Vector3f& position, const BF::Math::Vector2f& texcoord, const BF::Math::Vector3f& normal) :
		PVertexData(position), 
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
		PVertexData(BF::Math::Vector3f(0.0f)),
		texcoord(0.0f), normal(0.0f), tangent(0.0f), binormal(0.0f) { }

	PUVNTBVertexData(const BF::Math::Vector3f& position, const BF::Math::Vector2f& texcoord, const BF::Math::Vector3f& normal, const BF::Math::Vector3f& tangent, const BF::Math::Vector3f& binormal) :
		PVertexData(position),
		texcoord(texcoord), normal(normal), tangent(tangent), binormal(binormal)
	{
	}
};