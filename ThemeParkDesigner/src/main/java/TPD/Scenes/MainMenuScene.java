package main.java.TPD.Scenes;

import main.java.GameEngine.ECS.Component;
import main.java.GameEngine.ECS.Components.NameComponent;
import main.java.GameEngine.ECS.Components.TransformComponent;
import main.java.GameEngine.Scene;

public class MainMenuScene extends Scene
{
    public MainMenuScene()
    {
        int newGameButton = ecs.create();
        ecs.emplace(newGameButton, new NameComponent("new game button"), NameComponent.class);
        ecs.emplace(newGameButton, new TransformComponent(), TransformComponent.class);

        int player = ecs.create();
        ecs.emplace(player, new TransformComponent(), TransformComponent.class);

        int continueGameButton = ecs.create();
        ecs.emplace(continueGameButton, new NameComponent("continue game button"), NameComponent.class);
        ecs.emplace(continueGameButton, new TransformComponent(), TransformComponent.class);
    }
}
