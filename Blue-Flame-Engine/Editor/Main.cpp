#include <iostream>
#include <BF/BlueFlame.h>
#include <BF/IO/BFALoader.h>
#include "FBXLoader.h"
#include "BFXWriter.h"
#include "BFMWriter.h"
#include "BFAWriter.h"

int main()
{
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

	//-----------------------------------------------------------------------
	BFMWriter writer;
	writer.WriteToFile("TileMap", tileMapData);
	//-------------------------------------------------------------------------------------------------

	//-------------------------------------------------------------------------------------------------
	FBXLoader fbxloader;
	fbxloader.Load("../Sandbox/Assets/Models/crytek-sponza/sponza.fbx");

	BFXWriter bfxWriter(fbxloader.GetMeshs());
	bfxWriter.WriteToFile("untitled");
	//-------------------------------------------------------------------------------------------------
	*/

	BF::Graphics::Animation::SpriteAnimationData spriteAnimationData;
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
	bfaWriter.WriteToFile("../Sandbox/Assets/Animation/spriteAnimation", spriteAnimationData);

	system("PAUSE");
	return 0;
}