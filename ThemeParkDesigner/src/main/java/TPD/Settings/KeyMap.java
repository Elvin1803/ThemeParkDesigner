package main.java.TPD.Settings;

import org.lwjgl.glfw.GLFW;

import java.util.HashMap;

public class KeyMap
{
    public static HashMap<KeyMapping, Integer> keyMap = new HashMap<KeyMapping, Integer>();

    public KeyMap()
    {
        // check for a config.ini or smth idk
        keyMap.put(KeyMapping.FORWARD, GLFW.GLFW_KEY_W);
        keyMap.put(KeyMapping.BACKWARD, GLFW.GLFW_KEY_S);
        keyMap.put(KeyMapping.LEFT, GLFW.GLFW_KEY_A);
        keyMap.put(KeyMapping.RIGHT, GLFW.GLFW_KEY_D);
    }

    public enum KeyMapping
    {
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT
    }
}
