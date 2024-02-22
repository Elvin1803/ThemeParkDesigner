package main;

import main.java.GameEngine.DisplayManager;
import main.java.GameEngine.GraphicsEngine.Material.Material;
import main.java.GameEngine.GraphicsEngine.Material.Texture;
import main.java.GameEngine.GraphicsEngine.Mesh;
import main.java.GameEngine.GraphicsEngine.Renderer;
import main.java.GameEngine.GraphicsEngine.Shaders.StaticShader;
import main.java.GameEngine.GraphicsEngine.Vertex;
import main.java.GameEngine.Utils.Maths.Vector2f;
import main.java.GameEngine.Utils.Maths.Vector3f;
import main.java.GameEngine.Utils.MyLogging;

import java.util.logging.Level;

public class Main implements Runnable
{
    private Thread game;
    private DisplayManager displayManager;
    private Renderer renderer;
    private Mesh rectangle;
    private StaticShader shader;

    public void start()
    {
        MyLogging.log(Level.INFO, "Starting application.");
        game = new Thread(this, "ThemeParkManager");
        game.start();
    }

    public void init()
    {
        displayManager = new DisplayManager("Theme Park Designer", 1280, 720);
        renderer = new Renderer();
        displayManager.createDisplay();

        rectangle = new Mesh(new Vertex[]{
                new Vertex(new Vector3f(-0.5f, 0.5f, 0.0f), new Vector2f(0, 0)),
                new Vertex(new Vector3f(-0.5f, -0.5f, 0.0f), new Vector2f(0, 1)),
                new Vertex(new Vector3f(0.5f, 0.5f, 0.0f), new Vector2f(1, 0)),
                new Vertex(new Vector3f(0.5f, -0.5f, 0.0f), new Vector2f(1, 1))
        }, new int[]{
                0, 1, 2,
                2, 1, 3
        }, new Material(new Texture("assets/test.png")));
        rectangle.createVao();

        shader = new StaticShader();
    }

    public void run()
    {
        init();
        while (!displayManager.shouldClose())
        {
            renderer.prepare();
            // main.Main game loop here
            shader.start();
            render();
            shader.stop();
            update();
        }

        rectangle.cleanUp();
        shader.cleanUp();
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