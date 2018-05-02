public class AreaCalculator {
    static final double PI = 3.14159;
    public static void main(String [] args)
    {
        System.out.println(area(5.0));
        System.out.println(area(-1));
        System.out.println(area(5,4));
    }
    public static double area(double radius)
    {
        if(radius<0)
        {
            return -1.0;
        }
        double area=PI*(Math.pow(radius,2));
        return area;
    }
    public static double area(double x, double y)
    {
        if(x<0 || y<0)
        {
            return -1;
        }
        double area=x*y;
        return area;
    }
}
