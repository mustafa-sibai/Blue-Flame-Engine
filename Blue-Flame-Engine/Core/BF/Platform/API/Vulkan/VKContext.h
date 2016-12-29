#pragma once
#include <vulkan/vulkan.h>
#include <vector>
#include "BF/Common.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace Vulkan
			{
				class BF_API VKContext
				{
				private:
					VkInstance instance;
					VkDevice device;
					VkPhysicalDevice GPU;
					VkPhysicalDeviceProperties GPUProperties;
					VkResult error;

				public:
					VKContext();
					~VKContext();

				private:
					void CreateInstance();
					void CreateDevice();
				};
			}
		}
	}
}