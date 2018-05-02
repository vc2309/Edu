import java.io.IOException;

public class MegaBytesConverter {
    public static void main(String [] args)throws IOException
    {
        printMegaBytesAndKiloBytes(2450);
    }
    public static void printMegaBytesAndKiloBytes(int kiloBytes)
    {
        if(kiloBytes<0)
        {
            System.out.println("Invalid value");
        }
        int mb = kiloBytes/1024;
        int kb = kiloBytes%1024;
        System.out.println(kiloBytes+" KB = "+mb+" MB and "+kb+" KB");

    }
}
