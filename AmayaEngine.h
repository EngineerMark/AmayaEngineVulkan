#pragma once
#include "AmayaVulkan.h"

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

	//vulkan stuff
	AmayaVulkan* graphicsEngine;

	void mainLoop();
	void cleanup();
};
