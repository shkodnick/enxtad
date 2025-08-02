#include "instance.hpp"
#include "vulkan/vulkan_core.h"
#include <cstring>
#include <iostream>
#include <stdexcept>

namespace instance {
Instance::Instance(const std::vector<const char *> &exts,
                   const std::vector<const char *> &layers,
                   bool enableValidation)
    : enabledExtensions(exts), enabledLayers(layers),
      enableValidationLayers(enableValidation) {
  createInstance();
  setupDebugMessenger();
}

Instance::~Instance() { vkDestroyInstance(instance, nullptr); }

void Instance::createInstance() {

  std::cout << "Requested extensions:" << std::endl;
  for (const auto &ext : enabledExtensions) {
    std::cout << "  " << ext << std::endl;
  }

  if (enableValidationLayers && !checkValidationLayerSupport()) {
    throw std::runtime_error("validation layers requested, but not available!");
  }

  VkApplicationInfo appInfo = addVkApplicationInfo();
  VkInstanceCreateInfo createInfo = addVkInstanceCreateInfo(appInfo);

  VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
  if (result != VK_SUCCESS) {
    std::cerr << "Failed to create Vulkan instance. Error code: " << result
              << std::endl;
    throw std::runtime_error("failed to create Vulkan instance");
  }

  std::cout << "Vulkan instance created successfully!" << std::endl;
}

VkApplicationInfo Instance::addVkApplicationInfo() {
  VkApplicationInfo appInfo{};
  appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  appInfo.pApplicationName = "Hello smth";
  appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.pEngineName = "No Engine";
  appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.apiVersion = VK_API_VERSION_1_0;

  return appInfo;
}

VkInstanceCreateInfo
Instance::addVkInstanceCreateInfo(VkApplicationInfo appInfo) {
  VkInstanceCreateInfo createInfo{};
  createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  createInfo.pApplicationInfo = &appInfo;

  // На macOS нужно добавить portability расширение
  std::vector<const char *> allExtensions = enabledExtensions;
  allExtensions.push_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);

  createInfo.enabledExtensionCount =
      static_cast<uint32_t>(allExtensions.size());
  createInfo.ppEnabledExtensionNames = allExtensions.data();

  if (enableValidationLayers) {
    createInfo.enabledLayerCount = static_cast<uint32_t>(enabledLayers.size());
    createInfo.ppEnabledLayerNames = enabledLayers.data();
  }

  // Флаг для portability на macOS
  createInfo.flags |= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;

  return createInfo;
}

bool Instance::checkValidationLayerSupport() {
  uint32_t layerCount;
  vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

  std::vector<VkLayerProperties> availableLayers(layerCount);
  vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

  for (const char *layerName : enabledLayers) {
    bool layerFound = false;

    for (const auto &layerProperties : availableLayers) {
      if (strcmp(layerName, layerProperties.layerName) == 0) {
        layerFound = true;
        break;
      }
    }

    if (!layerFound) {
      return false;
    }
  }

  return true;
}

void Instance::setupDebugMessenger() {
  debugMessenger = std::make_unique<debug::DebugUtilsMessenger>(
      instance, enableValidationLayers);
}

} // namespace instance
