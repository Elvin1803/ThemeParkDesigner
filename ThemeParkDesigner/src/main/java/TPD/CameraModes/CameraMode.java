package main.java.TPD.CameraModes;

import main.java.GameEngine.GraphicsEngine.Camera;
import org.joml.Vector3f;

public abstract class CameraMode
{
    protected Vector3f position = new Vector3f(0,0,0);
    protected Vector3f rotation = new Vector3f(0,0,0);

    public void update()
    {
        if (moveCamera())
        {
            Camera.setPosition(position);
            Camera.setRotation(rotation);
        }
    }

    /*
     * This method will check for input, then update this.position accordingly
     * Will return true if the position has been updated, false otherwise.
     */
    protected abstract boolean moveCamera();
}
