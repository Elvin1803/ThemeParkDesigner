package main.java.TPD.CameraModes;

import main.java.GameEngine.Utils.KeyListener;
import main.java.TPD.Settings.KeyMap;
import org.joml.Vector3f;

public class FreeCamera extends CameraMode
{
    float default_speed = 0.01f;

    @Override
    protected boolean moveCamera()
    {
        Vector3f prevPos = position;

        /*
         * 2 if sprint key is pressed, 1 otherwise.
         * Used to multiply speed
         */
        int speed_coef = KeyListener.isKeyPressed(KeyMap.keyMap.get(KeyMap.KeyMapping.SPRINT)) ? 2 : 1;

        if (KeyListener.isKeyPressed(KeyMap.keyMap.get(KeyMap.KeyMapping.FORWARD)))
        {
            //MyLogging.log(Level.INFO, "Moving forward.");
            position = new Vector3f(position.x, position.y, position.z - default_speed * speed_coef);
        }
        if (KeyListener.isKeyPressed(KeyMap.keyMap.get(KeyMap.KeyMapping.BACKWARD)))
        {
            //MyLogging.log(Level.INFO, "Moving backward.");
            position = new Vector3f(position.x, position.y, position.z + default_speed * speed_coef);
        }
        if (KeyListener.isKeyPressed(KeyMap.keyMap.get(KeyMap.KeyMapping.LEFT)))
        {
            //MyLogging.log(Level.INFO, "Moving left.");
            position = new Vector3f(position.x - default_speed * speed_coef, position.y, position.z);
        }
        if (KeyListener.isKeyPressed(KeyMap.keyMap.get(KeyMap.KeyMapping.RIGHT)))
        {
            //MyLogging.log(Level.INFO, "Moving right.");
            position = new Vector3f(position.x + default_speed * speed_coef, position.y, position.z);
        }
        if (KeyListener.isKeyPressed(KeyMap.keyMap.get(KeyMap.KeyMapping.JUMP)))
        {
            //MyLogging.log(Level.INFO, "Jumping");
            position = new Vector3f(position.x, position.y + default_speed, position.z);
        }
        if (KeyListener.isKeyPressed(KeyMap.keyMap.get(KeyMap.KeyMapping.CROUCH)))
        {
            //MyLogging.log(Level.INFO, "Crouching");
            position = new Vector3f(position.x, position.y - default_speed, position.z);
        }

        return position != prevPos;
    }
}
