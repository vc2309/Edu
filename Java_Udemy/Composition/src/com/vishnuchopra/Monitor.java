package com.vishnuchopra;

public class Monitor {

    private String model;
    private String manufacturer;
    private int size;
    private Resolution nativeRes;

    public Monitor(String model, String manufacturer, int size, Resolution nativeRes) {
        this.model = model;
        this.manufacturer = manufacturer;
        this.size = size;
        this.nativeRes = nativeRes;
    }

    public void drawPixelAt(int x,int y)
    {
        System.out.println("Pixel on at" +" "+String.valueOf(x)+" "+String.valueOf(y));
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

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public Resolution getNativeRes() {
        return nativeRes;
    }

    public void setNativeRes(Resolution nativeRes) {
        this.nativeRes = nativeRes;
    }
}
