package com.vishnuchopra;

import java.util.ArrayList;

public class Customer {
    private String name;
    private ArrayList<Double> transactions;

    public Customer(String name) {
        this.name = name;
        this.transactions = new ArrayList<Double>();
    }

    public void addTransaction(double d)
    {
        transactions.add(d);
    }

    public void printTransactions()
    {   int i=0;
        for (Double d: transactions) {
            System.out.println("Transaction #"+i+" : "+d.doubleValue());

        }
    }

    public String getName() {
        return name;
    }
}
