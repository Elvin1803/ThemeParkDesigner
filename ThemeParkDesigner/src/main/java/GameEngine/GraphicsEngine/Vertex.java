package main.java.GameEngine.GraphicsEngine;

import main.java.GameEngine.Utils.Maths.Vector2f;
import main.java.GameEngine.Utils.Maths.Vector3f;

public class Vertex
{
    private final Vector3f position;
    private final Vector2f textureCoords;

    public Vertex(Vector3f position)
    {
        this.position = position;
        textureCoords = new Vector2f(0.0f, 0.0f);
    }

    public Vertex(Vector3f position, Vector2f textureCoords)
    {
        this.position = position;
        this.textureCoords = textureCoords;
    }

    public Vector3f getPosition()
    {
        return position;
    }

    public Vector2f getTextureCoords()
    {
        return textureCoords;
    }
}
