package com.vishnuchopra;

public class Main {

    public static void main(String[] args) {
        Customer customer = new Customer("Vishnu",1000023232);
        Customer another;
        another=customer;
        another.setBalance(13423423423.3);
        System.out.println();
    }

}
