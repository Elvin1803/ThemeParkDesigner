package main.java.GameEngine.GraphicsEngine;

import main.java.GameEngine.Utils.KeyListener;
import main.java.GameEngine.Utils.MyLogging;
import org.lwjgl.glfw.GLFW;
import org.lwjgl.glfw.GLFWVidMode;
import org.lwjgl.opengl.GL;

import java.util.logging.Level;

public class DisplayManager
{
    private final String title;

    private static int width = 1280;
    private static int height = 720;

    private long window;

    public DisplayManager(String title, int width, int height)
    {
        this.title = title;
        DisplayManager.width = width;
        DisplayManager.height = height;
    }

    public void createDisplay()
    {
        if (!GLFW.glfwInit())
        {
            MyLogging.log(Level.SEVERE, "GLFW couldn't be initialized.");
            return;
        }

        window = GLFW.glfwCreateWindow(width, height, title, 0, 0);
        if (window == 0)
        {
            MyLogging.log(Level.SEVERE, "Window couldn't be created.");
            return;
        }

        GLFW.glfwSetKeyCallback(window, KeyListener::keyCallback);

        GLFWVidMode videoMode = GLFW.glfwGetVideoMode(GLFW.glfwGetPrimaryMonitor());
        if (videoMode == null)
        {
            MyLogging.log(Level.SEVERE, "VideoMode couldn't be created.");
            return;
        }
        GLFW.glfwSetWindowPos(window, (videoMode.width() - width) / 2, (videoMode.height() - height) / 2);
        GLFW.glfwMakeContextCurrent(window);
        GL.createCapabilities();

        GLFW.glfwShowWindow(window);
        GLFW.glfwSwapInterval(1);
    }

    public void updateDisplay()
    {
        GLFW.glfwPollEvents();
    }

    public void swapBuffers()
    {
        GLFW.glfwSwapBuffers(window);
    }

    public boolean shouldClose()
    {
        return GLFW.glfwWindowShouldClose(window);
    }

    public static int getWidth()
    {
        return width;
    }

    public static int getHeight()
    {
        return height;
    }
}
