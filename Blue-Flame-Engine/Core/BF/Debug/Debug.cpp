#include "Debug.h"
#include "BF/Engine.h"

#define BFE_MAX_SPRITES     300000
#define BFE_SPRITE_VERTICES 4
#define	BFE_SPRITE_INDICES  6
#define BFE_VERTICES_SIZE	BFE_MAX_SPRITES * BFE_SPRITE_VERTICES
#define BFE_INDICES_SIZE	BFE_MAX_SPRITES * BFE_SPRITE_INDICES

namespace BF
{
	namespace Debugging
	{
		using namespace std;
		using namespace BF::Math;
		using namespace BF::Application;
		using namespace BF::Graphics;
		using namespace BF::Graphics::API;

		Shader Debug::shader;
		VertexBuffer Debug::vertexBuffer;
		IndexBuffer Debug::indexBuffer;
		VertexBufferLayout Debug::vertexBufferLayout;

		Debug::Vertex* Debug::vertexData = nullptr;
		unsigned int* Debug::indexData = nullptr;
		unsigned int Debug::currentIndex = 0;
		unsigned int Debug::indicesCount = 0;

		vector<Debug::Renderable*> Debug::renderable;

		vector<Vector2i> Debug::corners;

		void Debug::Initialize()
		{
			BF::Engine::GetContext().SetPrimitiveType(PrimitiveType::Triangles);

			shader.LoadStandardShader(ShaderType::Debug);

			vertexBufferLayout.Push(0, "POSITION", VertexBufferLayout::DataType::Float2, sizeof(Vertex), 0);
			vertexBufferLayout.Push(1, "COLOR", VertexBufferLayout::DataType::Float4, sizeof(Vertex), sizeof(Vector2f));

			vertexBuffer.Create();
			indexBuffer.Create();

			vertexBuffer.SetBuffer(BFE_VERTICES_SIZE * sizeof(Vertex), nullptr, BufferMode::DynamicDraw);
			indexBuffer.SetBuffer(nullptr, BFE_INDICES_SIZE, BufferMode::DynamicDraw);

			vertexBuffer.SetLayout(shader, &vertexBufferLayout);

			Engine::GetContext().EnableDepthBuffer(false);
			Engine::GetContext().EnableBlending(true);
			Engine::GetContext().EnableScissor(true);
		}

		void Debug::DrawLine(const Vector2f& startPosition, const Vector2f& endPosition, float thickness, const Color& color)
		{
			renderable.emplace_back(new Line(startPosition, endPosition, thickness, color));
		}

		void Debug::DrawRectangle(const Vector2f& position, const Vector2f& size, const Vector2f& pivot, const Color& color)
		{
			renderable.emplace_back(new Rectangle(position, size, pivot, color));
		}

		void Debug::DrawRegularPolygon(const Vector2f& position, float radius, int triangleCount, const Color& color)
		{
			renderable.emplace_back(new RegularPolygon(position, radius, triangleCount, color));
		}

		void Debug::MapLine(Line& line)
		{
			/*
			Winding order is clock-wise.
			0 -> 1 -> 2 ---> 2 -> 3 -> 0

				0      1
				 ______
				|\     |
				| \    |
				|  \   |
				|   \  |
				|    \ |
				|_____\|
				3      2
			*/
			/*int startingIndex = 0;

			Vector2f normal = Vector2f(line.endPosition.y - line.startPosition.y, line.endPosition.x - line.startPosition.x).Normalize() * line.thickness;

			startingIndex = currentIndex;

			*indexData = startingIndex;
			indexData++;

			*indexData = currentIndex + 1;
			indexData++;

			*indexData = currentIndex + 2;
			indexData++;


			*indexData = currentIndex + 2;
			indexData++;

			*indexData = currentIndex + 3;
			indexData++;

			*indexData = startingIndex;
			indexData++;

			currentIndex += 4;
			indicesCount += 6;

			//Top Left
			vertexData->position = line.startPosition;
			vertexData->color = line.color;
			vertexData++;

			//Top Right
			vertexData->position = Vector2f(line.startPosition.x - normal.x, line.startPosition.y + normal.y);
			vertexData->color = line.color;
			vertexData++;

			//Bottom Right
			vertexData->position = Vector2f(line.endPosition.x - normal.x, line.endPosition.y + normal.y);
			vertexData->color = line.color;
			vertexData++;

			//Bottom Left
			vertexData->position = Vector2f(line.endPosition.x, line.endPosition.y);
			vertexData->color = line.color;
			vertexData++;*/
		}

		void Debug::MapRectangle(Rectangle& rectangle)
		{
			/*
			Winding order is clock-wise.
			0 -> 1 -> 2 ---> 2 -> 3 -> 0

				0      1
				 ______
				|\     |
				| \    |
				|  \   |
				|   \  |
				|    \ |
				|_____\|
				3      2
			*/
			/*int startingIndex = 0;

			startingIndex = currentIndex;

			*indexData = startingIndex;
			indexData++;

			*indexData = currentIndex + 1;
			indexData++;

			*indexData = currentIndex + 2;
			indexData++;


			*indexData = currentIndex + 2;
			indexData++;

			*indexData = currentIndex + 3;
			indexData++;

			*indexData = startingIndex;
			indexData++;

			currentIndex += 4;
			indicesCount += 6;

			/*
			x = left position
			y = top position
			width = right position
			hgiht = bottom position

			   x, y      width, y
				 ----------
				 |        |
				 | sprite |
				 |        |
				 ---------- width, height
			  x, height

			  if we have an odd number of pixels and we want to center the image in the middle of the screen
			  the extra pixels will always be at the bottom right.
			  Meaning more of the image will be on the bottom right side rather than top left side.

			  --------------------
			  |       Screen     |
			  |                  |
			  |     -----------  |
			  |     |---------|  |
			  |     |--image--|  |
			  |     -----------  |
			  --------------------

			  as you can see, the image is close to the bottom right of the screen.
			*/
			/*corners = BF::Math::Rectangle(rectangle.position.x, rectangle.position.y, rectangle.size.x, rectangle.size.y, rectangle.pivot).GetCorners();

			//Top Left
			vertexData->position = Vector2f(corners[0].x, corners[0].y);
			vertexData->color = rectangle.color;
			vertexData++;

			//Top Right
			vertexData->position = Vector2f(corners[1].x, corners[1].y);
			vertexData->color = rectangle.color;
			vertexData++;

			//Bottom Right
			vertexData->position = Vector2f(corners[2].x, corners[2].y);
			vertexData->color = rectangle.color;
			vertexData++;

			//Bottom Left
			vertexData->position = Vector2f(corners[3].x, corners[3].y);
			vertexData->color = rectangle.color;
			vertexData++;*/
		}

		void Debug::MapRegularPolygon(RegularPolygon& regularPolygon)
		{
			/*int startingIndex = 0;
			float angle = 0;
			float distanceBetweenTris = 0;
			Vector2f vertexPosition;

			startingIndex = currentIndex;

			*indexData = currentIndex;
			indexData++;
			currentIndex++;
			indicesCount++;

			for (int i = 0; i < regularPolygon.triangleCount - 1; i++)
			{
				*indexData = currentIndex;
				indexData++;
				currentIndex++;
				indicesCount++;

				*indexData = currentIndex;
				indexData++;
				indicesCount++;

				*indexData = startingIndex;
				indexData++;
				indicesCount++;

				if (i >= regularPolygon.triangleCount - 2)
				{
					*indexData = currentIndex;
					indexData++;
					indicesCount++;

					*indexData = startingIndex + 1;
					indexData++;
					currentIndex++;
					indicesCount++;
				}
			}

			/*
						v1
					   /|\
					  /	| \
					 /	|  \
					/	|   \
				   /	|    \
				  /		|     \
				 /	    |      \
				/		|       \
			   /		| 90     \
			  /		    |----     \
		   v4/__________|v0_|______\v2
			 \			|          /
			  \			|         /
			   \		|        /
				\		|       /
				 \		|      /
				  \	    |     /
				   \	|	 /
					\	|	/
					 \	|  /
					  \ | /
					   \|/
						v3
			*/

			/*vertexData->position = regularPolygon.position;
			vertexData->color = regularPolygon.color;
			vertexData++;

			angle = 90.0f;

			distanceBetweenTris = (360.0f / (float)regularPolygon.triangleCount);

			for (int i = 0; i < regularPolygon.triangleCount; i++)
			{
				vertexData->position = Vector2f(regularPolygon.position.x + regularPolygon.radius * -cos(Math::ToRadians(angle)), regularPolygon.position.y + regularPolygon.radius * sin(Math::ToRadians(angle)));
				vertexData->color = regularPolygon.color;
				vertexData++;

				angle += distanceBetweenTris;
			}*/
		}

		void Debug::Render()
		{
			vertexData = (Vertex*)vertexBuffer.Map();
			indexData = (unsigned int*)indexBuffer.Map();

			for (size_t i = 0; i < renderable.size(); i++)
			{
				switch (renderable[i]->type)
				{
				case Renderable::Type::Line:
				{
					MapLine(*((Line*)renderable[i]));
					delete renderable[i];
					break;
				}
				case Renderable::Type::Rectangle:
				{
					MapRectangle(*((Rectangle*)renderable[i]));
					//delete renderable[i];
					break;
				}
				case Renderable::Type::RegularPolygon:
				{
					MapRegularPolygon(*((RegularPolygon*)renderable[i]));
					delete renderable[i];
					break;
				}
				default:
					break;
				}
			}

			indexBuffer.Unmap();
			vertexBuffer.Unmap();

			if (indicesCount > 0)
			{
				shader.Bind();

				vertexBuffer.Bind();
				indexBuffer.Bind();
				Engine::GetContext().Draw(indicesCount);
				indexBuffer.Unbind();
				vertexBuffer.Unbind();

				//renderable.clear();

				currentIndex = 0;
				indicesCount = 0;

				vertexData = nullptr;
			}
		}
	}
}