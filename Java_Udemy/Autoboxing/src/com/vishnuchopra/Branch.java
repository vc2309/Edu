package com.vishnuchopra;

import java.util.ArrayList;

public class Branch {
    private String name;
    ArrayList<Customer> customers;

    public String getName() {
        return name;
    }

    public Branch(String name) {
        this.name = name;
        this.customers = customers = new ArrayList<Customer>();
    }

    public void addCustomer(Customer customer)
    {
        customers.add(customer);
    }

    public void printCustomers()
    {
        for (int i = 0; i < customers.size(); i++) {
            System.out.println("Customer #"+i+" : "+customers.get(i).getName());
        }
    }

    public void explore() {
        String choice="";
        while (true) {
            System.out.println("1. select\n 2. view\n 3. add\n 4. quit");
            choice = scanner.next();
            if (choice=="select")
            {
                System.out.println("Enter name");
                String branchname = scanner.nextLine();
                int pos=customers.custExists(branchname);
                if(pos>-1)
                {
                    customers.get(pos).explore();
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
