// first_app.cpp
#include "first_app.hpp"
#include "GLFW/glfw3.h"
#include <memory>
#include <vector>

namespace app {
FirstApp::FirstApp() : appWindow(WIDTH, HEIGHT, "Vulkan smth") {
  vkInstance = std::make_unique<vk::Instance>(getRequiredExtensions(),
                                              std::vector<const char *>{});
}

FirstApp::~FirstApp() {
}

void FirstApp::run() {
  while (!appWindow.shouldClose()) {
    glfwPollEvents();
  }
}

std::vector<const char *> FirstApp::getRequiredExtensions() {
  uint32_t glfwExtensionCount = 0;
  const char **glfwExtensions;
  glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount); // запрашивает список расширений

  std::vector<const char *> extensions(glfwExtensions,
                                       glfwExtensions + glfwExtensionCount);

  return extensions;
} 
} // namespace app