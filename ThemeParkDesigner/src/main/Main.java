package main;

import main.java.GameEngine.DisplayManager;
import main.java.GameEngine.GraphicsEngine.Mesh;
import main.java.GameEngine.GraphicsEngine.Renderer;
import main.java.GameEngine.GraphicsEngine.Vertex;
import main.java.GameEngine.Utils.Maths.Vector3f;
import main.java.GameEngine.Utils.MyLogging;

import java.util.logging.Level;

public class Main implements Runnable
{
    public Thread game;
    public DisplayManager displayManager;
    public Renderer renderer;
    public Mesh rectangle;

    public void start()
    {
        MyLogging.log(Level.INFO, "Starting application.");
        game = new Thread(this, "ThemeParkManager");
        game.start();
    }

    public void init()
    {
        displayManager = new DisplayManager(1280, 720);
        renderer = new Renderer();
        displayManager.createDisplay();

        rectangle = new Mesh(new Vertex[]{
                new Vertex(new Vector3f(-0.5f, 0.5f, 0.0f)),
                new Vertex(new Vector3f(0.5f, 0.5f, 0.0f)),
                new Vertex(new Vector3f(-0.5f, -0.5f, 0.0f)),
                new Vertex(new Vector3f(0.5f, -0.5f, 0.0f)),
        }, new int[]{
                0, 2, 1,
                1, 2, 3
        });
        rectangle.createVao();
    }

    public void run()
    {
        init();
        while (!displayManager.shouldClose())
        {
            renderer.prepare();
            // main.Main game loop here
            update();
            render();
        }

        rectangle.cleanUp();
        MyLogging.log(Level.INFO, "Exiting Application.");
    }

    public void update()
    {
        displayManager.updateDisplay();
    }

    public void render()
    {
        renderer.renderMesh(rectangle);
        displayManager.swapBuffers();
    }

    public static void main(String[] args)
    {
        // Change to LEVEL.SEVERE for release
        MyLogging.getLogger().setLevel(Level.FINEST);
        MyLogging.log(Level.INFO, "PWD: " + System.getProperty("user.dir"));
        new Main().start();
    }
}