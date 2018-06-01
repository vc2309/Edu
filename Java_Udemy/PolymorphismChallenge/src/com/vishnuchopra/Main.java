package com.vishnuchopra;

class Car {
    private boolean Engine;
    private int cylinders;
    private int wheels;
    private String name;

    public Car(boolean engine, int cylinders, int wheels, String name) {
        Engine = engine;
        this.cylinders = cylinders;
        this.wheels = wheels;
        this.name = name;
    }

    public Car(String name) {
        this(true,2,4,name);
    }

    public Car(int cylinders, String name) {
        this(true,cylinders,4,name);
    }

    public boolean isEngine() {
        return Engine;
    }

    public int getCylinders() {
        return cylinders;
    }

    public int getWheels() {
        return wheels;
    }

    public String getName() {
        return name;
    }

    public void startEngine(){
        System.out.print("vrooooom");
    }

    public void accelerate(){
        System.out.print("speeding up ");
    }

    public void brake(){
        System.out.print("Slowing down");
    }

}

class Ferrari extends Car{
    public Ferrari() {
        super(4, "Ferrari");
    }

    @Override
    public void startEngine(){
        System.out.print("Push to start");
    }

    @Override
    public void accelerate(){
        System.out.print("0 to 60 real quick");
    }

}

class Tesla extends Car{
    public Tesla() {
        super(2, "Tesla");
    }

    @Override
    public void startEngine(){
        System.out.print("Charge to start");
    }

    @Override
    public void accelerate(){
        System.out.print("0 to 60 kinda quick");
    }

}

class Santro extends Car{
    public Santro() {
        super(1, "Santro");
    }

    @Override
    public void startEngine(){
        System.out.print("Pray to start");
    }

    @Override
    public void accelerate(){
        System.out.print("0 to 60 kal tak lol");
    }

}

public class Main {

    public static void main(String[] args) {
        Car Garage[] = {new Ferrari(), new Tesla(),new Santro()};
        for (int x=0;x<Garage.length;x++){
            System.out.print("The "+ Garage[x].getName() +" uses ");
            Garage[x].startEngine();
            System.out.print(" and goes ");
            Garage[x].accelerate();
            System.out.println("\n");
        }
    }
}
