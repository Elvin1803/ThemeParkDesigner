package main.java.GameEngine;

import main.java.GameEngine.GraphicsEngine.DisplayManager;
import main.java.GameEngine.Utils.MyLogging;

import java.util.logging.Level;

public class Application
{
    private final DisplayManager displayManager;
    public Scene currentScene;

    public Application(String title)
    {
        MyLogging.log(Level.INFO, "Starting application.");

        displayManager = new DisplayManager(title, 1280, 720);
        displayManager.createDisplay();

        currentScene = new Scene();
    }

    public void run()
    {
        while (!displayManager.shouldClose())
        {
            // Main game loop here
            // Update current Scene

            currentScene.update();
            displayManager.swapBuffers();
            displayManager.updateDisplay();
        }

        currentScene.cleanUp();
    }
}
