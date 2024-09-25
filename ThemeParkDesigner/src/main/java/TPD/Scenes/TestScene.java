package main.java.TPD.Scenes;

import main.java.GameEngine.ECS.Entity;
import main.java.GameEngine.GraphicsEngine.Material.Material;
import main.java.GameEngine.GraphicsEngine.Material.Texture;
import main.java.GameEngine.GraphicsEngine.Model.Mesh;
import main.java.GameEngine.GraphicsEngine.Model.Model;
import main.java.GameEngine.GraphicsEngine.Model.Vertex;
import main.java.GameEngine.Scene;
import org.joml.Vector2f;
import org.joml.Vector3f;

import java.util.ArrayList;
import java.util.List;

public class TestScene extends Scene
{
    /*
    public TestScene()
    {
        this.entities = new ArrayList<>();

        Mesh triangle0 = new Mesh(new Vertex[]{
                new Vertex(new Vector3f(-0.6f, 0.5f, 1), new Vector2f(0, 0)),
                new Vertex(new Vector3f(-0.6f, -0.5f, 1), new Vector2f(0, 1)),
                new Vertex(new Vector3f(0.4f, 0.5f, 1), new Vector2f(1, 0))
        }, new int[]{
                0, 1, 2
        }, new Material(new Texture("assets/test.png")));
        triangle0.createVao();

        Mesh triangle1 = new Mesh(new Vertex[]{
                new Vertex(new Vector3f(-0.5f, -0.5f, -1), new Vector2f(0, 1)),
                new Vertex(new Vector3f(0.5f, 0.5f, -1), new Vector2f(1, 0)),
                new Vertex(new Vector3f(0.5f, -0.5f, -1), new Vector2f(1, 1)),
        }, new int[]{
                0, 1, 2
        }, new Material(new Texture("assets/test.png")));
        triangle1.createVao();


        List<Mesh> temp = new ArrayList<>();
        temp.add(triangle0);
        temp.add(triangle1);

        Model model = new Model(temp);
        Entity entity = new Entity(model);

        entity.setPosition(new Vector3f(0,0,0));
        entity.setRotation(new Vector3f(0,0,0));
        entity.setScale(new Vector3f(1,1,1));

        this.addEntity(entity);
    }

    @Override
    public void update()
    {
        Entity entity = entities.get(0);
        entity.setRotation(new Vector3f(entity.getRotation().x, entity.getRotation().y + 0.01f, entity.getRotation().z));

        camera.setPosRot(camera.getPosition(), new Vector3f(camera.getRotation().x, camera.getRotation().y + 0.01f, camera.getRotation().z));
        renderScene(camera);
    }
     */
}
