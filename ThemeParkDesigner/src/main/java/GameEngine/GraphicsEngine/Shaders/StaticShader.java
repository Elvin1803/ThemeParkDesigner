package main.java.GameEngine.GraphicsEngine.Shaders;

public class StaticShader extends ShaderProgram
{
    private static final String VERTEX_FILE = "vertexShader.txt";
    private static final String FRAGMENT_FILE = "fragmentShader.txt";

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
