package com.vishnuchopra;

public class Main {
    public static void main(String[] args)
    {
        Printer printer=new Printer();
        printer.addToner(10);
        printer.printPages(17);
        printer.fillToner();
        printer.addToner(12);
    }
}
