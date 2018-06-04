package com.vishnuchopra;

import java.util.ArrayList;

public class GroceryList {

    private ArrayList<String> groceries= new ArrayList<String>();
    
    public void addItem(String item)
    {
        groceries.add(item);
    }
    public void printList()
    {
        System.out.println("No of items = "+groceries.size());
        for (String i:groceries) {
            System.out.println(i);
        }
    }

    public void removeItem (int pos)
    {

        try {
            System.out.println("Removed item "+groceries.get(pos));
            groceries.remove(pos);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public String findItem(String search)
    {
        if(groceries.contains(search))
        {
            return "Item present";
        }

        return "Item not present";
    }

}
