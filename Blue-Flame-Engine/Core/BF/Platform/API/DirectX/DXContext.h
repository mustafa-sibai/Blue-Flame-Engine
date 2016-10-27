#pragma once
#include <d3d11.h>
#include "BF/Application/Window.h"
#include "BF/Math/Vector4.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace DirectX
			{
				class BF_API DXContext
				{
					private:
						Application::Window* window;

						ID3D11Device* device;
						ID3D11DeviceContext* context;
						IDXGISwapChain* swapChain;
						ID3D11RenderTargetView* renderTarget;
						ID3D11RasterizerState* rasterizerState;
						ID3D11DepthStencilView* zBuffer;
						HRESULT hr;

					public:
						DXContext(Application::Window* window);
						~DXContext();

						void Clear(Math::Vector4 Color);
						void SwapBuffers();
						void Draw(unsigned int vertexCount);
						void CleanUp();

						inline ID3D11Device* GetDevice() const { return device; }
						inline ID3D11DeviceContext* GetContext() const { return context; }
						inline const IDXGISwapChain* GetSwapChain() const { return swapChain; }

					private:
						void CreateDeviceAndSwapChain();
						void CreateBackBuffer();
						void CreateRasterizerState();
						void CreateDepthBuffer();
						void SetViewPort();
				};
			}
		}
	}
}