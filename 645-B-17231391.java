import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class CodeForces
{
     static Scanner in = new Scanner(System.in);  
    public static void main(String[] args) throws IOException 
	{    
            
           long n = in.nextLong();
           long k = in.nextLong();
           if(n == 1 ){
               System.out.println(0);
               return ;
           }
           long ans = 0;
           if(k <= n/2 ){
               for(int i= 0 ; i<k ; i++){
                   ans += n-i-1 ;
               }
              // System.out.println(ans);
               ans += (n-(2*k))*k ;
               ans += (k*(k-1)/2);
           }
           else{
               ans += (n*(n-1)/2);
             // long rest = k - n/2 ;
             //  if(rest %2 == 1){ ans -- ;}
               
           }
           System.out.println(ans);
        }
}