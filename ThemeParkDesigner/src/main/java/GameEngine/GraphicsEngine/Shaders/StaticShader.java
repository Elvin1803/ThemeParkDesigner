package main.java.GameEngine.GraphicsEngine.Shaders;

public class StaticShader extends ShaderProgram
{
    private static final String VERTEX_FILE = "Scene/gbuffer.vert";
    private static final String FRAGMENT_FILE = "Scene/gbuffer.frag";

    public StaticShader()
    {
        super(VERTEX_FILE, FRAGMENT_FILE);
    }

    @Override
    protected void bindAttributes()
    {
        super.bindAttribute(0, "position");
        super.bindAttribute(1, "textureCoords");
    }
}
