#include <vulkan/vulkan.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

class AmayaEngine {
	public:
		void run() {
			initVulkan();
			mainLoop();
			cleanup();
		}

	private:
		void initVulkan() {

		}

		void mainLoop() {

		}

		void cleanup() {

		}
};

int main() {
	AmayaEngine app;

	try {
		app.run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}