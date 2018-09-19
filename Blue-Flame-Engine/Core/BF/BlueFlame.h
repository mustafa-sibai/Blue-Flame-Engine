#pragma once
#if defined (BF_PLATFORM_WINDOWS)
#include <BF/Network/Server.h>
#include <BF/Network/Client.h>
#endif

#include <BF/Engine.h>

#include <BF/Application/Window.h>
#include <BF/Application/Scene.h>
//#include <BF/Application/SceneManager.h>
#include <BF/Application/App.h>

#include <BF/AI/Waypoint.h>

#if defined (BF_PLATFORM_WINDOWS)
#include <BF/Audio/Sound.h>
#include <BF/Audio/SoundManager.h>
#endif

#include <BF/Graphics/API/Context.h>
#include <BF/Graphics/API/Shader.h>
#include <BF/Graphics/API/Texture2D.h>
#include <BF/Graphics/API/VertexBuffer.h>
#include <BF/Graphics/API/RenderTarget.h>

#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB)
#include <BF/Graphics/API/VertexBufferLayout.h>
#endif

#include <BF/Graphics/API/IndexBuffer.h>
#include <BF/Graphics/API/ConstantBuffer.h>

#include <BF/Graphics/Renderers/SpriteRenderer/SpriteRenderer.h>

#include <BF/Graphics/Fonts/FontAtlas.h>

#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB)
#include <BF/Graphics/Fonts/Font.h>
#endif

#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_WEB)
//#include <BF/Graphics/GUI/StyleSheet.h>
/*#include <BF/Graphics/GUI/Label.h>
#include <BF/Graphics/GUI/Button.h>
#include <BF/Graphics/GUI/MenuStrip/MenuStrip.h>
#include <BF/Graphics/GUI/Checkbox.h>
#include <BF/Graphics/GUI/Panel.h>*/
#endif

#include <BF/Graphics/Animation/SpriteAnimation.h>

#include <BF/Graphics/FPSCamera.h>
#include <BF/Graphics/TileMap.h>
#include <BF/Graphics/Skybox.h>
#include <BF/Graphics/Terrain.h>

#include <BF/Graphics/Materials/MeshMaterial.h>
#include <BF/Graphics/Light.h>

#include <BF/Graphics/Transform.h>

#if defined (BF_PLATFORM_WINDOWS)
#include <BF/Input/Controller.h>
#endif
#include <BF/Input/Keyboard.h>
#include <BF/Input/Mouse.h>

#include <BF/Math/Math.h>

#include <BF/Physics/PhysicsEngine.h>

#include <BF/IO/BFXLoader.h>

#include <BF/System/Debug.h>
#include <BF/System/Timer.h>
#include <BF/System/Random.h>