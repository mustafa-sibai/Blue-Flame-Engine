#include <iostream>
#include <BF/BlueFlame.h>
#include "EditorScene.h"

#include <BF/IO/BFALoader.h>
#include "IO/FBXLoader.h"
#include "IO/BFXWriter.h"
#include "IO/BFMWriter.h"
#include "IO/BFAWriter.h"

using namespace Editor::IO;

int main()
{
	//BF::Engine engine(BF::Application::Window("Blue Flame Editor", BF::Math::Rectangle(0, 0, 1920, 1080), BF::Application::WindowStyle::Windowed), BF::Graphics::API::RenderAPI::OpenGL);

	//Editor::EditorScene scene;
	//engine.Run(scene);

	/*
	//-------------------------------------------------------------------------------------------------
	BF::Graphics::TileMapData tileMapData;
	tileMapData.textures.push_back("Assets/Textures/tilea5.png");
	tileMapData.textures.push_back("Assets/Textures/tilea1.png");
	//-----------------------------------------------------------------------

	BF::Graphics::TileData tiledata1;
	tiledata1.textureID = 0;
	tiledata1.rectangle = BF::Math::Rectangle(0, 0, 32, 32);
	tiledata1.scissorRectangle = BF::Math::Rectangle(0, 0, 32, 32);

	BF::Graphics::TileData tiledata2;
	tiledata2.textureID = 1;
	tiledata2.rectangle = BF::Math::Rectangle(0, 32, 32, 32);
	tiledata2.scissorRectangle = BF::Math::Rectangle(32, 0, 32, 32);

	//-----------------------------------------------------------------------

	tileMapData.tilesData.push_back(tiledata1);
	tileMapData.tilesData.push_back(tiledata2);
	*/
	//-----------------------------------------------------------------------

	/*
	BF::Graphics::TileMapData tileMapData;
	tileMapData.textures.push_back("Assets/Textures/grass.png");
	tileMapData.textures.push_back("Assets/Textures/road.png");
	//-----------------------------------------------------------------------

	BF::Math::Vector2 pos(500, 500);
	BF::Math::Vector2 size(100, 65);

	//center
	BF::Graphics::TileData tiledata0;
	tiledata0.textureID = 0;
	tiledata0.rectangle = BF::Math::Rectangle(pos.x, pos.y, size.x, size.y);
	tiledata0.scissorRectangle = BF::Math::Rectangle(0, 0, size.x, size.y);

	//down
	BF::Graphics::TileData tiledata1;
	tiledata1.textureID = 1;
	tiledata1.rectangle = BF::Math::Rectangle(pos.x, pos.y + (size.x / 2), size.x, size.y);
	tiledata1.scissorRectangle = BF::Math::Rectangle(0, 0, size.x, size.y);

	//up
	BF::Graphics::TileData tiledata2;
	tiledata2.textureID = 1;
	tiledata2.rectangle = BF::Math::Rectangle(pos.x, pos.y - (size.x / 2), size.x, size.y);
	tiledata2.scissorRectangle = BF::Math::Rectangle(0, 0, size.x, size.y);

	//left
	BF::Graphics::TileData tiledata3;
	tiledata3.textureID = 1;
	tiledata3.rectangle = BF::Math::Rectangle(pos.x - size.x, pos.y, size.x, size.y);
	tiledata3.scissorRectangle = BF::Math::Rectangle(0, 0, size.x, size.y);

	//right
	BF::Graphics::TileData tiledata4;
	tiledata4.textureID = 1;
	tiledata4.rectangle = BF::Math::Rectangle(pos.x + size.x, pos.y, size.x, size.y);
	tiledata4.scissorRectangle = BF::Math::Rectangle(0, 0, size.x, size.y);

	//right bottom
	BF::Graphics::TileData tiledata5;
	tiledata5.textureID = 1;
	tiledata5.rectangle = BF::Math::Rectangle(pos.x + (size.x / 2), pos.y + (size.x / 4), size.x, size.y);
	tiledata5.scissorRectangle = BF::Math::Rectangle(0, 0, size.x, size.y);

	//left bottom
	BF::Graphics::TileData tiledata6;
	tiledata6.textureID = 1;
	tiledata6.rectangle = BF::Math::Rectangle(pos.x - (size.x / 2), pos.y + (size.x / 4), size.x, size.y);
	tiledata6.scissorRectangle = BF::Math::Rectangle(0, 0, size.x, size.y);

	//right top
	BF::Graphics::TileData tiledata7;
	tiledata7.textureID = 1;
	tiledata7.rectangle = BF::Math::Rectangle(pos.x + (size.x / 2), pos.y - (size.x / 4), size.x, size.y);
	tiledata7.scissorRectangle = BF::Math::Rectangle(0, 0, size.x, size.y);

	//left top
	BF::Graphics::TileData tiledata8;
	tiledata8.textureID = 1;
	tiledata8.rectangle = BF::Math::Rectangle(pos.x - (size.x / 2), pos.y - (size.x / 4), size.x, size.y);
	tiledata8.scissorRectangle = BF::Math::Rectangle(0, 0, size.x, size.y);
	*/
	//-----------------------------------------------------------------------

	//Rendering
	/*tileMapData.tilesData.push_back(tiledata2);

	tileMapData.tilesData.push_back(tiledata8);
	tileMapData.tilesData.push_back(tiledata7);

	tileMapData.tilesData.push_back(tiledata3);
	tileMapData.tilesData.push_back(tiledata0);
	tileMapData.tilesData.push_back(tiledata4);

	tileMapData.tilesData.push_back(tiledata6);
	tileMapData.tilesData.push_back(tiledata5);

	tileMapData.tilesData.push_back(tiledata1);*/
/*
	tileMapData.tilesData.push_back(tiledata0);
	tileMapData.tilesData.push_back(tiledata1);
	tileMapData.tilesData.push_back(tiledata2);
	tileMapData.tilesData.push_back(tiledata3);
	tileMapData.tilesData.push_back(tiledata4);
	tileMapData.tilesData.push_back(tiledata5);
	tileMapData.tilesData.push_back(tiledata6);
	tileMapData.tilesData.push_back(tiledata7);
	tileMapData.tilesData.push_back(tiledata8);
	
	BFMWriter writer;
	writer.WriteToFile("../Sandbox/Assets/Maps/TileMap", tileMapData);*/
	//-------------------------------------------------------------------------------------------------
	
	//-------------------------------------------------------------------------------------------------
	/*FBXLoader fbxloader;
	fbxloader.Load("../Sandbox/Assets/Models/halfTexturedCube.fbx");

	BFXWriter bfxWriter(fbxloader.GetMeshs());
	bfxWriter.WriteToFile("../Sandbox/Assets/Models/halfTexturedCube");*/

	
	FBXLoader fbxloader;
	fbxloader.Load("../Sandbox/Assets/Models/Plane.fbx");

	BFXWriter bfxWriter(fbxloader.GetMeshs());
	bfxWriter.WriteToFile("../Sandbox/Assets/Models/Plane");
	
	std::system("PAUSE");
	//-------------------------------------------------------------------------------------------------
	

	/*BF::Graphics::Animation::SpriteAnimationData spriteAnimationData;
	BF::Graphics::Animation::Sequence sequence;
	sequence.keyFrames.push_back(BF::Graphics::Animation::KeyFrame(100, BF::Math::Rectangle(0, 0, 32, 48)));
	sequence.keyFrames.push_back(BF::Graphics::Animation::KeyFrame(100, BF::Math::Rectangle(32, 0, 32, 48)));
	sequence.keyFrames.push_back(BF::Graphics::Animation::KeyFrame(100, BF::Math::Rectangle(64, 0, 32, 48)));
	sequence.keyFrames.push_back(BF::Graphics::Animation::KeyFrame(100, BF::Math::Rectangle(96, 0, 32, 48)));
	sequence.keyFrames.push_back(BF::Graphics::Animation::KeyFrame(100, BF::Math::Rectangle(128, 0, 32, 48)));
	sequence.keyFrames.push_back(BF::Graphics::Animation::KeyFrame(100, BF::Math::Rectangle(160, 0, 32, 48)));
	sequence.keyFrames.push_back(BF::Graphics::Animation::KeyFrame(100, BF::Math::Rectangle(192, 0, 32, 48)));
	sequence.keyFrames.push_back(BF::Graphics::Animation::KeyFrame(100, BF::Math::Rectangle(224, 0, 32, 48)));
	spriteAnimationData.sequences.push_back(sequence);

	spriteAnimationData.textureName = "../Sandbox/Assets/Textures/player.png";

	BFAWriter bfaWriter;
	bfaWriter.WriteToFile("../Sandbox/Assets/Animation/spriteAnimation", spriteAnimationData);*/

	//system("PAUSE");
	return 0;
}