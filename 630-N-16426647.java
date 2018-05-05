import java.util.*;
public class CodeForces
{
    
    public static void main(String[] args)
	{
            
            Scanner in = new Scanner(System.in);
            double a , b , c , root , ans1 , ans2 ;
            a = in.nextDouble();
            b = in.nextDouble();
            c = in.nextDouble();
            root = Math.sqrt(b*b  - 4*a*c);
            ans1 = (-1*b + root)/(2*a);
            ans2 = (-1*b - root)/(2*a);
            System.out.printf("%.15f\n",(ans1 > ans2) ? ans1 : ans2);
            System.out.printf("%.15f\n",(ans1 < ans2) ? ans1 : ans2);
        }

}