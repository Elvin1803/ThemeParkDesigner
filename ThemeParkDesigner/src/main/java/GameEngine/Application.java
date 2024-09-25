package main.java.GameEngine;

import main.java.GameEngine.GraphicsEngine.Display.DisplayManager;
import main.java.GameEngine.Utils.MyLogging;

import java.util.logging.Level;

public class Application
{
    private final DisplayManager displayManager;
    public SceneManager sceneManager;

    public Application(String title)
    {
        MyLogging.log(Level.INFO, "Starting application.");

        displayManager = new DisplayManager(title, 1280, 720);
        displayManager.createDisplay();

        sceneManager = SceneManager.getInstance();
    }

    public void run()
    {
        while (!displayManager.shouldClose())
        {
            // Main game loop here
            // Update current Scene

            sceneManager.update();
            displayManager.swapBuffers();
            displayManager.updateDisplay();
        }
    }
}
