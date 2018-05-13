package com.vishnuchopra;

import java.awt.*;

public class Room {
    private Dimension dimension;
    private Table table;
    private TV tv;

    public Room(Dimension dimension, Table table, TV tv) {
        this.dimension = dimension;
        this.table = table;
        this.tv = tv;
    }

    public Room() {
        this(new Dimension(12,12),new Table("Coffee table",4),new TV());
    }

    public void chillOut(){
        table.takeSeat();
        tv.turnOn();
    }
    public void addGuest(){
        System.out.println("New guest entered");
        table.takeSeat();
    }
}
