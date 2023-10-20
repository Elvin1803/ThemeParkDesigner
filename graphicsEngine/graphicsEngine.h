#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

struct graphicsEngine
{
  GLFWwindow* window;
  VkInstance instance;

  char* name;

  int height;
  int width;
};

struct graphicsEngine* createEngine();

void run(struct graphicsEngine* engine);
