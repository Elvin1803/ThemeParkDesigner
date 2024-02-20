package main.java.GameEngine.GraphicsEngine;

import main.java.GameEngine.Utils.Maths.Vector3f;

public class Vertex
{
    private Vector3f position;

    public Vertex(Vector3f position)
    {
        this.position = position;
    }

    public Vector3f getPosition()
    {
        return position;
    }
}
