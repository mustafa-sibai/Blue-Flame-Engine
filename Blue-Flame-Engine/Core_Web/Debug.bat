CALL mkdir ..\Output\Core\Web\Debug\
CALL emcc ^
 "../Core/BF/Engine.cpp" ^
 "../Core/BF/AI/Waypoint.cpp" ^
 "../Core/BF/Application/Scene.cpp" ^
 "../Core/BF/Application/SceneManager.cpp" ^
 "../Core/BF/Application/Window.cpp" ^
 "../Core/BF/Graphics/Animation/SpriteAnimation.cpp" ^
 "../Core/BF/Graphics/API/ConstentBuffer.cpp" ^
 "../Core/BF/Graphics/API/Context.cpp" ^
 "../Core/BF/Graphics/API/IndexBuffer.cpp" ^
 "../Core/BF/Graphics/API/RenderTarget.cpp" ^
 "../Core/BF/Graphics/API/Shader.cpp" ^
 "../Core/BF/Graphics/API/Texture.cpp" ^
 "../Core/BF/Graphics/API/Texture2D.cpp" ^
 "../Core/BF/Graphics/API/VertexBuffer.cpp" ^
 "../Core/BF/Graphics/API/VertexBufferLayout.cpp" ^
 "../Core/BF/Graphics/Fonts/Font.cpp" ^
 "../Core/BF/Graphics/GUI/Button.cpp" ^
 "../Core/BF/Graphics/GUI/Checkbox.cpp" ^
 "../Core/BF/Graphics/GUI/Panel.cpp" ^
 "../Core/BF/Graphics/GUI/Scrollbar.cpp" ^
 "../Core/BF/Graphics/GUI/ScrollbarSlider.cpp" ^
 "../Core/BF/Graphics/GUI/StyleSheet.cpp" ^
 "../Core/BF/Graphics/GUI/Widget.cpp" ^
 "../Core/BF/Graphics/GUI/WidgetManager.cpp" ^
 "../Core/BF/Graphics/Renderers/LineShape.cpp" ^
 "../Core/BF/Graphics/Renderers/RegularPolygon.cpp" ^
 "../Core/BF/Graphics/Renderers/Renderable.cpp" ^
 "../Core/BF/Graphics/Renderers/Sprite.cpp" ^
 "../Core/BF/Graphics/Renderers/SpriteRenderer.cpp" ^
 "../Core/BF/Graphics/Camera.cpp" ^
 "../Core/BF/Graphics/Color.cpp" ^
 "../Core/BF/Graphics/FPSCamera.cpp" ^
 "../Core/BF/Graphics/Light.cpp" ^
 "../Core/BF/Graphics/Material.cpp" ^
 "../Core/BF/Graphics/Mesh.cpp" ^
 "../Core/BF/Graphics/Model.cpp" ^
 "../Core/BF/Graphics/Terrain.cpp" ^
 "../Core/BF/Graphics/TextureAtlas.cpp" ^
 "../Core/BF/Graphics/TileMap.cpp" ^
 "../Core/BF/Input/Keyboard.cpp" ^
 "../Core/BF/Input/Mouse.cpp" ^
 "../Core/BF/IO/BFALoader.cpp" ^
 "../Core/BF/IO/BFMLoader.cpp" ^
 "../Core/BF/IO/BFXLoader.cpp" ^
 "../Core/BF/IO/FileLoader.cpp" ^
 "../Core/BF/IO/ImageLoader.cpp" ^
 "../Core/BF/IO/WAVLoader.cpp" ^
 "../Core/BF/Math/Math.cpp" ^
 "../Core/BF/Math/Matrix4.cpp" ^
 "../Core/BF/Math/Rectangle.cpp" ^
 "../Core/BF/Math/Vector2.cpp" ^
 "../Core/BF/Math/Vector3.cpp" ^
 "../Core/BF/Math/Vector4.cpp" ^
 "../Core/BF/Platform/API/OpenGL/Context/WEBGLContext.cpp" ^
 "../Core/BF/Platform/API/OpenGL/GLConstentBuffer.cpp" ^
 "../Core/BF/Platform/API/OpenGL/GLError.cpp" ^
 "../Core/BF/Platform/API/OpenGL/GLFramebuffer.cpp" ^
 "../Core/BF/Platform/API/OpenGL/GLIndexBuffer.cpp" ^
 "../Core/BF/Platform/API/OpenGL/GLShader.cpp" ^
 "../Core/BF/Platform/API/OpenGL/GLTexture2D.cpp" ^
 "../Core/BF/Platform/API/OpenGL/GLVertexBuffer.cpp" ^
 "../Core/BF/Platform/Web/WEBEngineEntryPoint.cpp" ^
 "../Core/BF/Platform/Web/WEBWindow.cpp" ^
 "../Core/BF/System/Timer.cpp" ^
 -I "../Core/" ^
 -I "../Dependency/FreeImage/Source/" ^
 -I "../Dependency/FreeType/include/" ^
 -I "../Dependency/TinyXML-2/" ^
 -D BF_PLATFORM_WEB ^
 -std=c++14 ^
 -O0 ^
 -o ../Output/Core/Web/Debug/Core.bc