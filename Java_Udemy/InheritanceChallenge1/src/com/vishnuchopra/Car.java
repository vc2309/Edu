package com.vishnuchopra;

public class Car extends Vehicle{
    private String model;
    private String gear;
    private String direction;

    public void steer(String dir) {
        if (dir.equalsIgnoreCase("right") || dir.equalsIgnoreCase("left") || dir.equalsIgnoreCase("straight") || dir.equalsIgnoreCase("reverse")) {
            this.direction = dir;
        }
        else {
            System.out.println("Invalid direction");
        }
    }

    public void changeGear(String gear){
        if (gear.equalsIgnoreCase("1") || gear.equalsIgnoreCase("2") || gear.equalsIgnoreCase("3") || gear.equalsIgnoreCase("4") || gear.equalsIgnoreCase("5") || gear.equalsIgnoreCase("R"))
        {
            this.gear=gear;
        }
        else {
            System.out.println("Invalid gear");
        }
    }

    public Car(int speed, String model, String gear, String direction) {
        super(speed);
        this.model = model;
        this.gear = gear;
        this.direction = direction;
    }

    public Car(String model, String gear, String direction) {
        this(0,model,gear,direction);
    }

    public Car() {
        this("default","1","Straight");
    }

    public Car(String model) {
        this(0,model,"1","straight");
    }
}
