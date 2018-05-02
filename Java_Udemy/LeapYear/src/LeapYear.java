import java.io.IOException;

public class LeapYear {
    public static void main(String [] args)throws IOException
    {
        System.out.println(isLeapYear(-1600));
        System.out.println(isLeapYear(2016));
        System.out.println(isLeapYear(2000));
    }
    public static boolean isLeapYear(int year)
    {
        if(year>=9999 || year<=1)
        {
            return false;
        }

        if(year%400==0)
        {
            return true;
        }
        else if(year%4==0 && year%100!=0)
        {
            return true;
        }
        else return false;
    }
}
