package com.vishnuchopra;

import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException{
        Room myRoom = new Room();
        myRoom.chillOut();
        myRoom.addGuest();
        myRoom.addGuest();
        myRoom.addGuest();
        myRoom.addGuest();
    }
}
