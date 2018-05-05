import java.util.*;
public class CodeForces
{

    public static void main(String[] args)
	{
            
            Scanner in = new Scanner(System.in);
            int  a , b ;
            a = in.nextInt();
            b = in.nextInt();
            long ans = solve(a,b);
            System.out.println(ans);
        }
    
    public static long solve(int  a , int  b){
         
      if(a==1 && b == 1) return 0;
      if(a == 0 || b == 0) return 0 ;
      
      int min = Math.min(a,b);
      int max = Math.max(a,b);
      return 1+ solve(min+1 , max-2);
    }
}