package com.vishnuchopra;

import java.util.Scanner;

public class Main {

    private static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        System.out.println("Enter arr length");
        int len = scanner.nextInt();
        int [] myIntArray = getInts(len);
        printArray(myIntArray);

    }

    public static int[] getInts(int num)
    {
        System.out.println("Enter "+num+" values");
        int [] myArr = new int[num];
        for (int i = 0; i <myArr.length ; i++) {
            myArr[i]=scanner.nextInt();
        }
        return myArr;
    }

    public static void printArray(int myArray[])
    {
        for (int i = 0; i <myArray.length ; i++) {
            System.out.println(myArray[i]);
        }
    }
}
