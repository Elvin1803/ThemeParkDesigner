package main.java.GameEngine.GraphicsEngine.Material;

import main.java.GameEngine.Utils.Maths.Vector3f;
import org.lwjgl.opengl.GL11;

public class Material
{
    private float shininess;
    private Vector3f colorAmbient;
    private Vector3f colorDiffuse;
    private Vector3f colorSpecular;
    private Vector3f colorEmission;
    private float refraction;
    private float illumination;

    private Texture texture;

    public Material(Texture texture)
    {
        shininess = 1;
        colorAmbient = new Vector3f(1, 1, 1);
        colorDiffuse = new Vector3f(1, 1, 1);
        colorSpecular = new Vector3f(1, 1, 1);
        colorEmission = new Vector3f(1, 1, 1);
        refraction = 1;
        illumination = 1;

        this.texture = texture;
    }

    public Material(float shininess, Vector3f colorAmbient, Vector3f colorDiffuse, Vector3f colorSpecular, Vector3f colorEmission, float refraction, float illumination, Texture texture)
    {
        this.shininess = shininess;
        this.colorAmbient = colorAmbient;
        this.colorDiffuse = colorDiffuse;
        this.colorSpecular = colorSpecular;
        this.colorEmission = colorEmission;
        this.refraction = refraction;
        this.illumination = illumination;
        this.texture = texture;
    }

    public void cleanUp()
    {
        GL11.glDeleteTextures(texture.getTextureID());
    }

    public float getShininess()
    {
        return shininess;
    }

    public Vector3f getColorAmbient()
    {
        return colorAmbient;
    }

    public Vector3f getColorDiffuse()
    {
        return colorDiffuse;
    }

    public Vector3f getColorSpecular()
    {
        return colorSpecular;
    }

    public Vector3f getColorEmission()
    {
        return colorEmission;
    }

    public float getRefraction()
    {
        return refraction;
    }

    public float getIllumination()
    {
        return illumination;
    }

    public Texture getTexture()
    {
        return texture;
    }
}
