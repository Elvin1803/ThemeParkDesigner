#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>

#include "graphicsEngine.h"
#include "initVulkan.h"

//Function that will set all parameters for the graphics engine
struct graphicsEngine* createEngine()
{
  struct graphicsEngine* engine = malloc(sizeof(struct graphicsEngine));
  
  engine->name = "Theme Park Designer";
  
  engine->width = 1280;
  engine->height = 720;
  
  return engine;
}


//setting up the application
void initWindow(struct graphicsEngine* engine)
{
  glfwInit();
  
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
  
  engine->window = glfwCreateWindow(engine->width, engine->height, engine->name, NULL, NULL);
}

void initVulkan(struct graphicsEngine* engine)
{
  createInstance(engine);
}

void mainLoop(struct graphicsEngine* engine)
{
  while (!glfwWindowShouldClose(engine->window))
    {
      glfwPollEvents();
    }
}

void cleanup(struct graphicsEngine* engine)
{
  vkDestroyInstance(engine->instance, NULL);
  glfwDestroyWindow(engine->window);
  glfwTerminate();

  free(engine);
}


void run(struct graphicsEngine* engine)
{
  initWindow(engine);
  initVulkan(engine);  
  mainLoop(engine);
  cleanup(engine);
}
