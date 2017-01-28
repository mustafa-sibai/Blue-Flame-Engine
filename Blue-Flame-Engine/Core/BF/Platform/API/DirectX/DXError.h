#pragma once
#include "BF/System/Log.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace DirectX
			{
				const char* GetDXError(HRESULT hr);

#ifdef _DEBUG
#define DXCall(stmt) \
				do { HRESULT hr = stmt; \
					 if (hr != S_OK) \
						BF_LOG_ERROR("D3D11 %s - %s", GetDXError(hr), #stmt); \
				} while (false)
#else
#define DXCall(stmt) stmt
#endif
			}
		}
	}
}