//first_app.cpp
#include "first_app.hpp"
#include "GLFW/glfw3.h"

namespace app {
  void FirstApp::run() {
    while (!appWindow.shouldClose()) {
      glfwPollEvents();
    }
  };
}