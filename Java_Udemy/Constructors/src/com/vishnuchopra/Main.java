package com.vishnuchopra;

public class Main {
    public static void main(String[] args)
    {
        BankAccount vishnuAcc = new BankAccount(2309,100000000, "Vishnu", "VISHNU@gmail.com", 99100008);
        vishnuAcc.deposit(10000);
        vishnuAcc.withdrawal(10000);
        BankAccount v = new BankAccount();
    }
}
