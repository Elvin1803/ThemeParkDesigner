package main.java.GameEngine;

import main.java.GameEngine.GraphicsEngine.Camera;
import main.java.GameEngine.GraphicsEngine.Entity;
import main.java.GameEngine.GraphicsEngine.Material.Material;
import main.java.GameEngine.GraphicsEngine.Material.Texture;
import main.java.GameEngine.GraphicsEngine.Model.Mesh;
import main.java.GameEngine.GraphicsEngine.Model.Model;
import main.java.GameEngine.GraphicsEngine.Model.Vertex;
import org.joml.Vector2f;
import org.joml.Vector3f;

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
            entity.cleanUp();
        }

        camera.cleanUp();
    }
}
