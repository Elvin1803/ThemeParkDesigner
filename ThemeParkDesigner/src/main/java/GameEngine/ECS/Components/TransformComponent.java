package main.java.GameEngine.ECS.Components;

import main.java.GameEngine.ECS.Component;
import org.joml.Vector3f;

public class TransformComponent extends Component
{
    public Vector3f position;
    public Vector3f rotation;
    public Vector3f scale;
}