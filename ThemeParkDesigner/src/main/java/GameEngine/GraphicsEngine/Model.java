package main.java.GameEngine.GraphicsEngine;

import java.util.List;

public class Model
{
    private final List<Mesh> meshes;

    public Model(List<Mesh> meshes)
    {
        this.meshes = meshes;
    }

    public List<Mesh> getMeshes()
    {
        return meshes;
    }

    public void cleanUp()
    {
        for (Mesh mesh : meshes)
        {
            mesh.cleanUp();
        }
    }
}
