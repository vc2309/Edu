package com.vishnuchopra;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    private static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        ArrayList<Song> KSG = new ArrayList<Song>();
        KSG.add(new Song("Freee", 3.4, "Kanye West"));
        KSG.add(new Song("Ghost Town", 3.4, "Kanye West"));
        KSG.add(new Song("Cudi Montage", 3.4, "Kanye West"));
        KSG.add(new Song("Feel the Love", 3.4, "Kanye West"));
        Album myAlbum = new Album("Kids See Ghosts","Kanye West", KSG);

        ArrayList<Song> trilogy = new ArrayList<Song>();
        trilogy.add(new Song("Glass Table Girls", 3.4, "The Weeknd"));
        trilogy.add(new Song("The Morning", 3.4, "The Weeknd"));
        trilogy.add(new Song("Echoes of Silence", 3.4, "The Weeknd"));
        trilogy.add(new Song("Wicked Games", 3.4, "The Weeknd"));
        Album myAlbum2 = new Album("Trilogy","The Weeknd", trilogy);
        
        myMenu()
    }
}
