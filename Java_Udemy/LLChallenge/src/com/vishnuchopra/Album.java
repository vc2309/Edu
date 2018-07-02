package com.vishnuchopra;

import java.util.ArrayList;
import java.util.ListIterator;
import java.util.Scanner;

public class Album {

    private String name;
    private String artist;
    private ArrayList<Song> songs;

    public Album(String name, String artist, ArrayList<Song> songs) {
        this.name = name;
        this.artist = artist;
        this.songs = songs;
    }

    public Album(String name, String artist) {
        this.name = name;
        this.artist = artist;
        this.songs = new ArrayList<Song>();
    }

    public void Menu() {
        Scanner scanner = new Scanner(System.in);
        int choice = -1;
        while (choice!=0)
        {
            System.out.println("Enter choice : 0. quit\n 1. add song\n 2. print songs\n 3. show menu");
            choice = Integer.parseInt(scanner.nextLine());

            switch (choice)
            {
                case 0:
                    System.out.println("Quitting.. ");
                    break;
                case 1:
                    System.out.println("Enter song name");
                    String name=scanner.nextLine();
                    System.out.println("Enter song length");
                    Double len = Double.parseDouble(scanner.nextLine());
                    Song newSong = new Song(name,2.1,artist);
                    System.out.println(addSong(newSong));
                    break;
                case 2:
                    printSongs();
                    break;
                case 3:
                    continue;
                    default:
                        continue;

            }
        }
    }

    private void printSongs() {
        if (songs.isEmpty())
        {
            System.out.println("Album is empty");
        }
        ListIterator<Song> i = songs.listIterator();
        System.out.println("Album name : " +name);
        System.out.println("Artist : "+artist);
        while (i.hasNext())
        {
            System.out.println((i.next()).getName());
        }

    }

    private String addSong(Song newSong) {
        if(songs.contains(newSong))
        {
           return "Song is already present";
        }
        else {
            songs.add(newSong);
            return "Added song "+newSong.getName();

        }
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getArtist() {
        return artist;
    }

    public void setArtist(String artist) {
        this.artist = artist;
    }

    public ArrayList<Song> getSongs() {
        return songs;
    }

    public void setSongs(ArrayList<Song> songs) {
        this.songs = songs;
    }
}
