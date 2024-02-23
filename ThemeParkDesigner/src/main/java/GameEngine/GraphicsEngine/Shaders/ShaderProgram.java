package main.java.GameEngine.GraphicsEngine.Shaders;

import main.java.GameEngine.Utils.MyLogging;
import org.lwjgl.opengl.GL11;
import org.lwjgl.opengl.GL20;

import java.io.*;
import java.util.logging.Level;

public abstract class ShaderProgram
{
    private final int programID;
    private final int vertexShaderID;
    private final int fragmentShaderID;

    public ShaderProgram(String vertexFile, String fragmentFile)
    {
        vertexShaderID = loadShader(vertexFile, GL20.GL_VERTEX_SHADER);
        fragmentShaderID = loadShader(fragmentFile, GL20.GL_FRAGMENT_SHADER);
        programID = GL20.glCreateProgram();

        GL20.glAttachShader(programID, vertexShaderID);
        GL20.glAttachShader(programID, fragmentShaderID);
        GL20.glLinkProgram(programID);
        GL20.glValidateProgram(programID);
    }

    public void start()
    {
        GL20.glUseProgram(programID);
    }

    public void stop()
    {
        GL20.glUseProgram(0);
    }

    public void cleanUp()
    {
        stop();
        GL20.glDetachShader(programID, vertexShaderID);
        GL20.glDetachShader(programID, fragmentShaderID);
        GL20.glDeleteShader(vertexShaderID);
        GL20.glDeleteShader(fragmentShaderID);
        GL20.glDeleteProgram(programID);
    }

    protected abstract void bindAttributes();

    protected void bindAttribute(int attribute, String variableName)
    {
        GL20.glBindAttribLocation(programID, attribute, variableName);
    }

    private static int loadShader(String file, int type)
    {
        StringBuilder shaderSource = new StringBuilder();
        try
        {
            InputStream in = ShaderProgram.class.getResourceAsStream(file);
            if (in == null)
            {
                MyLogging.log(Level.SEVERE, "Couldn't find: " + file);
                System.exit(1);
            }
            BufferedReader reader = new BufferedReader(new InputStreamReader(in));
            String line;
            while ((line = reader.readLine()) != null)
            {
                shaderSource.append(line).append("\n");
            }
            reader.close();
        }
        catch (IOException e)
        {
            MyLogging.log(Level.SEVERE, "Couldn't read " + file);
            System.exit(-1);
        }
        int shaderID = GL20.glCreateShader(type);
        GL20.glShaderSource(shaderID, shaderSource);
        GL20.glCompileShader(shaderID);
        if (GL20.glGetShaderi(shaderID, GL20.GL_COMPILE_STATUS) == GL11.GL_FALSE)
        {
            MyLogging.log(Level.SEVERE, GL20.glGetShaderInfoLog(shaderID, 500));
            MyLogging.log(Level.SEVERE, "Could not compile shader!");
            System.exit(-1);
        }
        return shaderID;
    }
}
