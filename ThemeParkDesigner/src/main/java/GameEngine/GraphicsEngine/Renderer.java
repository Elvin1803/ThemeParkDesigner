package main.java.GameEngine.GraphicsEngine;

import main.java.GameEngine.DisplayManager;
import main.java.GameEngine.GraphicsEngine.Model.Mesh;
import main.java.GameEngine.GraphicsEngine.Model.Model;
import main.java.GameEngine.GraphicsEngine.Shaders.StaticShader;
import main.java.GameEngine.Utils.Maths.Matricks;
import main.java.GameEngine.Utils.MyLogging;
import main.java.TPD.Scene;
import org.joml.Matrix4f;
import org.lwjgl.opengl.GL11;
import org.lwjgl.opengl.GL13;
import org.lwjgl.opengl.GL30;

import java.util.logging.Level;

public class Renderer
{
    private static final StaticShader shader = new StaticShader();

    public Renderer()
    {
        updateProjectionMatrix();
        updateViewMatrix();
    }

    public void prepare()
    {
        GL11.glEnable(GL11.GL_DEPTH_TEST);
        GL11.glClear(GL11.GL_COLOR_BUFFER_BIT|GL11.GL_DEPTH_BUFFER_BIT);
        GL11.glClearColor(1, 1, 1, 1);
    }

    public void renderScene(Scene scene)
    {
        shader.start();

        for (Entity entity : scene.getEntities())
        {
            renderEntity(entity);
        }

        shader.stop();
    }

    private void renderEntity(Entity entity)
    {
        Model model = entity.getModel();
        Matrix4f transformationMatrix = Matricks.createTransformationMatrix(entity.getPosition(), entity.getRotation(), entity.getScale());

        //MyLogging.log(Level.INFO, "Transformation matrix: \n" + transformationMatrix);
        shader.loadTransformationMatrix(transformationMatrix);

        for (Mesh mesh : model.getMeshes())
        {
            renderMesh(mesh);
        }
    }

    private void renderMesh(Mesh mesh)
    {
        GL30.glBindVertexArray(mesh.getVaoID());
        GL30.glEnableVertexAttribArray(0); // Vertex Position
        GL30.glEnableVertexAttribArray(1); // Texture Coordinates
        GL13.glActiveTexture(GL13.GL_TEXTURE0);
        GL11.glBindTexture(GL11.GL_TEXTURE_2D, mesh.getMaterial().getTexture().getTextureID());
        GL11.glDrawElements(GL11.GL_TRIANGLES, mesh.getIndices().length, GL11.GL_UNSIGNED_INT, 0);
        GL30.glDisableVertexAttribArray(0);
        GL30.glDisableVertexAttribArray(1);
        GL30.glBindVertexArray(0);
    }

    public static void updateProjectionMatrix()
    {
        float NEAR_PLANE = 0.1f;
        float FAR_PLANE = 1000;

        Matrix4f projectionMatrix = new Matrix4f();
        projectionMatrix.setPerspective(
                (float)Math.toRadians(Camera.getFOV()),
                ((float) DisplayManager.getWidth() / (float) DisplayManager.getHeight()),
                NEAR_PLANE,
                FAR_PLANE);

        shader.start();
        //MyLogging.log(Level.INFO, "Projection matrix: \n" + projectionMatrix);
        shader.loadProjectionMatrix(projectionMatrix);
        shader.stop();
    }

    public static void updateViewMatrix()
    {
        Matrix4f viewMatrix = Matricks.createViewMatrix(Camera.getPosition(), Camera.getRotation());

        shader.start();
        //MyLogging.log(Level.INFO, "View matrix: \n" + viewMatrix);
        shader.loadViewMatrix(viewMatrix);
        shader.stop();
    }

    public void cleanUp()
    {
        shader.cleanUp();
    }
}
