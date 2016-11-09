#include "DXContext.h"
#include "BF/Graphics/API/Context.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace DirectX
			{
				DXContext::DXContext(Application::Window* window) :
					window(window), device(nullptr), context(nullptr), swapChain(nullptr), renderTarget(nullptr), rasterizerState(nullptr), zBuffer(nullptr), D3DPrimitiveType(D3D_PRIMITIVE_TOPOLOGY_UNDEFINED)
				{
					CreateDeviceAndSwapChain();
					CreateBackBuffer();
					CreateRasterizerState();
					CreateDepthBuffer();
					SetViewPort();
				}

				DXContext::~DXContext()
				{
				}

				void DXContext::CreateDeviceAndSwapChain()
				{
					DXGI_SWAP_CHAIN_DESC swapChainDesc;
					ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));

					swapChainDesc.BufferCount = 1;
					swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
					swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
					swapChainDesc.OutputWindow = window->GetWINWindow()->GetHWND();
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

				void DXContext::CreateBackBuffer()
				{
					ID3D11Texture2D* backBuffer;
					ZeroMemory(&backBuffer, sizeof(backBuffer));

					swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBuffer);

					hr = device->CreateRenderTargetView(backBuffer, NULL, &renderTarget);
					if (FAILED(hr))
						std::cout << hr << std::endl;

					backBuffer->Release();
				}

				void DXContext::CreateRasterizerState()
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

				void DXContext::CreateDepthBuffer()
				{
					ID3D11Texture2D* depthBuffer;
					D3D11_TEXTURE2D_DESC texd;
					ZeroMemory(&texd, sizeof(texd));
					ZeroMemory(&depthBuffer, sizeof(depthBuffer));

					texd.Width = window->GetClientWidth();
					texd.Height = window->GetClientHeight();
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

				void DXContext::SetViewPort()
				{
					D3D11_VIEWPORT viewPort;
					ZeroMemory(&viewPort, sizeof(viewPort));

					viewPort.TopLeftX = 0;
					viewPort.TopLeftY = 0;
					viewPort.Width = window->GetClientWidth();
					viewPort.Height = window->GetClientHeight();
					viewPort.MinDepth = 0;
					viewPort.MaxDepth = 1;
					context->RSSetViewports(1, &viewPort);
				}

				void DXContext::SetPrimitiveType(Graphics::API::PrimitiveType primitiveType)
				{
					switch (primitiveType)
					{
						case Graphics::API::PrimitiveType::PointList:
						{
							D3DPrimitiveType = D3D11_PRIMITIVE_TOPOLOGY_POINTLIST;
							break;
						}
						case Graphics::API::PrimitiveType::LineList:
						{
							D3DPrimitiveType = D3D11_PRIMITIVE_TOPOLOGY_LINELIST;
							break;
						}
						case Graphics::API::PrimitiveType::LineStrip:
						{
							D3DPrimitiveType = D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP;
							break;
						}
						case Graphics::API::PrimitiveType::TriangleList:
						{
							D3DPrimitiveType = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
							break;
						}
						case Graphics::API::PrimitiveType::TriangeStrip:
						{
							D3DPrimitiveType = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP;
							break;
						}
						default:
							break;
					}
					context->IASetPrimitiveTopology(D3DPrimitiveType);
				}

				void DXContext::Clear(Math::Vector4 Color)
				{
					float color[4] = { Color.x, Color.y, Color.z, Color.w };
					context->ClearRenderTargetView(renderTarget, color);
					context->ClearDepthStencilView(zBuffer, D3D11_CLEAR_DEPTH, 1.0f, 0);
				}

				void DXContext::SwapBuffers()
				{
					swapChain->Present(0, 0);
				}

				void DXContext::Draw(unsigned int vertexCount)
				{
					context->DrawIndexed(vertexCount, 0, 0);
				}

				void DXContext::CleanUp()
				{
					swapChain->Release();
					renderTarget->Release();
					device->Release();
					context->Release();
				}
			}
		}
	}
}