package main;

import main.java.GameEngine.DisplayManager;
import main.java.GameEngine.GraphicsEngine.Renderer;
import main.java.GameEngine.Utils.MyLogging;
import main.java.TPD.Scene;

import java.util.logging.Level;


public class Main implements Runnable
{
    private DisplayManager displayManager;
    private Renderer renderer;
    private Scene scene;

    public void start()
    {
        MyLogging.log(Level.INFO, "Starting application.");
        Thread game = new Thread(this, "ThemeParkManager");
        game.start();
    }

    public void init()
    {
        displayManager = new DisplayManager("Theme Park Designer", 1280, 720);
        displayManager.createDisplay();

        scene = new Scene();
        renderer = new Renderer();
    }

    public void run()
    {
        init();
        while (!displayManager.shouldClose())
        {
            renderer.prepare();
            // Main game loop here
            scene.update();
            render();
            update();
        }

        scene.cleanUp();
        renderer.cleanUp();
        MyLogging.log(Level.INFO, "Exiting Application.");
    }

    public void update()
    {
        displayManager.updateDisplay();
    }

    public void render()
    {
        renderer.renderScene(scene);
        displayManager.swapBuffers();
    }

    public static void main(String[] args)
    {
        // Change to LEVEL.SEVERE for release
        MyLogging.getLogger().setLevel(Level.INFO);
        MyLogging.log(Level.INFO, "PWD: " + System.getProperty("user.dir"));
        new Main().start();
    }
}