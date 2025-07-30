#pragma once

#include "vulkan/vulkan.h"
#include "vulkan/vulkan_core.h"
#include <string>
#include <vector>

namespace vk {
class Instance {
public:
  Instance(const std::vector<const char *> &extensions,
           const std::vector<const char *> &layers);
  ~Instance();

  Instance(const Instance &) = delete;
  Instance &operator=(const Instance &) = delete;

  VkInstance get() const { return instance; }

private:
  void createInstance();

  VkInstance instance;

  std::vector<const char *> enabledExtensions;
  std::vector<const char *> enabledLayers;
};
} // namespace vk
