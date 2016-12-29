#include "VKContext.h"
#include "BF/System/Log.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace Vulkan
			{
				VKContext::VKContext() :
					instance(nullptr), device(nullptr), GPU(nullptr)
				{
					CreateInstance();
					CreateDevice();
				}

				VKContext::~VKContext()
				{
					vkDestroyDevice(device, nullptr);
					vkDestroyInstance(instance, nullptr);
				}

				void VKContext::CreateInstance()
				{
					VkApplicationInfo applicationInfo{};
					applicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
					applicationInfo.apiVersion = VK_MAKE_VERSION(1, 0, 37);
					applicationInfo.engineVersion = VK_MAKE_VERSION(0, 5, 0);
					applicationInfo.pEngineName = "Blue Flame Engine";
					applicationInfo.applicationVersion = VK_MAKE_VERSION(0, 0, 0);
					applicationInfo.pApplicationName = "";

					VkInstanceCreateInfo instanceInfo{};
					instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
					instanceInfo.pApplicationInfo = &applicationInfo;

					error = vkCreateInstance(&instanceInfo, nullptr, &instance);
					if (error != VK_SUCCESS)
						BF_LOG_FATAL("ERROR !!");
				}

				void VKContext::CreateDevice()
				{
					uint32_t GPUCount = 0;
					vkEnumeratePhysicalDevices(instance, &GPUCount, nullptr);
					std::vector<VkPhysicalDevice> GPUs(GPUCount);
					vkEnumeratePhysicalDevices(instance, &GPUCount, GPUs.data());
					GPU = GPUs[0];
					vkGetPhysicalDeviceProperties(GPU, &GPUProperties);

					uint32_t familyCount = 0;
					vkGetPhysicalDeviceQueueFamilyProperties(GPU, &familyCount, nullptr);
					std::vector<VkQueueFamilyProperties> queueFamilyProperties(familyCount);
					vkGetPhysicalDeviceQueueFamilyProperties(GPU, &familyCount, queueFamilyProperties.data());

					bool foundGPU = false;
					uint32_t graphics_family_index = 0;
					for (uint32_t i = 0; i < familyCount; i++)
					{
						if (queueFamilyProperties[i].queueFlags & VK_QUEUE_GRAPHICS_BIT)
						{
							foundGPU = true;
							graphics_family_index = i;
							break;
						}
					}
					if (!foundGPU)
						BF_LOG_FATAL("ERROR !!");

					float queuePriorities[]{ 1.0f };
					VkDeviceQueueCreateInfo deviceQueueInfo{};
					deviceQueueInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
					deviceQueueInfo.queueFamilyIndex = graphics_family_index;
					deviceQueueInfo.queueCount = 1;
					deviceQueueInfo.pQueuePriorities = queuePriorities;

					VkDeviceCreateInfo deviceInfo{};
					deviceInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
					deviceInfo.queueCreateInfoCount = 1;
					deviceInfo.pQueueCreateInfos = &deviceQueueInfo;

					error = vkCreateDevice(GPU, &deviceInfo, nullptr, &device);
					if (error != VK_SUCCESS)
						BF_LOG_FATAL("ERROR !!");
				}
			}
		}
	}
}