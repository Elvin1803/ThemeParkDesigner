package main.java.GameEngine;

import main.java.GameEngine.ECS.Entity;
import main.java.GameEngine.GraphicsEngine.Camera;

import java.util.ArrayList;
import java.util.List;

public class Scene
{
    protected Camera camera = new Camera();
    protected List<Entity> entities = new ArrayList<>();

    public Scene(){}

    public void update(){}

    protected void renderScene(Camera camera)
    {
        camera.prepare();
        camera.renderEntities(this.entities);
    }

    public void addEntity(Entity entity)
    {
        entities.add(entity);
    }

    public List<Entity> getEntities()
    {
        return entities;
    }

    public void cleanUp()
    {
        for (Entity entity : entities)
        {
            /*
            entity.cleanUp();
             */
        }

        camera.cleanUp();
    }
}
