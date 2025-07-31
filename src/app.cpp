// first_app.cpp
#include "app.hpp"
#include "GLFW/glfw3.h"
#include "vulkan/vulkan.h"
#include <memory>
#include <vector>

namespace app {
FirstApp::FirstApp() : appWindow(WIDTH, HEIGHT, "Vulkan smth") {
#ifdef DEBUG
  bool enableValidation = true;
#else
  bool enableValidation = false;
#endif
  vkInstance = std::make_unique<vk::Instance>(
      getRequiredExtensions(), getRequiredLayers(), enableValidation);
}

FirstApp::~FirstApp() {}

void FirstApp::run() {
  while (!appWindow.shouldClose()) {
    glfwPollEvents();
  }
}

std::vector<const char *> FirstApp::getRequiredExtensions() {
  uint32_t glfwExtensionCount = 0;
  const char **glfwExtensions;
  glfwExtensions = glfwGetRequiredInstanceExtensions(
      &glfwExtensionCount); // запрашивает список расширений

  std::vector<const char *> extensions(glfwExtensions,
                                       glfwExtensions + glfwExtensionCount);

#ifdef DEBUG
  extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
#endif

  return extensions;
}

std::vector<const char *> FirstApp::getRequiredLayers() {
  std::vector<const char *> layers;

#ifdef DEBUG
  layers.push_back("VK_LAYER_KHRONOS_validation");
#endif

  return layers;
}
} // namespace app