#include <iostream>
#include "FBXLoader.h"
#include "BFXWriter.h"

int main()
{
	FBXLoader fbxloader;
	fbxloader.Load("../Sandbox/Assets/Models/crytek-sponza/sponza.fbx");

	BFXWriter bfxWriter(fbxloader.GetMeshs());
	bfxWriter.WriteToFile("untitled");

	system("PAUSE");
	return 0;
}