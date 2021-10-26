#include "AmayaEngine.h"

void AmayaEngine::run() {
	graphicsEngine = new AmayaVulkan;
	graphicsEngine->initialize(WIN_WIDTH, WIN_HEIGHT, ENGINE_NAME, APP_NAME);

	mainLoop();
	cleanup();
}

void AmayaEngine::mainLoop() {
	while (!glfwWindowShouldClose(graphicsEngine->GetWindow())) {
		glfwPollEvents();
	}
}

void AmayaEngine::cleanup() {
	graphicsEngine->cleanup();

	delete graphicsEngine;
}