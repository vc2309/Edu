package com.vishnuchopra;

import java.util.Scanner;

public class Main {

    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        System.out.println("Enter bank name");
        String name = scanner.nextLine();
        Bank myBank = new Bank(name);

        String choice = "";
        while(choice!="quit")
        {
            System.out.println("1. add\n 2. view\n 3. quit\n");
            choice = scanner.next();

            if (choice=="add")
            {
                System.out.println("Enter name");
                String branchname = scanner.nextLine();
                myBank.addBranch(new Branch(branchname));
            }
            else if(choice=="view")
            {
                myBank.printBranches();
            }
            else {
                break;
            }
        }
        choice="";
        while (true)
        {
            System.out.println("1. select\n 2. view\n 3. quit\n");
            choice = scanner.next();

            if (choice=="select")
            {
                System.out.println("Enter name");
                String branchname = scanner.nextLine();
                int pos=myBank.branchExists(branchname);
                if(pos>-1)
                {
                    myBank.branches.get(pos).explore();
                }
            }
            else if(choice=="view")
            {
                myBank.printBranches();
            }
            else {
                break;
            }

        }

    }
}
