#include "AmayaEngine.h"

void AmayaEngine::run() {
	initWindow();
	//initVulkan();

	graphicsEngine = new AmayaVulkan;
	graphicsEngine->initialize(ENGINE_NAME, APP_NAME, getRequiredExtensions());

	mainLoop();
	cleanup();
}

void AmayaEngine::initWindow() {
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, ENGINE_NAME, nullptr, nullptr);
}

void AmayaEngine::mainLoop() {
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}
}

void AmayaEngine::cleanup() {
	graphicsEngine->cleanup();

	delete graphicsEngine;

	glfwDestroyWindow(window);
	glfwTerminate();
}

std::vector<const char*> AmayaEngine::getRequiredExtensions() {
	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;
	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

	if (graphicsEngine->validationLayersEnabled()) {
		extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
	}

	return extensions;
}