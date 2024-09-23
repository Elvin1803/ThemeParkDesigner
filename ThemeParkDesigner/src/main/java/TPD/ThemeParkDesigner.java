package main.java.TPD;

import main.java.GameEngine.Application;
import main.java.GameEngine.SceneManager;
import main.java.TPD.Scenes.MainMenuScene;
import main.java.TPD.Scenes.TestScene;

public class ThemeParkDesigner extends Application
{
    public ThemeParkDesigner()
    {
        super("Theme Park Designer");
        SceneManager.changeScene(new MainMenuScene());

        try
        {
            Thread.sleep(3000);
        }
        catch (InterruptedException e)
        {
            throw new RuntimeException(e);
        }

        SceneManager.changeScene(new TestScene());
    }
}