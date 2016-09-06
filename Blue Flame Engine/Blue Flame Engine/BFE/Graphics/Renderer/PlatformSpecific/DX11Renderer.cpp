#include "DX11Renderer.h"
#include "../../Window.h"

namespace BFE
{
	namespace Graphics
	{
		DX11Renderer::DX11Renderer(Window &window) :
			window(window), device(nullptr), context(nullptr), swapChain(nullptr), renderTarget(nullptr)
		{
		}

		DX11Renderer::~DX11Renderer()
		{
		}

		void DX11Renderer::Initialize()
		{
			//Initialize D3D11
			DXGI_SWAP_CHAIN_DESC swapChainDesc;
			ZeroMemory(&swapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));

			swapChainDesc.BufferCount = 1;
			swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
			swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
			swapChainDesc.OutputWindow = window.GetHWND();
			swapChainDesc.SampleDesc.Count = 4;
			swapChainDesc.Windowed = TRUE;


			UINT creationFlags = D3D11_CREATE_DEVICE_BGRA_SUPPORT;
#ifdef _DEBUG
			// If the project is in a debug build, enable the debug layer.
			creationFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

			D3D_FEATURE_LEVEL FeatureLevelsRequested[]
			{
				D3D_FEATURE_LEVEL_11_0,
			};

			UINT               numLevelsRequested = 1;
			D3D_FEATURE_LEVEL  FeatureLevelsSupported;
			

			if (FAILED(hr = D3D11CreateDeviceAndSwapChain(NULL,
				D3D_DRIVER_TYPE_HARDWARE,
				NULL,
				creationFlags,
				FeatureLevelsRequested,
				numLevelsRequested,
				D3D11_SDK_VERSION,
				&swapChainDesc,
				&swapChain,
				&device,
				&FeatureLevelsSupported,
				&context)))
			{
				std::cout << hr << std::endl;
			}
			
			//Set back buffer
			ID3D11Texture2D *backBuffer;
			swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBuffer);

			device->CreateRenderTargetView(backBuffer, NULL, &renderTarget);
			backBuffer->Release();

			context->OMSetRenderTargets(1, &renderTarget, NULL);




			ID3D11RasterizerState* m_rasterState;

			D3D11_RASTERIZER_DESC rasterDesc;
			rasterDesc.AntialiasedLineEnable = false;
			rasterDesc.CullMode = D3D11_CULL_NONE;
			rasterDesc.DepthBias = 0;
			rasterDesc.DepthBiasClamp = 0.0f;
			rasterDesc.DepthClipEnable = false;
			rasterDesc.FillMode = D3D11_FILL_SOLID;
			rasterDesc.FrontCounterClockwise = false;
			rasterDesc.MultisampleEnable = false;
			rasterDesc.ScissorEnable = false;
			rasterDesc.SlopeScaledDepthBias = 0.0f;

			// Create the rasterizer state from the description we just filled out.
			device->CreateRasterizerState(&rasterDesc, &m_rasterState);


			// Now set the rasterizer state.
			context->RSSetState(m_rasterState);




			//Set view port
			D3D11_VIEWPORT viewPort;
			ZeroMemory(&viewPort, sizeof(D3D11_VIEWPORT));

			viewPort.TopLeftX = 0;
			viewPort.TopLeftY = 0;
			viewPort.Width = window.GetClientWidth();
			viewPort.Height = window.GetClientHeight();

			context->RSSetViewports(1, &viewPort);
		}

		void DX11Renderer::Clear(Math::Vector4 Color)
		{
			float color[4] = { Color.x, Color.y, Color.z, Color.w };
			context->ClearRenderTargetView(renderTarget, color);
		}

		void DX11Renderer::SwapBuffers()
		{
			swapChain->Present(0, 0);
		}

		void DX11Renderer::CleanUp()
		{
			swapChain->Release();
			renderTarget->Release();
			device->Release();
			context->Release();
		}
	}
}