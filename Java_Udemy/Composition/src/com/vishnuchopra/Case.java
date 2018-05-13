package com.vishnuchopra;

public class Case {

    private String model;
    private String manufacturer;
    private String powerSup;
    private Dimensions dim;

    public Case(String model, String manufacturer, String powerSup, Dimensions dim) {
        this.model = model;
        this.manufacturer = manufacturer;
        this.powerSup = powerSup;
        this.dim = dim;
    }

    public void powerUp(){
        System.out.println("Power button pressed");
    }
    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public String getManufacturer() {
        return manufacturer;
    }

    public void setManufacturer(String manufacturer) {
        this.manufacturer = manufacturer;
    }

    public String getPowerSup() {
        return powerSup;
    }

    public void setPowerSup(String powerSup) {
        this.powerSup = powerSup;
    }

    public Dimensions getDim() {
        return dim;
    }

    public void setDim(Dimensions dim) {
        this.dim = dim;
    }
}
