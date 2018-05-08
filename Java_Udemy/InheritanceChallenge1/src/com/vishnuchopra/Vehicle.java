package com.vishnuchopra;

public class Vehicle {
    private int speed;

    public static void move(int speed)
    {
        this.speed=speed;
    }

    public Vehicle() {
        this(0);
    }

    public Vehicle(int speed) {
        this.speed = speed;
    }

}
