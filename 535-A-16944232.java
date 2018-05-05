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
            String[] units = new String[]{"zero","one","two","three","four","five","six","seven","eight","nine"};
            String[] tens = new String[]{"ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
            String[] tens_ = new String[]{"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
            if(n>10 && n<20) System.out.println(tens_[n%10 -1]);
            else if(n<10) System.out.println(units[n]);
            else{
                System.out.println(tens[n/10 - 1] + ((n%10 == 0)? "" : "-"+units[n%10]));
                
            }
        }
}