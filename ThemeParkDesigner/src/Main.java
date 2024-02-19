import GameEngine.GraphicsEngine.DisplayManager;
import Utils.MyLogging;

import java.awt.*;
import java.util.logging.Level;

public class Main implements Runnable
{
    public Thread game;
    public DisplayManager displayManager;

    public void start()
    {
        MyLogging.log(Level.INFO, "Starting application.");
        game = new Thread(this, "ThemeParkManager");
        game.start();
    }

    public void init()
    {
        displayManager = new DisplayManager(1280, 720);
        displayManager.createDisplay();
    }

    public void run()
    {
        init();
        while (!displayManager.shouldClose())
        {
            update();
            render();
        }
    }

    public void update()
    {
        displayManager.updateDisplay();
    }

    public void render()
    {
        displayManager.swapBuffers();
    }

    public static void main(String[] args)
    {
        // Change to LEVEL.SEVERE for release
        MyLogging.getLogger().setLevel(Level.SEVERE);
        new Main().start();
    }
}