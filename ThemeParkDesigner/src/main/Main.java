package main;

import main.java.GameEngine.Utils.MyLogging;
import main.java.TPD.ThemeParkDesigner;

import java.util.logging.Level;


public class Main
{
    public static void main(String[] args)
    {
        // Change to LEVEL.SEVERE for release
        MyLogging.getLogger().setLevel(Level.INFO);
        MyLogging.log(Level.INFO, "PWD: " + System.getProperty("user.dir"));

        ThemeParkDesigner game = new ThemeParkDesigner();
        game.run();
    }
}