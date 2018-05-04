public class NumberOfDaysInMonth {

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
    public static int getDaysInMonth(int month, int year)
    {
        if(month<1 || month>12 || year>9999 || year<1)
        {
            return -1;
        }
        int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        days[1] = isLeapYear(year)? 29 : 28;

        return days[month-1];
    }
}
