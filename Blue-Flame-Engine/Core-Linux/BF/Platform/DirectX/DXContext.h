#ifdef BF_PLATFORM_WINDOWS
#pragma once
#include <d3d11.h>
#include "../../../Math/Vector4.h"

#ifdef COMPILE_BLUE_FLAME_ENGINE   
	#define DLLEXPORT __declspec(dllexport) 
#else   
	#define DLLEXPORT __declspec(dllimport) 
#endif

namespace BFE
{
	namespace Graphics
	{
		class Window;
		class DLLEXPORT DX11Renderer
		{
			private:
				HRESULT hr;
				ID3D11Device *device;
				ID3D11DeviceContext *context;
				IDXGISwapChain *swapChain;
				ID3D11RenderTargetView *renderTarget;
				ID3D11RasterizerState* rasterizerState;
				ID3D11DepthStencilView *zBuffer;
				Window &window;

			public:
				DX11Renderer(Window &window);
				~DX11Renderer();

				void Initialize();
				void Clear(Math::Vector4 Color);
				void SwapBuffers();
				void CleanUp();

				inline ID3D11Device &GetDevice() { return *device; }
				inline ID3D11DeviceContext &GetContext() { return *context; }
				inline IDXGISwapChain &GetSwapChain() { return *swapChain; }

			private:
				void CreateDeviceAndSwapChain();
				void CreateBackBuffer();
				void CreateRasterizerState();
				void CreateDepthBuffer();
				void SetViewPort();
		};
	}
}
#endif