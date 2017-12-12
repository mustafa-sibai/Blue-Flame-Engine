#pragma once
#include "BF/System/Debug.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace DirectX
			{
				std::string GetDXError(HRESULT hr);

#ifdef _DEBUG
#define DXCall(stmt) \
				do { HRESULT hr = stmt; \
					 if (hr != S_OK) \
						BF_LOG_ERROR("D3D11 " + GetDXError(hr) + " - " + #stmt, ""); \
				} while (false)
#else
#define DXCall(stmt) stmt
#endif
			}
		}
	}
}