public class BarkingDog {
    public static void main(String [] args)
    {
        System.out.println(bark(true,1));
        System.out.println(bark(false,2));
        System.out.println(bark(true,8));

    }
    public static boolean bark(boolean barking, int hourOfDay)
    {
        if(hourOfDay>23 || hourOfDay<0)
        {
            return false;
        }
        if(barking && hourOfDay<8 || hourOfDay>22)
        {
            return true;
        }
        return false;
    }
}
