//first_app.hpp
#pragma once

#include "app_window.hpp"

namespace app {
  class FirstApp {
    public:
      static constexpr int WIDTH = 800;
      static constexpr int HEIGHT = 600;

  void run();

  private:
    AppWindow appWindow{WIDTH, HEIGHT, "Vulkan smth"};
  };
}