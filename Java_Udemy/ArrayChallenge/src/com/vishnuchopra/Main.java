package com.vishnuchopra;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        System.out.println("Enter size");
        int len = scanner.nextInt();
        int [] myArr = getArray(len);
        myArr=mergesort(myArr);
        printArray(myArr);

    }

    private static int[] getArray(int len) {
        int myArr [] = new int[len];
        for (int i = 0; i < len; i++) {
            System.out.println("Enter element "+i);
            myArr[i] = scanner.nextInt();
        }
        return myArr;
    }

    private static int[] mergesort(int[] myArr) {

        if (myArr.length==1)
        {
            return myArr;
        }
        int l1 []  = Arrays.copyOfRange(myArr,0, ((myArr.length)/2));
        int l2 []  = Arrays.copyOfRange(myArr,(myArr.length)/2, myArr.length);
        return merge(mergesort(l1),mergesort(l2));
        
    }

    private static int[] merge(int[] l, int[] r) {
        int lp = 0;
        int rp = 0;
        int i =0;
        int merged[] = new int [l.length + r.length ];
        while (lp<l.length && rp<r.length)
        {
            merged[i]=l[lp]<=r[rp]? l[lp] : r[rp];
            if (l[lp]<=r[rp])
                lp++;
            else
                rp++;
            i++;
        }
        while (lp<l.length)
        {
            merged[i]=l[lp];
            lp++;
            i++;
        }
        while (rp<r.length)
        {
            merged[i]=r[rp];
            rp++;
            i++;
        }
//        printArray(merged);
        return merged;
    }

    public static void printArray(int myarr[])
    {
        for (int i = 0; i < myarr.length; i++) {
            System.out.print(myarr[i]+" ");
        }
        System.out.println("");
    }
}
