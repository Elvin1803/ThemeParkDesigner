package main.java.GameEngine.GraphicsEngine.Material;

import main.java.GameEngine.Utils.MyLogging;
import org.lwjgl.BufferUtils;
import org.lwjgl.opengl.GL11;
import org.lwjgl.opengl.GL12;
import org.lwjgl.opengl.GL30;
import org.lwjgl.stb.STBImage;

import java.nio.ByteBuffer;
import java.nio.IntBuffer;
import java.util.logging.Level;

import static org.lwjgl.stb.STBImage.*;

public class Texture
{
    private int textureID;

    private int width;
    private int height;
    private int nrChannels;

    public Texture(String texturePath)
    {
        IntBuffer width = BufferUtils.createIntBuffer(1);
        IntBuffer height = BufferUtils.createIntBuffer(1);
        IntBuffer nrChannels = BufferUtils.createIntBuffer(1);

        ByteBuffer data = stbi_load(texturePath, width, height, nrChannels, 0);
        if (data == null)
        {
            MyLogging.log(Level.WARNING, "Could not decode image file [" + texturePath + "]: [" + STBImage.stbi_failure_reason() + "]");
            return;
        }

        MyLogging.log(Level.INFO, "Texture: " + texturePath + "\nImage width: " + width.get(0) + "\nImage height: " + height.get(0) + "\nImage nrChannels: " + nrChannels.get(0));
        this.width = width.get(0);
        this.height = height.get(0);
        this.nrChannels = nrChannels.get(0);
        textureID = GL11.glGenTextures();

        GL11.glBindTexture(GL11.GL_TEXTURE_2D, textureID);
        GL11.glTexParameteri(GL11.GL_TEXTURE_2D, GL11.GL_TEXTURE_MAG_FILTER, GL11.GL_LINEAR);
        GL11.glTexParameteri(GL11.GL_TEXTURE_2D, GL11.GL_TEXTURE_MIN_FILTER, GL11.GL_LINEAR_MIPMAP_LINEAR);
        GL11.glTexParameteri(GL11.GL_TEXTURE_2D, GL11.GL_TEXTURE_WRAP_S, GL12.GL_CLAMP_TO_EDGE);
        GL11.glTexParameteri(GL11.GL_TEXTURE_2D, GL11.GL_TEXTURE_WRAP_T, GL12.GL_CLAMP_TO_EDGE);

        GL11.glTexImage2D(GL11.GL_TEXTURE_2D, 0, GL11.GL_RGBA, width.get(0), height.get(0), 0, GL11.GL_RGBA, GL11.GL_UNSIGNED_BYTE, data);
        GL30.glGenerateMipmap(GL11.GL_TEXTURE_2D);

        stbi_image_free(data);
    }

    public int getTextureID()
    {
        return textureID;
    }

    public int getWidth()
    {
        return width;
    }

    public int getHeight()
    {
        return height;
    }

    public int getNrChannels()
    {
        return nrChannels;
    }

    public void cleanUp()
    {
        GL11.glDeleteTextures(this.textureID);
    }
}
