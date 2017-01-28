#include "DXContext.h"
#include "BF/Graphics/API/Context.h"
#include "BF/Engine.h"
#include "DXError.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace DirectX
			{
				using namespace BF::Graphics::API;
				using namespace BF::Math;

				DXContext::DXContext() :
					device(nullptr), context(nullptr), swapChain(nullptr), renderTarget(nullptr), rasterizerState(nullptr), zBuffer(nullptr), vsync(false), D3DPrimitiveType(D3D_PRIMITIVE_TOPOLOGY_UNDEFINED)
				{
				}

				DXContext::~DXContext()
				{
				}

				void DXContext::Initialize()
				{
					CreateDeviceAndSwapChain();
					CreateBackBuffer();
					CreateRasterizerState();
					CreateDepthBuffer();
					SetViewPort();

					context->OMSetRenderTargets(1, &renderTarget, zBuffer);
				}

				void DXContext::Clear(const Vector4& Color)
				{
					float color[] = { Color.x, Color.y, Color.z, Color.w };
					context->ClearRenderTargetView(renderTarget, color);

					if (zBuffer)
						context->ClearDepthStencilView(zBuffer, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
				}

				void DXContext::SwapBuffers()
				{
					if(vsync)
						DXCall(swapChain->Present(1, 0));
					else
						DXCall(swapChain->Present(0, 0));
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

				void DXContext::SetPrimitiveType(PrimitiveType primitiveType)
				{
					switch (primitiveType)
					{
						case PrimitiveType::PointList:
						{
							D3DPrimitiveType = D3D11_PRIMITIVE_TOPOLOGY_POINTLIST;
							break;
						}
						case PrimitiveType::LineList:
						{
							D3DPrimitiveType = D3D11_PRIMITIVE_TOPOLOGY_LINELIST;
							break;
						}
						case PrimitiveType::LineStrip:
						{
							D3DPrimitiveType = D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP;
							break;
						}
						case PrimitiveType::TriangleList:
						{
							D3DPrimitiveType = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
							break;
						}
						case PrimitiveType::TriangeStrip:
						{
							D3DPrimitiveType = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP;
							break;
						}
						default:
							break;
					}
					context->IASetPrimitiveTopology(D3DPrimitiveType);
				}

				void DXContext::EnableDepthBuffer(bool state)
				{
					if (state)
						context->OMSetRenderTargets(1, &renderTarget, zBuffer);
					else
						context->OMSetRenderTargets(1, &renderTarget, 0);
				}

				void DXContext::EnableBlending(bool state)
				{
					if (state)
					{
						D3D11_BLEND_DESC blendDesc;
						ZeroMemory(&blendDesc, sizeof(blendDesc));

						blendDesc.RenderTarget[0].BlendEnable = TRUE;
						blendDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
						blendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
						blendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
						blendDesc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
						blendDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
						blendDesc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
						blendDesc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
						blendDesc.IndependentBlendEnable = FALSE;
						blendDesc.AlphaToCoverageEnable = FALSE;

						DXCall(device->CreateBlendState(&blendDesc, &blendState));
						context->OMSetBlendState(blendState, 0, 0xffffffff);
					}
					else
						context->OMSetBlendState(0, 0, 0xffffffff);
				}

				void DXContext::EnableVsync(bool state)
				{
					vsync = state;
				}

				void DXContext::CreateDeviceAndSwapChain()
				{
					DXGI_SWAP_CHAIN_DESC swapChainDesc;
					ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));

					swapChainDesc.BufferCount = 1;
					swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
					swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
					swapChainDesc.OutputWindow = Engine::GetWindow().GetHWND();
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

					DXCall(D3D11CreateDeviceAndSwapChain(NULL,
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
						&context));
				}

				void DXContext::CreateBackBuffer()
				{
					ID3D11Texture2D* backBuffer;
					ZeroMemory(&backBuffer, sizeof(backBuffer));

					DXCall(swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBuffer));
					DXCall(device->CreateRenderTargetView(backBuffer, NULL, &renderTarget));
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

					DXCall(device->CreateRasterizerState(&rasterDesc, &rasterizerState));
					context->RSSetState(rasterizerState);
				}

				void DXContext::CreateDepthBuffer()
				{
					ID3D11Texture2D* depthBuffer;
					D3D11_TEXTURE2D_DESC texd;
					ZeroMemory(&texd, sizeof(texd));
					ZeroMemory(&depthBuffer, sizeof(depthBuffer));

					texd.Width = Engine::GetWindow().GetClientWidth();
					texd.Height = Engine::GetWindow().GetClientHeight();
					texd.ArraySize = 1;
					texd.MipLevels = 1;
					texd.SampleDesc.Count = 4;
					texd.Format = DXGI_FORMAT_D32_FLOAT;
					texd.BindFlags = D3D11_BIND_DEPTH_STENCIL;
					DXCall(device->CreateTexture2D(&texd, NULL, &depthBuffer));

					//Create Z-Buffer
					D3D11_DEPTH_STENCIL_VIEW_DESC dsvd;
					ZeroMemory(&dsvd, sizeof(dsvd));

					dsvd.Format = DXGI_FORMAT_D32_FLOAT;
					dsvd.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2DMS;
					DXCall(device->CreateDepthStencilView(depthBuffer, &dsvd, &zBuffer));
					depthBuffer->Release();
				}

				void DXContext::SetViewPort()
				{
					D3D11_VIEWPORT viewPort;
					ZeroMemory(&viewPort, sizeof(viewPort));

					viewPort.TopLeftX = 0;
					viewPort.TopLeftY = 0;
					viewPort.Width = Engine::GetWindow().GetClientWidth();
					viewPort.Height = Engine::GetWindow().GetClientHeight();
					viewPort.MinDepth = 0.0f;
					viewPort.MaxDepth = 1.0f;
					context->RSSetViewports(1, &viewPort);
				}
			}
		}
	}
}