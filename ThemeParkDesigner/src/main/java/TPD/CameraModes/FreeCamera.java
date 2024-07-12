package main.java.TPD.CameraModes;

import main.java.GameEngine.KeyListener;
import main.java.GameEngine.Utils.MyLogging;
import main.java.TPD.Settings.KeyMap;
import org.joml.Vector3f;
import org.lwjgl.glfw.GLFW;

import java.util.logging.Level;

public class FreeCamera extends CameraMode
{
    @Override
    protected boolean moveCamera()
    {
        Vector3f prevPos = position;

        if (KeyListener.isKeyPressed(KeyMap.keyMap.get(KeyMap.KeyMapping.FORWARD)))
        {
            //MyLogging.log(Level.INFO, "Moving forward.");
            position = new Vector3f(position.x, position.y, position.z - 0.01f);
        }
        if (KeyListener.isKeyPressed(KeyMap.keyMap.get(KeyMap.KeyMapping.BACKWARD)))
        {
            //MyLogging.log(Level.INFO, "Moving backward.");
            position = new Vector3f(position.x, position.y, position.z + 0.01f);
        }
        if (KeyListener.isKeyPressed(KeyMap.keyMap.get(KeyMap.KeyMapping.LEFT)))
        {
            //MyLogging.log(Level.INFO, "Moving left.");
            position = new Vector3f(position.x - 0.01f, position.y, position.z);
        }
        if (KeyListener.isKeyPressed(KeyMap.keyMap.get(KeyMap.KeyMapping.RIGHT)))
        {
            //MyLogging.log(Level.INFO, "Moving right.");
            position = new Vector3f(position.x + 0.01f, position.y, position.z);
        }

        return position != prevPos;
    }
}
