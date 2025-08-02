#pragma once

#include "debug.hpp"
#include "vulkan/vulkan.h"
#include "vulkan/vulkan_core.h"
#include <string>
#include <vector>

namespace instance {
class Instance {
public:
  Instance(const std::vector<const char *> &extensions,
           const std::vector<const char *> &layers,
           bool enableValidationLayers);
  ~Instance();

  Instance(const Instance &) = delete;
  Instance &operator=(const Instance &) = delete;

  VkInstance get() const { return instance; }

private:
  void createInstance();
  VkApplicationInfo addVkApplicationInfo();
  VkInstanceCreateInfo addVkInstanceCreateInfo(VkApplicationInfo appInfo);
  void setupDebugMessenger();
  bool checkValidationLayerSupport();

  VkInstance instance;

  std::vector<const char *> enabledExtensions;
  std::vector<const char *> enabledLayers;
  bool enableValidationLayers{};

  std::unique_ptr<debug::DebugUtilsMessenger> debugMessenger;
};
} // namespace instance
