#include "Engine.h"

using namespace BF::Graphics::API;
using namespace BF::Application;

Engine::Engine() :
	window("Blue Flame Engine", 0, 0, 400, 400, WindowStyle::Windowed),
	context(&window, RenderAPI::Default), totalTime(0), extra(0), FPS(0), FUPS(0), extraTimesToRunFixedUpdate(0), runFixedUpdate(false)
{
}

Engine::Engine(const Window& window, const Context& context) :
	window(window), context(context), totalTime(0), extra(0), FPS(0), FUPS(0), extraTimesToRunFixedUpdate(0), runFixedUpdate(false)
{
}

Engine::~Engine()
{
}

void Engine::Run()
{
	while (window.IsOpen())
	{
		window.Update();

		for (int i = 0; i < SceneManager::GetScenes().size(); i++)
		{
			if (SceneManager::GetScene(i).IsRunning())
			{
				if (!SceneManager::GetScene(i).initialized)
				{
					SceneManager::GetScene(i).SetWindow(window);
					SceneManager::GetScene(i).SetContext(context);
					SceneManager::GetScene(i).Initialize();
					SceneManager::GetScene(i).initialized = true;
				}

				if (!SceneManager::GetScene(i).loaded)
				{
					SceneManager::GetScene(i).Load();
					SceneManager::GetScene(i).loaded = true;
				}

				SceneManager::GetScene(i).frameTimer.Reset();
				if (runFixedUpdate || extraTimesToRunFixedUpdate > 0)
				{
					SceneManager::GetScene(i).FixedUpdate();
					extraTimesToRunFixedUpdate--;
					runFixedUpdate = false;
				}

				SceneManager::GetScene(i).Update();
				SceneManager::GetScene(i).Render();
				float elapsedFrameTime = SceneManager::GetScene(i).frameTimer.GetElapsedTimeInMilliseconds();

				FPS++;
				totalTime += elapsedFrameTime;

				if (totalTime >= frameTimeTarget)
				{
					extra += totalTime - frameTimeTarget;
					FUPS++;
					runFixedUpdate = true;

					if (extra >= frameTimeTarget)
					{
						extraTimesToRunFixedUpdate++;
						FUPS++;
						extra -= frameTimeTarget;
					}

					totalTime = 0;
				}

				if (SceneManager::GetScene(i).frameRateTimer.GetElapsedTimeInSeconds() >= 1.0f)
				{
					BF_INFO("frames: %d FUPS: %d", FPS, FUPS);
					SceneManager::GetScene(i).frameRateTimer.Reset();
					FPS = 0;
					FUPS = 0;
				}
			}
		}
	}
}