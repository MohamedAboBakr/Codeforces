import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class CodeForces
{
      
    static InputStreamReader isr = new InputStreamReader(System.in);
    static BufferedReader br = new BufferedReader(isr);
   //  static PrintWriter pt = new PrintWriter(System.out);
   //  static Scanner in = new Scanner(System.in);  
       
    static long mod = (long) 1e9 + 7 ;
    public static void main(String[] args) throws IOException 
	{
   
            String s = br.readLine();
            long k = Long.parseLong(br.readLine());
            long len = s.length();
            long Len_cases = Power(2,len);
            long G_series = ((Power(Len_cases , k)-1)*Power(Len_cases - 1 , mod -2)) % mod;
            long ans = 0;
            for(int i=0 ; i<len ; i++){
                if(s.charAt(i) == '0' || s.charAt(i) == '5' ){
                  long till_index = Power(2,i)%mod;
                  ans = (ans + (till_index * G_series)%mod)% mod;
                }
            }
            
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