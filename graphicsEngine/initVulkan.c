#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>

#include "graphicsEngine.h"
#include "initVulkan.h"

void createInstance(struct graphicsEngine* engine)
{
  struct VkApplicationInfo appInfo;
  appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  appInfo.pApplicationName = "Theme Park Designer";
  appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.pEngineName = "No Engine";
  appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.apiVersion = VK_API_VERSION_1_0;

  struct VkInstanceCreateInfo createInfo;
  createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  createInfo.pApplicationInfo = &appInfo;
  
  uint32_t glfwExtensionCount = 0;
  const char** glfwExtensions;

  glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

  createInfo.enabledExtensionCount = glfwExtensionCount;
  createInfo.ppEnabledExtensionNames = glfwExtensions;

  createInfo.enabledLayerCount = 0;
  
  if (vkCreateInstance(&createInfo, NULL, &(engine->instance)) != VK_SUCCESS)
    {
      printf("Failed to create instance\n");
      exit(EXIT_FAILURE);
    }
}
