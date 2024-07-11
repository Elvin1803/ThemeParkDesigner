package main.java.GameEngine.GraphicsEngine.Model;

import main.java.GameEngine.GraphicsEngine.Material.Material;
import main.java.GameEngine.GraphicsEngine.Material.Texture;
import org.lwjgl.opengl.*;

import org.lwjgl.system.MemoryUtil;

import java.nio.FloatBuffer;
import java.nio.IntBuffer;
import java.util.ArrayList;
import java.util.List;

public class Mesh
{
    private final Vertex[] vertices;
    private final int[] indices;

    private int vaoID;
    private List<Integer> vbos;
    private Material material;

    public Mesh(Vertex[] vertices, int[] indices)
    {
        this.vertices = vertices;
        this.indices = indices;
    }

    public Mesh(Vertex[] vertices, int[] indices, Material material)
    {
        this.vertices = vertices;
        this.indices = indices;
        this.material = material;
    }

    /*
     * The Vao of the mesh will be created.
     * The vertices' position will be stored in the attrib 0.
     * The texture coordinates will be stored in the attrib 1.
     *
     * The index buffer is stored automatically by OpenGL.
     */
    public void createVao()
    {
        vaoID = GL30.glGenVertexArrays();
        GL30.glBindVertexArray(vaoID);

        vbos = new ArrayList<>();

        // Store the position of all vertices
        FloatBuffer verticesBuffer = MemoryUtil.memAllocFloat(vertices.length * 3);
        float[] tempVertices = new float[vertices.length * 3];
        for (int i = 0; i < vertices.length; i++)
        {
            tempVertices[i * 3] = vertices[i].getPosition().x();
            tempVertices[i * 3 + 1] = vertices[i].getPosition().y();
            tempVertices[i * 3 + 2] = vertices[i].getPosition().z();
        }
        verticesBuffer.put(tempVertices).flip();
        storeInAttrib(verticesBuffer, 0, 3);

        // Store index buffer
        IntBuffer indicesBuffer = MemoryUtil.memAllocInt(indices.length);
        indicesBuffer.put(indices).flip();
        int iboID = GL15.glGenBuffers();
        GL15.glBindBuffer(GL15.GL_ELEMENT_ARRAY_BUFFER, iboID); // OpenGL knows it is the index buffer
        GL15.glBufferData(GL15.GL_ELEMENT_ARRAY_BUFFER, indicesBuffer, GL15.GL_STATIC_DRAW);
        vbos.add(iboID);

        // Store texture coordinates
        FloatBuffer texCoordsBuffer = MemoryUtil.memAllocFloat(vertices.length * 2);
        float[] tempTexCoords = new float[vertices.length * 2];
        for (int i = 0; i < vertices.length; i++)
        {
            tempTexCoords[i * 2] = vertices[i].getTextureCoords().x();
            tempTexCoords[i * 2 + 1] = vertices[i].getTextureCoords().y();
        }
        texCoordsBuffer.put(tempTexCoords).flip();
        storeInAttrib(texCoordsBuffer, 1, 2);

        // Free all buffers
        MemoryUtil.memFree(verticesBuffer);
        MemoryUtil.memFree(indicesBuffer);
        MemoryUtil.memFree(texCoordsBuffer);
    }

    public void storeInAttrib(FloatBuffer buffer, int index, int size)
    {
        int bufferID = GL15.glGenBuffers();
        GL15.glBindBuffer(GL15.GL_ARRAY_BUFFER, bufferID);
        GL15.glBufferData(GL15.GL_ARRAY_BUFFER, buffer, GL15.GL_STATIC_DRAW);
        GL20.glVertexAttribPointer(index, size, GL11.GL_FLOAT, false, 0, 0);
        GL15.glBindBuffer(GL15.GL_ARRAY_BUFFER, 0);
        vbos.add(bufferID);
    }

    public void cleanUp()
    {
        GL20.glDisableVertexAttribArray(0);

        // Delete the VBOs
        GL15.glBindBuffer(GL15.GL_ARRAY_BUFFER, 0);
        for (Integer vbo : vbos)
        {
            GL15.glDeleteBuffers(vbo);
        }

        // Delete the texture
        Texture texture = material.getTexture();
        if (texture != null)
        {
            texture.cleanUp();
        }

        // Delete the VAO
        GL30.glBindVertexArray(0);
        GL30.glDeleteVertexArrays(vaoID);
    }

    public int[] getIndices()
    {
        return indices;
    }

    public int getVaoID()
    {
        return vaoID;
    }

    public Material getMaterial()
    {
        return material;
    }
}
