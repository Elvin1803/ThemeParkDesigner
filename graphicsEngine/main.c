#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>

#include "graphicsEngine.h"

int main()
{
  struct graphicsEngine* engine = createEngine();
  run(engine);

  return 0;
}
