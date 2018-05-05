import java.util.*;
public class CodeForces
{
    
    public static void main(String[] args)
	{
            
            Scanner in = new Scanner(System.in);
            long n = in.nextLong();
            long ans = 0 ;
            ans += n/2;
            ans += (n/3 - n/6);
            ans += (n/5 - n/10 -( n/15 - n/30)) ;
            long x , y, z ;
            x =  n/14;
            y =  n/21;
            z =  n/35;
            y -= n/42;
            z -= n/210 ;
            z -= (n/70-n/210);
            z -= (n/105 - n/210); 
            ans += n/7-(x+y+z);
            System.out.println(n - ans);
        }
    
    
}