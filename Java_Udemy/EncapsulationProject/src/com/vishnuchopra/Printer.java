package com.vishnuchopra;

public class Printer {
    private int tonerLevel;
    private boolean isDuplex;

    public Printer() {
        this(50,false);
    }

    public void fillToner()
    {
        if (tonerLevel<100)
            System.out.println("The toner is filled "+String.valueOf(100-tonerLevel)+"%");
        else

            System.out.println("The toner is full");
        tonerLevel=100;
    }

    public void addToner(int amt)
    {
        if (amt+tonerLevel>100){
            System.out.println("Toner will overflow");
        }
        else {
            System.out.println("Toner filled to "+String.valueOf(tonerLevel+amt));
            tonerLevel+=amt;
        }
    }

    public Printer(int tonerLevel, boolean isDuplex) {
        this.tonerLevel = (tonerLevel>0 && tonerLevel<=100)? tonerLevel:-1;
        this.isDuplex = isDuplex;
    }

    public boolean isDuplex() {
        return isDuplex;
    }

    public void printPages(int amt)
    {
        if (isDuplex)
        {
            System.out.println(String.valueOf(amt/2 + amt%2)+" pages are used");
        }
        else {
            System.out.println(String.valueOf(amt) + " pages are used");
        }
    }
}
