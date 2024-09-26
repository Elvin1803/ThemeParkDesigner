package main.java.GameEngine;

import main.java.GameEngine.ECS.ECSManager;
import main.java.GameEngine.GraphicsEngine.Camera;

public class Scene
{
    protected Camera camera = new Camera();
    protected ECSManager ecs = new ECSManager();

    public Scene(){}

    public void update(){}

    protected void renderScene(Camera camera)
    {
        camera.prepare();
        //camera.renderEntities(this.entities);
    }

    public void cleanUp()
    {
        camera.cleanUp();
    }
}
