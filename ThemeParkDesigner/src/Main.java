import GameEngine.DisplayManager;
import GameEngine.GraphicsEngine.Mesh;
import GameEngine.GraphicsEngine.Renderer;
import GameEngine.GraphicsEngine.Vertex;
import Utils.Maths.Vector3f;
import Utils.MyLogging;

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
    }

    public void run()
    {
        init();
        while (!displayManager.shouldClose())
        {
            // Main game loop here
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
        renderer.renderMesh(rectangle);
        displayManager.swapBuffers();
    }

    public static void main(String[] args)
    {
        // Change to LEVEL.SEVERE for release
        MyLogging.getLogger().setLevel(Level.SEVERE);
        new Main().start();
    }
}