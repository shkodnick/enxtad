// app_window.cpp
#include "app_window.hpp"
#include "GLFW/glfw3.h"

namespace app {
AppWindow::AppWindow(uint32_t w, uint32_t h, std::string name)
    : width{w}, height{h}, windowName(name) {
  initWindow();
}

AppWindow::~AppWindow() {
  glfwDestroyWindow(window);
  glfwTerminate();
}

void AppWindow::initWindow() {
  glfwInit();

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  window =
      glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
}
} // namespace app