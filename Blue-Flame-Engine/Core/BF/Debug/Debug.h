#pragma once
#include "BF/Graphics/API/VertexBuffer.h"
#include "BF/Graphics/API/IndexBuffer.h"
#include "BF/Graphics/Color.h"
#include "BF/Math/Vector2.h"
#include "BF/Common.h"

namespace BF
{
	namespace Debugging
	{
		class BFE_API Debug
		{
		private:
			struct Vertex
			{
				BF::Math::Vector2f position;
				BF::Graphics::Color color;

				Vertex(const BF::Math::Vector2f& position, const BF::Graphics::Color& color) :
					position(position), color(color)
				{
				}
			};

			struct Renderable
			{
				enum class Type { Line, Rectangle, RegularPolygon };
				Type type;

				Renderable(Type type) :
					type(type)
				{
				}
			};

			struct Line : public Renderable
			{
				BF::Math::Vector2f startPosition;
				BF::Math::Vector2f endPosition;
				float thickness;
				BF::Graphics::Color color;

				Line(const BF::Math::Vector2f& startPosition, const BF::Math::Vector2f& endPosition, float thickness, const BF::Graphics::Color& color) :
					Renderable(Renderable::Type::Line), 
					startPosition(startPosition), endPosition(endPosition), thickness(thickness), color(color)
				{
				}
			};

			struct Rectangle : public Renderable
			{
				BF::Math::Vector2f position;
				BF::Math::Vector2f size;
				BF::Math::Vector2f pivot;
				BF::Graphics::Color color;

				Rectangle(const BF::Math::Vector2f& position, const BF::Math::Vector2f& size, const BF::Math::Vector2f& pivot, const BF::Graphics::Color& color) :
					Renderable(Renderable::Type::Rectangle),
					position(position), size(size), pivot(pivot), color(color)
				{
				}
			};

			struct RegularPolygon : public Renderable
			{
				BF::Math::Vector2f position;
				float radius;
				int triangleCount;
				BF::Graphics::Color color;

				RegularPolygon(const BF::Math::Vector2f& position, float radius, float triangleCount, const BF::Graphics::Color& color) :
					Renderable(Renderable::Type::RegularPolygon),
					position(position), radius(radius), triangleCount(triangleCount), color(color)
				{
				}
			};

			static BF::Graphics::API::Shader shader;
			static BF::Graphics::API::VertexBuffer vertexBuffer;
			static BF::Graphics::API::IndexBuffer indexBuffer;
			static BF::Graphics::API::VertexBufferLayout vertexBufferLayout;

			static Vertex* vertexData;
			static unsigned int* indexData;
			static unsigned int currentIndex;
			static unsigned int indicesCount;

			static std::vector<Renderable*> renderable;

			//static std::vector<BF::Math::Vector2i> corners;
			//static BF::Math::Rectangle corners;

		public:
			static void Initialize();
			static void Render();

			static void DrawLine(const BF::Math::Vector2f& startPosition, const BF::Math::Vector2f& endPosition, float thickness, const BF::Graphics::Color& color);
			static void DrawRectangle(const BF::Math::Vector2f& position, const BF::Math::Vector2f& size, const BF::Math::Vector2f& pivot, const BF::Graphics::Color& color);
			static void DrawRegularPolygon(const BF::Math::Vector2f& position, float radius, int triangleCount, const BF::Graphics::Color& color);

		private:
			static void MapLine(Line& line);
			static void MapRectangle(Rectangle& rectangle);
			static void MapRegularPolygon(RegularPolygon& regularPolygon);
		};
	}
}