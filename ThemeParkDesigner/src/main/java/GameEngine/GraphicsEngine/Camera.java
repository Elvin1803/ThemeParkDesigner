package main.java.GameEngine.GraphicsEngine;

import main.java.GameEngine.DisplayManager;
import main.java.GameEngine.GraphicsEngine.Model.Mesh;
import main.java.GameEngine.Utils.Maths.Matricks;
import main.java.GameEngine.Utils.MyLogging;
import org.joml.Matrix4f;
import org.joml.Vector3f;

import java.util.List;

public class Camera
{
    private final Renderer renderer;
    float NEAR_PLANE = 0.1f;
    float FAR_PLANE = 1000;
    private float FOV = 70;
    private Matrix4f projectionMatrix;

    private Vector3f position = new Vector3f(0,0,0);
    private Vector3f rotation = new Vector3f(0,0,0);
    private Matrix4f viewMatrix;

    public Camera()
    {
        projectionMatrix = new Matrix4f();
        projectionMatrix.setPerspective(
                (float)Math.toRadians(this.FOV),
                ((float) DisplayManager.getWidth() / (float) DisplayManager.getHeight()),
                NEAR_PLANE,
                FAR_PLANE);

        viewMatrix = Matricks.createViewMatrix(this.position, this.rotation);

        this.renderer = new Renderer(projectionMatrix, viewMatrix);
    }

    public void setFOV(float FOV)
    {
        this.FOV = FOV;

        projectionMatrix = new Matrix4f();
        projectionMatrix.setPerspective(
                (float)Math.toRadians(this.FOV),
                ((float) DisplayManager.getWidth() / (float) DisplayManager.getHeight()),
                NEAR_PLANE,
                FAR_PLANE);

        this.renderer.updateProjectionMatrix(projectionMatrix);
    }

    public void setPosRot(Vector3f position, Vector3f rotation)
    {
        this.position = position;
        this.rotation = rotation;
        viewMatrix = Matricks.createViewMatrix(this.position, this.rotation);

        this.renderer.updateViewMatrix(viewMatrix);
    }

    public float getFOV()
    {
        return this.FOV;
    }

    public Vector3f getPosition()
    {
        return this.position;
    }

    public Vector3f getRotation()
    {
        return this.rotation;
    }

    public void prepare()
    {
        this.renderer.prepare();
    }

    public void renderEntities(List<Entity> entities)
    {
        renderer.renderEntities(entities);
    }

    public void cleanUp()
    {
        this.renderer.cleanUp();
    }
}
