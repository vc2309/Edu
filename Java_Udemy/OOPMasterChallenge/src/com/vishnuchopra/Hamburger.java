package com.vishnuchopra;

public class Hamburger {
    private String rolltype;
    private String meat;
    private String [] additions;
    private int addOns;
    private int basePrice;
    private String name;
    private int maxAddons;

    public Hamburger(String rolltype, String meat, int basePrice, String name) {
        this.rolltype = rolltype;
        this.meat = meat;
        this.basePrice = basePrice;
        this.name = name;
        this.maxAddons = 4;

    }

    public void addToppings(String toppings[]){
        if(addOns+toppings.length<=maxAddons)
        {
            this.addOns+=toppings.length;
            additions=toppings;
            System.out.println("Added "+toppings.length+" toppings to "+name);
        }
        else {
            System.out.println("Maximum addons reached");
        }
    }

    public double getPrice() {
        return basePrice + (addOns * 1.5);
    }

    public void getTotal(){
        System.out.println("Base price of "+name+" is "+basePrice);
        for (int i=0;i<additions.length;i++)
        {
            System.out.println("Addon #"+(i+1)+" : "+additions[i]);
        }
        if (additions.length>0)
        {
            System.out.println("Total price is "+getPrice());
        }
    }

}
