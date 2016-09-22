#if 0
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
			CreateDeviceAndSwapChain();
			CreateBackBuffer();
			CreateRasterizerState();
			CreateDepthBuffer();
			SetViewPort();
		}

		void DX11Renderer::CreateDeviceAndSwapChain()
		{
			DXGI_SWAP_CHAIN_DESC swapChainDesc;
			ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));

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

			hr = D3D11CreateDeviceAndSwapChain(NULL,
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
				&context);

			if (FAILED(hr))
				std::cout << hr << std::endl;
		}

		void DX11Renderer::CreateBackBuffer()
		{
			ID3D11Texture2D *backBuffer;
			swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBuffer);

			hr = device->CreateRenderTargetView(backBuffer, NULL, &renderTarget);
			if (FAILED(hr))
				std::cout << hr << std::endl;

			backBuffer->Release();
		}

		void DX11Renderer::CreateRasterizerState()
		{
			D3D11_RASTERIZER_DESC rasterDesc;
			ZeroMemory(&rasterDesc, sizeof(rasterDesc));

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

			hr = device->CreateRasterizerState(&rasterDesc, &rasterizerState);
			if (FAILED(hr))
				std::cout << hr << std::endl;

			context->RSSetState(rasterizerState);
		}

		void DX11Renderer::CreateDepthBuffer()
		{
			ID3D11Texture2D *depthBuffer;
			D3D11_TEXTURE2D_DESC texd;
			ZeroMemory(&texd, sizeof(texd));

			texd.Width = window.GetClientWidth();
			texd.Height = window.GetClientHeight();
			texd.ArraySize = 1;
			texd.MipLevels = 1;
			texd.SampleDesc.Count = 4;
			texd.Format = DXGI_FORMAT_D32_FLOAT;
			texd.BindFlags = D3D11_BIND_DEPTH_STENCIL;

			hr = device->CreateTexture2D(&texd, NULL, &depthBuffer);
			if (FAILED(hr))
				std::cout << hr << std::endl;

			//Create Z-Buffer
			D3D11_DEPTH_STENCIL_VIEW_DESC dsvd;
			ZeroMemory(&dsvd, sizeof(dsvd));

			dsvd.Format = DXGI_FORMAT_D32_FLOAT;
			dsvd.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2DMS;
			device->CreateDepthStencilView(depthBuffer, &dsvd, &zBuffer);
			depthBuffer->Release();

			context->OMSetRenderTargets(1, &renderTarget, zBuffer);
		}

		void DX11Renderer::SetViewPort()
		{
			D3D11_VIEWPORT viewPort;
			ZeroMemory(&viewPort, sizeof(viewPort));

			viewPort.TopLeftX = 0;
			viewPort.TopLeftY = 0;
			viewPort.Width = window.GetClientWidth();
			viewPort.Height = window.GetClientHeight();
			viewPort.MinDepth = 0;
			viewPort.MaxDepth = 1;
			context->RSSetViewports(1, &viewPort);
		}

		void DX11Renderer::Clear(Math::Vector4 Color)
		{
			float color[4] = { Color.x, Color.y, Color.z, Color.w };
			context->ClearRenderTargetView(renderTarget, color);
			context->ClearDepthStencilView(zBuffer, D3D11_CLEAR_DEPTH, 1.0f, 0);
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
#endif