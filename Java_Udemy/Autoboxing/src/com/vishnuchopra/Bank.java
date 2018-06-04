package com.vishnuchopra;

import java.util.ArrayList;

public class Bank {

    ArrayList<Branch> branches;
    private String name;

    public Bank(String name) {
        this.name = name;
        this.branches = new ArrayList<Branch>();
    }

    public int branchExists(String name)
    {

        for (int i = 0; i <branches.size() ; i++) {
            if (name==branches.get(i).getName())
            {
                return i;
            }

        }
        return -1;
    }

    public String getName() {
        return name;
    }

    public void addBranch(Branch branch)
    {
        branches.add(branch);
    }

    public void printBranches()
    {
        for (Branch b:branches
             ) {
            System.out.println(b.getName());
        }
    }

}


