#pragma once

#include "vulkan/vulkan.h"
#include <iostream>

namespace debug {

class DebugUtilsMessenger {
public:
  DebugUtilsMessenger(VkInstance instance, bool enableValidation);
  ~DebugUtilsMessenger();

  DebugUtilsMessenger(const DebugUtilsMessenger &) = delete;
  DebugUtilsMessenger &operator=(const DebugUtilsMessenger &) = delete;

  VkDebugUtilsMessengerEXT get() const { return debugMessenger; }

private:
  static VKAPI_ATTR VkBool32 VKAPI_CALL
  debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                VkDebugUtilsMessageTypeFlagsEXT messageType,
                const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData,
                void *pUserData);
  void createDebugMessenger();
  void populateDebugMessengerCreateInfo(
      VkDebugUtilsMessengerCreateInfoEXT &createInfo);

  static VkResult CreateDebugUtilsMessengerEXT(
      VkInstance instance,
      const VkDebugUtilsMessengerCreateInfoEXT *pCreateInfo,
      const VkAllocationCallbacks *pAllocator,
      VkDebugUtilsMessengerEXT *pDebugMessenger);

  static void
  DestroyDebugUtilsMessengerEXT(VkInstance instance,
                                VkDebugUtilsMessengerEXT debugMessenger,
                                const VkAllocationCallbacks *pAllocator);

  VkInstance vkInstance;
  VkDebugUtilsMessengerEXT debugMessenger{VK_NULL_HANDLE};
  bool enableValidationLayers;
};

} // namespace debug
