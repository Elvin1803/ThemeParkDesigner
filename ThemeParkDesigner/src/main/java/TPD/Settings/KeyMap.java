package main.java.TPD.Settings;

import org.lwjgl.glfw.GLFW;

import java.util.HashMap;

public class KeyMap
{
    public static HashMap<KeyMapping, Integer> keyMap = new HashMap<>();

    public KeyMap()
    {
        // check for a config.ini or something I don't know
        keyMap.put(KeyMapping.FORWARD, GLFW.GLFW_KEY_W);
        keyMap.put(KeyMapping.BACKWARD, GLFW.GLFW_KEY_S);
        keyMap.put(KeyMapping.LEFT, GLFW.GLFW_KEY_A);
        keyMap.put(KeyMapping.RIGHT, GLFW.GLFW_KEY_D);
        keyMap.put(KeyMapping.SPRINT, GLFW.GLFW_KEY_LEFT_SHIFT);
        keyMap.put(KeyMapping.JUMP, GLFW.GLFW_KEY_SPACE);
        keyMap.put(KeyMapping.CROUCH, GLFW.GLFW_KEY_LEFT_CONTROL);
    }

    public enum KeyMapping
    {
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT,
        SPRINT,
        JUMP,
        CROUCH
    }
}
