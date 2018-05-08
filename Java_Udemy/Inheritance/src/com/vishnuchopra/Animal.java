package com.vishnuchopra;

public class Animal {
   private String name;
   private int weight;
   private int size;
   private int age;
    public Animal(String name, int weight, int size) {
        this.name = name;
        this.weight = weight;
        this.size = size;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getWeight() {
        return weight;
    }

    public void setWeight(int weight) {
        this.weight = weight;
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public void talk()
    {
        System.out.println("is the sound I make");
    }

    public void eat()
    {
        System.out.println("is eating");
    }
}
