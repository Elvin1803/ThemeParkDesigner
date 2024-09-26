package main.java.GameEngine.ECS;

import main.java.GameEngine.ECS.Components.NameComponent;
import main.java.GameEngine.Utils.MyLogging;
import main.java.GameEngine.Utils.SparseSet;

import java.util.Vector;
import java.util.logging.Level;

public class ECSManager
{
    private Vector<Integer> entities = new Vector<>(100);
    private Vector<Integer> deletedIds = new Vector<>(100);

    private Vector<SparseSet<Component>> componentsSets = new Vector<>(100);

    public ECSManager(){}

    public int create()
    {
        int newEnt;
        if (!deletedIds.isEmpty())
        {
            newEnt = deletedIds.remove(deletedIds.size() - 1);
        }

        newEnt = entities.size();
        entities.add(0);

        MyLogging.log(Level.INFO, "Created entity with ID: " + newEnt);
        return newEnt;
    }

    public void emplace(int entity, Component component, Class<? extends Component> T)
    {
        MyLogging.log(Level.INFO, "Adding component " + T.getSimpleName() + " to entity: " + entity);
        for (SparseSet<Component> l : componentsSets)
        {
            if (l.getTypeClass() == T)
            {
                l.set(entity, component);
                return;
            }
        }

        SparseSet<Component> newSparse = new SparseSet<>((Class<Component>) T);
        newSparse.set(entity, component);
        componentsSets.add(newSparse);
    }

    public Component get(int entity, Class<? extends Component> T)
    {
        for (SparseSet<Component> l : componentsSets)
        {
            if (l.getTypeClass() == T)
            {
                return l.get(entity);
            }
        }
        return null;
    }
}
