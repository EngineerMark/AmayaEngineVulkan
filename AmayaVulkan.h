#pragma once

#include <vulkan/vulkan.h>
#include <vector>
#include <iostream>
#include "QueueFamilyIndices.h"
#include "SwapChainSupportDetails.h"

#define VK_USE_PLATFORM_WIN32_KHR
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>

#include <cstdint>
#include <algorithm>
#include "AmayaFile.h"

class AmayaVulkan
{
	public:
		bool framebufferResized = false;

		void initialize(const uint32_t windowWidth, const uint32_t windowHeight, const char* engineName, const char* appName);
		void initWindow();
		void cleanup();
		void drawFrame();

		void waitIdle(){
			vkDeviceWaitIdle(device);
		}

		bool validationLayersEnabled() {
			return enableValidationLayers;
		}

		GLFWwindow* GetWindow() {
			return window;
		}

	private:
		const int MAX_FRAMES_IN_FLIGHT = 2;

		char* ENGINE_NAME;
		char* APP_NAME;

		uint32_t WIN_WIDTH = 800;
		uint32_t WIN_HEIGHT = 600;

		AmayaFile* fileSystem;

		GLFWwindow* window;

		VkInstance instance;
		VkDebugUtilsMessengerEXT debugMessenger;
		VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
		VkDevice device;
		VkQueue graphicsQueue;
		VkQueue presentQueue;
		VkSurfaceKHR surface;
		VkSwapchainKHR swapChain;
		VkFormat swapChainImageFormat;
		VkExtent2D swapChainExtent;
		VkPipelineLayout pipelineLayout;
		VkRenderPass renderPass;
		VkPipeline graphicsPipeline;
		VkCommandPool commandPool;
		VkSemaphore imageAvailableSemaphore;
		VkSemaphore renderFinishedSemaphore;

		std::vector<VkImage> swapChainImages;
		std::vector<VkImageView> swapChainImageViews;
		std::vector<VkFramebuffer> swapChainFramebuffers;
		std::vector<VkCommandBuffer> commandBuffers;
		std::vector<VkSemaphore> imageAvailableSemaphores;
		std::vector<VkSemaphore> renderFinishedSemaphores;
		std::vector<VkFence> inFlightFences;
		std::vector<VkFence> imagesInFlight;

		size_t currentFrame = 0;

		const std::vector<const char*> validationLayers = {
			"VK_LAYER_KHRONOS_validation"
		};

		const std::vector<const char*> deviceExtensions = {
			VK_KHR_SWAPCHAIN_EXTENSION_NAME
		};

#ifdef NDEBUG
		const bool enableValidationLayers = false;
#else
		const bool enableValidationLayers = true;
#endif

		void initVulkan();
		void createInstance();
		void setupDebugMessenger();
		void createSurface();
		void pickPhysicalDevice();
		void createLogicalDevice();
		void createSwapChain();
		void createImageViews();
		void createRenderPass();
		void createGraphicsPipeline();
		void createFramebuffers();
		void createCommandPool();
		void createCommandBuffers();
		void createSyncObjects();
		void cleanupSwapChain();
		void recreateSwapChain();

		bool isDeviceSuitable(VkPhysicalDevice device);

		SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
		VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
		VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
		VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
		VkShaderModule createShaderModule(const std::vector<char>& code);

		bool checkDeviceExtensionSupport(VkPhysicalDevice device);
		void populateDebugMessenger(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
		bool checkValidationLayerSupport();

		QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

		std::vector<const char*> getRequiredExtensions();

		VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
		void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);
		static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);
};

