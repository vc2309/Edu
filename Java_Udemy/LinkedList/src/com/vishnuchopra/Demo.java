package com.vishnuchopra;

import java.util.Iterator;
import java.util.LinkedList;

public class Demo {

    public static void main(String[] args) {
        LinkedList<String> places = new LinkedList<String>() ;
        places.add("Hyderabad");
        places.add("Goa");
        places.add("Bangalore");
        places.add("Mumbai");
        places.add("Jaipur");
        places.add("Agra");
        places.add("Delhi");

        printList(places);
    }

    private static void printList(LinkedList<String> places) {
        Iterator<String> i = places.iterator();
        while (i.hasNext())
        {
            System.out.println("Now visited "+i.next());
        }

    }
}
