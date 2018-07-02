package com.vishnuchopra;

public class Song {
    private String name;
    private double length;
    private String artist;

    public Song(String name, double length, String artist) {
        this.name = name;
        this.length = length;
        this.artist = artist;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getLength() {
        return length;
    }

    public void setLength(double length) {
        this.length = length;
    }

    public String getArtist() {
        return artist;
    }

    public void setArtist(String artist) {
        this.artist = artist;
    }
}
