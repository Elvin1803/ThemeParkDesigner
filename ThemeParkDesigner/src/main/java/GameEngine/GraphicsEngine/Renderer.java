package main.java.GameEngine.GraphicsEngine;

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
    int width;
    int height;
    private float FOV = 90;

    private final StaticShader shader = new StaticShader();

    public Renderer(int width, int height)
    {
        this.width = width;
        this.height = height;

        updateProjectionMatrix();
    }

    public void setFOV(float FOV)
    {
        this.FOV = FOV;

        updateProjectionMatrix();
    }

    public void setWidth(int width)
    {
        this.width = width;

        updateProjectionMatrix();
    }

    public void setHeight(int height)
    {
        this.height = height;

        updateProjectionMatrix();
    }

    public void prepare()
    {
        GL11.glClearColor(1, 0, 0, 1);
        GL11.glClear(GL11.GL_COLOR_BUFFER_BIT);
    }

    public void renderScene(Scene scene)
    {
        shader.start();

        for (Entity entity : scene.getEntities())
        {
            renderEntity(entity, shader);
        }

        shader.stop();
    }

    private void renderEntity(Entity entity, StaticShader shader)
    {
        Model model = entity.getModel();
        Matrix4f transformationMatrix = Matricks.createTransformationMatrix(entity.getPosition(), entity.getRotation(), entity.getScale());

        MyLogging.log(Level.INFO, "Transformation matrix: \n" + transformationMatrix);
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

    private void updateProjectionMatrix()
    {
        float NEAR_PLANE = 0.1f;
        float FAR_PLANE = 1000;

        Matrix4f projectionMatrix = new Matrix4f();
        projectionMatrix.setPerspective((float)Math.toRadians(FOV), (float) width / (float) height, NEAR_PLANE, FAR_PLANE);

        shader.start();
        MyLogging.log(Level.INFO, "Projection matrix: \n" + projectionMatrix);
        shader.loadProjectionMatrix(projectionMatrix);
        shader.stop();
    }

    public void cleanUp()
    {
        shader.cleanUp();
    }
}
