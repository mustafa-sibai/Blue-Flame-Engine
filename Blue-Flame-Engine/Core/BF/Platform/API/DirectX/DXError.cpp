#include "DXError.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace DirectX
			{
				const char* GetDXError(HRESULT hr)
				{
					switch (hr)
					{
						case D3D11_ERROR_FILE_NOT_FOUND:								return "File not found";
						case D3D11_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS:					return "Too many unique state objects";
						case D3D11_ERROR_TOO_MANY_UNIQUE_VIEW_OBJECTS:					return "Too many unique view objects";
						case D3D11_ERROR_DEFERRED_CONTEXT_MAP_WITHOUT_INITIAL_DISCARD:  return "Deferred context map without initial discard";
						case DXGI_ERROR_INVALID_CALL:									return "Invalid call";
						case DXGI_ERROR_WAS_STILL_DRAWING:								return "Still Drawing";
						case E_FAIL:													return "Attempted to create a device with the debug layer enabled and the layer is not installed";
						case E_INVALIDARG:												return "An invalid parameter was passed to the returning function";
						case E_OUTOFMEMORY:												return "Direct3D could not allocate sufficient memory to complete the call";
						case E_NOTIMPL:													return "The method call isn't implemented with the passed parameter combination";
						case S_FALSE:													return "Nonstandard completion";
						default:														return "Unknown error";
					}
				}
			}
		}
	}
}