package com.vishnuchopra;

public class BankAccount {

    private int accountNo;
    private double balance;
    private String custName;
    private String email;
    private int phone;

    BankAccount(){
        System.out.println("Empty account created");
    }

    BankAccount(int accountNo, double balance, String custName, String email, int phone)
    {
        this.accountNo=accountNo;
        this.balance=balance;
        this.custName=custName;
        this.email=email;
        this.phone=phone;
    }

    public int getAccountNo(){
        return this.accountNo;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public String getCustName() {
        return custName;
    }

    public void setCustName(String custName) {
        this.custName = custName;
    }

    public int getPhone() {
        return phone;
    }

    public void setPhone(int phone) {
        this.phone = phone;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public void deposit(int amt)
    {
        this.balance+=amt;
        System.out.println("New balance is: "+balance);
    }

    public void withdrawal(int amt)
    {
        if (this.balance>=amt) {
            this.balance -= amt;
            System.out.println("New balance is: "+balance);
        }

        else {
            System.out.println("Only " + this.balance + " is available. Insufficient funds.");
        }
    }
}
