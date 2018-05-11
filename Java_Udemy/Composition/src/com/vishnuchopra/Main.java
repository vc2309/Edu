package com.vishnuchopra;

public class Main {

    public static void main(String [] args)
    {
        Case theCase = new Case("220S", "AOC", "220V", new Dimensions(24,29,45));
        Monitor monitor = new Monitor("222","Dell",25, new Resolution(2200,1080));
        Motherboard motherboard = new Motherboard("LJHF4","Mon","JJJJ",2);

        PC myPC = new PC(theCase,monitor,motherboard);
        myPC.turnOn();
        myPC.getMonitor().drawPixelAt(45,4);
    }
}
