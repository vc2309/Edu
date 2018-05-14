package com.vishnuchopra;

import java.awt.*;

public class Table extends Furniture {
    private String tableType;
    private int numChairs;
    private Chair [] chairs;

    public Table(String tableType, int numChairs) {
        super();
        this.tableType = tableType;
        this.numChairs = numChairs;
        this.chairs = new Chair[numChairs];
        for (int x=0;x<numChairs;x++)
        {
            chairs[x]=new Chair();
        }
    }

    public Table(String colour, String manufacturer, Dimension dimension, String tableType, int numChairs) {
        super(colour, manufacturer, dimension);
        this.tableType = tableType;
        this.numChairs = numChairs;
        this.chairs = new Chair[numChairs];
    }

    public void takeSeat(){
        int ctr=1;

        for (int x=0;x<chairs.length;x++) {

            if (!chairs[x].isSeatTaken())
            {
                chairs[x].takeSeat(x);
                break;
            }
            ctr++;

        }
        if (ctr==numChairs)
        {
            System.out.println("All seats occupied");
        }
    }
}

