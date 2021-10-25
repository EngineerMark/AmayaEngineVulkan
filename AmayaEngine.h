#pragma once
#include "AmayaVulkan.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>

class AmayaEngine {
public:
	void run();

private:
	//misc stuff
	const char* ENGINE_NAME = "AmayaEngine";
	const char* APP_NAME = "Test App";

	//glfw stuff
	const uint32_t WIN_WIDTH = 800;
	const uint32_t WIN_HEIGHT = 600;
	GLFWwindow* window;

	//vulkan stuff
	AmayaVulkan* graphicsEngine;

	void initWindow();
	void mainLoop();
	void cleanup();

	std::vector<const char*> getRequiredExtensions();
};
