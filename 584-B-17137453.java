import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class CodeForces
{
     
     static Scanner in = new Scanner(System.in);  
       
    static long mod = (long) 1e9 + 7 ;
    public static void main(String[] args) throws IOException 
	{
             int n = in.nextInt();
             long ans = 0;
             long pow_27 = n-1 , pow_7 = 0 ;
             for(int i =0 ; i<n ; i++){
                 ans = (ans%mod + (Power(27,pow_27) * Power(7,pow_7))%mod)%mod;
                 pow_27 -- ;
                 pow_7 ++ ;
             }
             ans =( ans%mod * 20 )%mod ;
             System.out.println(ans);
        }
    
    
    static long Power(long base , long times){
        long ans = 1 ;
        long base_binary = base ;
        while(times > 0){
            if(times % 2 == 1) ans = ((ans%mod) * (base_binary%mod))%mod ;
            base_binary = (base_binary % mod)*(base_binary % mod)%mod;
            times /= 2 ;
        }
        return ans ;
    }
}