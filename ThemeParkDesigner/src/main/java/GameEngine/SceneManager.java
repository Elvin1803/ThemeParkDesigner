package main.java.GameEngine;

import main.java.GameEngine.Utils.MyLogging;

import java.util.logging.Level;

/*
 * Singleton class that helps keep track of the current scene
 * and helps switch scenes.
 */
public class SceneManager
{
    public static SceneManager instance;
    public Scene currentScene;

    public SceneManager(){}

    public static SceneManager getInstance()
    {
        if (instance == null)
        {
            instance = new SceneManager();
        }

        return instance;
    }

    public void update()
    {
        currentScene.update();
    }

    public static void changeScene(Scene newScene)
    {
        if (instance.currentScene != null)
        {
            instance.currentScene.cleanUp();
            MyLogging.log(Level.INFO, "Cleaned scene: " + instance.currentScene.getClass().getName());
        }

        instance.currentScene = newScene;
        MyLogging.log(Level.INFO, "Loaded new scene: " + newScene.getClass().getName());
    }
}
