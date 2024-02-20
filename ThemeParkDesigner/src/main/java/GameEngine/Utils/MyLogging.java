package main.java.GameEngine.Utils;

import java.util.logging.Level;
import java.util.logging.Logger;

public class MyLogging
{
    private static Logger logger;

    public static Logger getLogger()
    {
        if (logger == null)
        {
            logger = Logger.getLogger(MyLogging.class.getName());
        }
        return logger;
    }

    public static void log(Level level, String msg)
    {
        getLogger().log(level, msg);
    }
}
