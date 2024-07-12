package main.java.GameEngine.Utils.Maths;

import org.joml.Matrix4f;
import org.joml.Quaternionf;
import org.joml.Vector3f;

public class Matricks
{
    public static Matrix4f createTransformationMatrix(Vector3f position, Vector3f rotation, Vector3f scale)
    {
        Matrix4f matrix = new Matrix4f();
        matrix.identity();
        matrix.translate(position);
        matrix.rotateXYZ(rotation);
        matrix.scale(scale);

        return matrix;
    }

    public static Matrix4f createViewMatrix(Vector3f position, Vector3f rotation)
    {
        Matrix4f matrix = new Matrix4f();
        matrix.identity();
        matrix.rotateXYZ(rotation);
        matrix.translate(-position.x, -position.y, -position.z);

        return matrix;
    }
}
