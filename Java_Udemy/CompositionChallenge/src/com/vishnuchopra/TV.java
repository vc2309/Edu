package com.vishnuchopra;

import java.awt.*;

public class TV extends Furniture {
    private Resolution resolution;

    public TV(String colour, String manufacturer, Dimension dimension, Resolution resolution) {
        super(colour, manufacturer, dimension);
        this.resolution = resolution;
    }

    public TV() {
        super();
        this.resolution=new Resolution(1080,720);
    }

    public void turnOn()
    {
        System.out.println("The TV is on.");
    }
}
