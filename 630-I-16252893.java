import java.util.*;
public class CodeForces
{
    
    public static void main(String[] args)
	{
            
            Scanner in = new Scanner(System.in);
            int n = in.nextInt();
            long num = 6*(long)Math.pow(4,n-3);
            if(n>3) num += 9*(n-3)*(long)Math.pow(4,n-4);
            
            System.out.println(num*4);
        }
    
    
}