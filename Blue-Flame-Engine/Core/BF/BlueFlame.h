#pragma once
#include <BF/Engine.h>

#include <BF/Application/Window.h>
#include <BF/Application/Scene.h>
#include <BF/Application/SceneManager.h>

#include <BF/AI/Waypoint.h>

#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
#include <BF/Audio/Sound.h>
#include <BF/Audio/SoundManager.h>
#endif

#include <BF/Graphics/API/Context.h>
#include <BF/Graphics/API/Shader.h>
#include <BF/Graphics/API/Texture2D.h>
#include <BF/Graphics/API/VertexBuffer.h>
#include <BF/Graphics/API/RenderTarget.h>

#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
#include <BF/Graphics/API/VertexBufferLayout.h>
#endif

#include <BF/Graphics/API/IndexBuffer.h>
#include <BF/Graphics/API/ConstentBuffer.h>

#include <BF/Graphics/Renderers/SpriteRenderer.h>

#include <BF/Graphics/Fonts/FontAtlas.h>

#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
#include <BF/Graphics/Fonts/Font.h>

#include <BF/Graphics/GUI/StyleSheet.h>
#include <BF/Graphics/GUI/Button.h>
#include <BF/Graphics/GUI/Checkbox.h>
#include <BF/Graphics/GUI/Panel.h>
#endif

#include <BF/Graphics/Animation/SpriteAnimation.h>

#include <BF/Graphics/FPSCamera.h>
#include <BF/Graphics/TileMap.h>
#include <BF/Graphics/Skybox.h>
#include <BF/Graphics/Model.h>
#include <BF/Graphics/Terrain.h>

#include <BF/Graphics/Material.h>
#include <BF/Graphics/Light.h>

#include <BF/Input/Controller.h>
#include <BF/Input/Keyboard.h>
#include <BF/Input/Mouse.h>

#include <BF/Math/Math.h>

#include <BF/System/Timer.h>
#include <BF/System/Log.h>