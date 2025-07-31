// first_app.hpp
#pragma once

#include "app_window.hpp"
#include "instance.hpp"
#include <memory>
#include <vector>

namespace app {
class FirstApp {
public:
  static constexpr int WIDTH = 800;
  static constexpr int HEIGHT = 600;

  FirstApp();
  ~FirstApp();

  FirstApp(const FirstApp &) = delete;
  FirstApp &operator=(const FirstApp &) = delete;

  void run();

private:
  std::vector<const char *> getRequiredExtensions();
  std::vector<const char *> getRequiredLayers();
  AppWindow appWindow{WIDTH, HEIGHT, "Vulkan smth"};
  std::unique_ptr<vk::Instance> vkInstance;
};
} // namespace app