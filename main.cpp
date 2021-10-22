#include <vulkan/vulkan.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

class AmayaEngine {
	public:
		void run() {
			initWindow();
			initVulkan();
			mainLoop();
			cleanup();
		}

	private:
		const uint32_t WIN_WIDTH = 800;
		const uint32_t WIN_HEIGHT = 600;

		GLFWwindow* window;

		void initWindow() {
			glfwInit();

			glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
			glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

			window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "AmayaEngine", nullptr, nullptr);
		}

		void initVulkan() {
		}

		void mainLoop() {
			while (!glfwWindowShouldClose(window)) {
				glfwPollEvents();
			}
		}

		void cleanup() {
			glfwDestroyWindow(window);
			glfwTerminate();
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