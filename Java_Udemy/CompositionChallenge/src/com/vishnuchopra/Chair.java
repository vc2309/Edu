package com.vishnuchopra;

import java.awt.*;

public class Chair extends Furniture{
    private boolean seatTaken;
    public Chair(String colour, String manufacturer, Dimension dimension) {
        super(colour, manufacturer, dimension);
        this.seatTaken=false;
    }

    public Chair() {
        super();
        this.seatTaken=false;
    }

    public void takeSeat(int seatNum){
        this.seatTaken=true;
        System.out.println("Seat "+String.valueOf(seatNum)+" is now taken");
    }

    public boolean isSeatTaken() {
        return seatTaken;
    }
}
