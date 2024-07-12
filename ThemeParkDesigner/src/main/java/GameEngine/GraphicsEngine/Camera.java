package main.java.GameEngine.GraphicsEngine;

import main.java.GameEngine.DisplayManager;
import main.java.GameEngine.Utils.Maths.Matricks;
import main.java.GameEngine.Utils.MyLogging;
import org.joml.Matrix4f;
import org.joml.Vector3f;

import java.util.logging.Level;

public class Camera
{
    private static float FOV = 70;
    private static Vector3f position = new Vector3f(0,0,0);
    private static Vector3f rotation = new Vector3f(0,0,0);

    public Camera(){}

    public static void setFOV(float FOV)
    {
        Camera.FOV = FOV;

        Renderer.updateProjectionMatrix();
    }

    public static void setPosition(Vector3f position)
    {
        Camera.position = position;

        Renderer.updateViewMatrix();
    }

    public static void setRotation(Vector3f rotation)
    {
        Camera.rotation = rotation;

        Renderer.updateViewMatrix();
    }

    public static float getFOV()
    {
        return FOV;
    }

    public static Vector3f getPosition()
    {
        return position;
    }

    public static Vector3f getRotation()
    {
        return rotation;
    }
}
