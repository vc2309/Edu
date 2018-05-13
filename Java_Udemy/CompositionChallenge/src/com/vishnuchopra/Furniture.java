package com.vishnuchopra;

import java.awt.*;

public class Furniture {
    private String colour;
    private String manufacturer;
    private Dimension dimension;

    public Furniture(String colour, String manufacturer, Dimension dimension) {
        this.colour = colour;
        this.manufacturer = manufacturer;
        this.dimension = dimension;
    }

    public Furniture() {
        this("Wood","IKEA",new Dimension(-1,-1));
    }

}
