package main.java.GameEngine.ECS.Components;

import main.java.GameEngine.ECS.Component;

public class NameComponent extends Component
{
    public String name;

    public NameComponent(String name)
    {
        this.name = name;
    }
}
