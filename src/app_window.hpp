// app_window.hpp
#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace app {
class AppWindow {
public:
  AppWindow(uint32_t w, uint32_t h, std::string name);
  ~AppWindow();

  AppWindow(const AppWindow &) = delete;
  AppWindow &operator=(const AppWindow &) = delete;

  bool shouldClose() { return glfwWindowShouldClose(window); }

private:
  void initWindow();

  const uint32_t width;
  const uint32_t height;

  std::string windowName;
  GLFWwindow *window;
};
} // namespace app
