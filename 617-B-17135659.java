import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class CodeForces
{
      
     static Scanner in = new Scanner(System.in);  

    public static void main(String[] args) throws IOException 
	{
             int n = in.nextInt();
             int[] a =  new int[n];
             List<Integer> ones = new ArrayList<>();
             long ans = 1 ;
             for(int i=0 ; i<n ; i++){
                 a[i] = in.nextInt();
                 if(a[i] ==  1) ones.add(i);
             }
             if(ones.size() < 2) {
                 System.out.println(ones.size());
                 return ;
             }
             
             for(int i=1 ; i< ones.size() ; i++){
                ans *= (ones.get(i)-ones.get(i-1)); 
             }
             System.out.println(ans);
        }
}