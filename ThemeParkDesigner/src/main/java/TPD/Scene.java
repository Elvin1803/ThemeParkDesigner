package main.java.TPD;

import main.java.GameEngine.GraphicsEngine.Material.Material;
import main.java.GameEngine.GraphicsEngine.Material.Texture;
import main.java.GameEngine.GraphicsEngine.Mesh;
import main.java.GameEngine.GraphicsEngine.Model;
import main.java.GameEngine.GraphicsEngine.Vertex;
import main.java.GameEngine.Utils.Maths.Vector2f;
import main.java.GameEngine.Utils.Maths.Vector3f;

import java.util.ArrayList;
import java.util.List;

public class Scene
{
    private List<Model> models;

    public Scene()
    {
        this.models = new ArrayList<>();

        Mesh triangle0 = new Mesh(new Vertex[]{
                new Vertex(new Vector3f(-0.6f, 0.5f, 0.0f), new Vector2f(0, 0)),
                new Vertex(new Vector3f(-0.6f, -0.5f, 0.0f), new Vector2f(0, 1)),
                new Vertex(new Vector3f(0.4f, 0.5f, 0.0f), new Vector2f(1, 0))
        }, new int[]{
                0, 1, 2
        }, new Material(new Texture("assets/test.png")));
        triangle0.createVao();

        Mesh triangle1 = new Mesh(new Vertex[]{
                new Vertex(new Vector3f(-0.5f, -0.5f, 0.0f), new Vector2f(0, 1)),
                new Vertex(new Vector3f(0.5f, 0.5f, 0.0f), new Vector2f(1, 0)),
                new Vertex(new Vector3f(0.5f, -0.5f, 0.0f), new Vector2f(1, 1)),
        }, new int[]{
                0, 1, 2
        }, new Material(new Texture("assets/test.png")));
        triangle1.createVao();


        List<Mesh> temp = new ArrayList<>();
        temp.add(triangle0);
        temp.add(triangle1);

        this.addModel(new Model(temp));
    }

    public void addModel(Model model)
    {
        models.add(model);
    }

    public List<Model> getModels()
    {
        return models;
    }

    public void cleanUp()
    {
        for (Model model : models)
        {
            model.cleanUp();
        }
    }
}
