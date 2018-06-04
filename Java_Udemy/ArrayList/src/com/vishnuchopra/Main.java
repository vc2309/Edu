package com.vishnuchopra;

import java.util.Scanner;

public class Main {
    private static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        GroceryList groceryList = new GroceryList();
        addGroceries(groceryList);
        groceryList.printList();
        groceryList.removeItem(0);
        System.out.println(groceryList.findItem("apple"));
    }

    private static void addGroceries(GroceryList groceryList) {
        String item="";
        while (!item.contains("done"))
        {
            System.out.println("Enter item/enter done to finish");
            item=scanner.nextLine();
            if (!item.contains("done"))
                groceryList.addItem(item);
            else break;
        }
    }
}
