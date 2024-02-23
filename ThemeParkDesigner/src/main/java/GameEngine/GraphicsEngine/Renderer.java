package main.java.GameEngine.GraphicsEngine;

import main.java.GameEngine.GraphicsEngine.Shaders.StaticShader;
import main.java.TPD.Scene;
import org.lwjgl.opengl.GL11;
import org.lwjgl.opengl.GL13;
import org.lwjgl.opengl.GL30;

public class Renderer
{
    public void prepare()
    {
        GL11.glClearColor(1, 0, 0, 1);
        GL11.glClear(GL11.GL_COLOR_BUFFER_BIT);
    }

    public void renderScene(Scene scene)
    {
        StaticShader shader = new StaticShader();
        shader.start();
        for (Model model : scene.getModels())
        {
            renderModel(model);
        }
        shader.stop();
        shader.cleanUp();
    }

    private void renderModel(Model model)
    {
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
}
