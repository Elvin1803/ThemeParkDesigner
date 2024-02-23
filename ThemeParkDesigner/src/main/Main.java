package main;

import main.java.GameEngine.DisplayManager;
import main.java.GameEngine.GraphicsEngine.Material.Material;
import main.java.GameEngine.GraphicsEngine.Material.Texture;
import main.java.GameEngine.GraphicsEngine.Mesh;
import main.java.GameEngine.GraphicsEngine.Model;
import main.java.GameEngine.GraphicsEngine.Renderer;
import main.java.GameEngine.GraphicsEngine.Shaders.StaticShader;
import main.java.GameEngine.GraphicsEngine.Vertex;
import main.java.GameEngine.Utils.Maths.Vector2f;
import main.java.GameEngine.Utils.Maths.Vector3f;
import main.java.GameEngine.Utils.MyLogging;
import main.java.TPD.Scene;

import java.util.ArrayList;
import java.util.List;
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
        renderer = new Renderer();
        displayManager.createDisplay();

        scene = new Scene();
    }

    public void run()
    {
        init();
        while (!displayManager.shouldClose())
        {
            renderer.prepare();
            // Main game loop here
            render();
            update();
        }

        scene.cleanUp();
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
        MyLogging.getLogger().setLevel(Level.SEVERE);
        MyLogging.log(Level.INFO, "PWD: " + System.getProperty("user.dir"));
        new Main().start();
    }
}