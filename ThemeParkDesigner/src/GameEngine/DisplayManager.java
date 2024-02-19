package GameEngine;

import Utils.MyLogging;
import org.lwjgl.glfw.GLFW;
import org.lwjgl.glfw.GLFWVidMode;
import org.lwjgl.opengl.GL;

import java.util.logging.Level;

public class DisplayManager
{
    private String title = "ThemeParkDesigner";

    private int width;
    private int height;

    private long window;

    public DisplayManager(int width, int height)
    {
        this.width = width;
        this.height = height;
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
}
