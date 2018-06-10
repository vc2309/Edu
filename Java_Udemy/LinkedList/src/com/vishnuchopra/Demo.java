package com.vishnuchopra;

import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Scanner;

public class Demo {

    public static void main(String[] args) {
        LinkedList<String> places = new LinkedList<String>() ;
        addTo(places,"Hyderabad");
        addTo(places,"Goa");
        addTo(places,"Bangalore");
        addTo(places,"Mumbai");
        addTo(places,"Jaipur");
        addTo(places,"Agra");
        addTo(places,"Delhi");

        printList(places);

        addTo(places,"Jammu");
        addTo(places,"Zimbabwe");
        printList(places);
        visit(places);
        printList(places);
    }

    private static void printList(LinkedList<String> places) {
        ListIterator<String> i = places.listIterator();
        while (i.hasNext())
        {
            System.out.println("Now visited "+i.next());
        }

    }

    private static void addTo(LinkedList<String> places, String p)
    {
        ListIterator<String> i = places.listIterator();
        boolean added=false;
        while (i.hasNext() && !added)
        {
            int comp =i.next().compareTo(p);
            if(comp == 0)
            {
                System.out.println("Already present");
            }
            else if ( comp>0){
                i.previous();
                i.add(p);
                added=true;
                System.out.println("Added new city "+p);

            }
        }
        if (!added)
        {
            //i.previous();
            System.out.println("Added new city "+p);
            i.add(p);
        }
    }

    public static void visit(LinkedList places)
    {
        Scanner scanner = new Scanner(System.in);
        if (places.isEmpty()){
            System.out.println("List is empty");
        }
        else{
            int choice = -1;
            while (choice!=0)
            {
                System.out.println("Enter choice :\n 1. search city \n 0. quit");
                choice=scanner.nextInt();
                switch (choice)
                {
                    case 0:
                        System.out.println("Quitting");
                        break;
                    case 1:
                        System.out.println("Enter place name");
                        String city = scanner.next();
                        if(places.contains(city))
                        {
                            System.out.println("Visited "+city);
                            places.remove(city);
                        }
                        else {
                            System.out.println("City not in itinerary");
                        }
                        break;
                    default:
                        System.out.println("Invalide");
                        choice=0;
                }
            }

        }
    }
}
