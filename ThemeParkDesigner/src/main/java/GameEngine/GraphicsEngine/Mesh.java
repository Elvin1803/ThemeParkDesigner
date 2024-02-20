package main.java.GameEngine.GraphicsEngine;

import org.lwjgl.opengl.*;

import org.lwjgl.system.MemoryUtil;

import java.nio.FloatBuffer;
import java.nio.IntBuffer;

public class Mesh
{
    private Vertex[] vertices;
    private int[] indices;

    private int vaoId;
    private int vboId;
    private int iboId;

    public Mesh(Vertex[] vertices, int[] indices)
    {
        this.vertices = vertices;
        this.indices = indices;
    }

    public void createVao()
    {
        vaoId = GL30.glGenVertexArrays();
        GL30.glBindVertexArray(vaoId);

        FloatBuffer verticesBuffer = MemoryUtil.memAllocFloat(vertices.length * 3);
        if (verticesBuffer == null)
        {
            throw new RuntimeException("Mesh constructor: Not enough memory !");
        }

        float[] tempVertices = new float[vertices.length * 3];
        for (int i = 0; i < vertices.length; i++)
        {
            tempVertices[i * 3] = vertices[i].getPosition().getX();
            tempVertices[i * 3 + 1] = vertices[i].getPosition().getY();
            tempVertices[i * 3 + 2] = vertices[i].getPosition().getZ();
        }
        verticesBuffer.put(tempVertices).flip();

        vboId = GL15.glGenBuffers();
        GL15.glBindBuffer(GL15.GL_ARRAY_BUFFER, vboId);
        GL15.glBufferData(GL15.GL_ARRAY_BUFFER, verticesBuffer, GL15.GL_STATIC_DRAW);
        GL20.glVertexAttribPointer(0, 3, GL11.GL_FLOAT, false, 0, 0);
        GL15.glBindBuffer(GL15.GL_ARRAY_BUFFER, 0);

        IntBuffer indicesBuffer = MemoryUtil.memAllocInt(indices.length);
        if (indicesBuffer == null)
        {
            throw new RuntimeException("Mesh constructor: Not enough memory !");
        }
        indicesBuffer.put(indices).flip();

        iboId = GL15.glGenBuffers();
        GL15.glBindBuffer(GL15.GL_ELEMENT_ARRAY_BUFFER, iboId);
        GL15.glBufferData(GL15.GL_ELEMENT_ARRAY_BUFFER, indicesBuffer, GL15.GL_STATIC_DRAW);
        GL15.glBindBuffer(GL15.GL_ELEMENT_ARRAY_BUFFER, 0);

        MemoryUtil.memFree(verticesBuffer);
        MemoryUtil.memFree(indicesBuffer);
    }

    public void cleanUp() {
        GL20.glDisableVertexAttribArray(0);

        // Delete the VBOs
        GL15.glBindBuffer(GL15.GL_ARRAY_BUFFER, 0);
        GL15.glDeleteBuffers(vboId);
        GL15.glDeleteBuffers(iboId);

        // Delete the VAO
        GL30.glBindVertexArray(0);
        GL30.glDeleteVertexArrays(vaoId);
    }

    public Vertex[] getVertices()
    {
        return vertices;
    }

    public int[] getIndices()
    {
        return indices;
    }

    public int getVaoId()
    {
        return vaoId;
    }

    public int getVboId()
    {
        return vboId;
    }

    public int getIboId()
    {
        return iboId;
    }
}
