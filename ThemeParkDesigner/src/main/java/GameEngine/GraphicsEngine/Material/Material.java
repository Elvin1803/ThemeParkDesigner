package main.java.GameEngine.GraphicsEngine.Material;


import org.joml.Vector3f;

public class Material
{
    private final float shininess;
    private final Vector3f colorAmbient;
    private final Vector3f colorDiffuse;
    private final Vector3f colorSpecular;
    private final Vector3f colorEmission;
    private final float refraction;
    private final float illumination;

    private final Texture texture;

    public Material(Texture texture)
    {
        shininess = 1;
        colorAmbient = new Vector3f(1, 1, 1);
        colorDiffuse = new Vector3f(1, 1, 1);
        colorSpecular = new Vector3f(1, 1, 1);
        colorEmission = new Vector3f(0, 0, 0);
        refraction = 1;
        illumination = 1;

        this.texture = texture;
    }

    public Material(Vector3f color)
    {
        shininess = 1;
        colorAmbient = new Vector3f(1, 1, 1);
        colorDiffuse = color;
        colorSpecular = new Vector3f(1, 1, 1);
        colorEmission = new Vector3f(0, 0, 0);
        refraction = 1;
        illumination = 1;

        texture = null;
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
