package com.vishnuchopra;

public class VipAccount {
    private int creditLimit;
    private String name;
    private String email;

    public VipAccount(int creditLimit, String name, String email) {
        this.creditLimit = creditLimit;
        this.name = name;
        this.email = email;
    }

    public VipAccount(String name, String email) {
        this(9999,name,email);
    }

    public VipAccount() {
        this(9999,"John Doe","johndoe@email.com");
    }

    public int getCreditLimit() {
        return creditLimit;
    }

    public void setCreditLimit(int creditLimit) {
        this.creditLimit = creditLimit;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }
}
