package main.java.GameEngine.GraphicsEngine;

import main.java.GameEngine.GraphicsEngine.Model.Model;
import org.joml.Vector3f;

public class Entity
{
    private final Model model;

    private Vector3f position;
    private Vector3f rotation;
    private Vector3f scale;

    public Entity(Model model)
    {
        this.model = model;
    }

    public void setPosition(Vector3f position)
    {
        this.position = position;
    }

    public void setRotation(Vector3f rotation)
    {
        this.rotation = rotation;
    }

    public void setScale(Vector3f scale)
    {
        this.scale = scale;
    }

    public Model getModel()
    {
        return model;
    }

    public Vector3f getPosition()
    {
        return position;
    }

    public Vector3f getRotation()
    {
        return rotation;
    }

    public Vector3f getScale()
    {
        return scale;
    }

    public void cleanUp()
    {
        this.model.cleanUp();
    }
}
