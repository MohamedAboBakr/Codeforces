import java.io.*;
import java.util.*;


public class CodeForces
{
      
        static int max , v1 , v2, t, d;;
       
    public static void main(String[] args) throws IOException 
	{
                Scanner in = new Scanner(System.in);
                
                v1 = in.nextInt();
                v2 = in.nextInt();
                t  = in.nextInt();
                d  = in.nextInt();
                 int ans = 0 ;
                 for(int i=0 ;  i<t ; i++){
                     ans += Math.min(v1+i*d , v2+d*(t-1-i));
                 }
                System.out.println(ans);
        }
}