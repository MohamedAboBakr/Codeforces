import java.util.*;
public class CodeForces
{

    public static void main(String[] args)
	{
            
            Scanner in = new Scanner(System.in);
            long a , b ;
            a = in.nextLong();
            b = in.nextLong();
            long ans = solve(a,b);
            System.out.println(ans);
        }
    
    public static long solve(long a , long b){
         
        if(a == 1) return b ; 
        if(a+1 == b) return b ;
        if(a == b) return 1 ;
        if(a%b == 0) return a/b;
        if(a>b){
            return a/b + solve(a%b , b );
        }
        if(a<b){
            if(b-a < a) return 1+solve(a,b-a);
            else return (b-a)/a + solve(a , b - ((b-a)/a *a) );
        }
        return 1;
    }
}