import java.io.*;
import java.math.*;
import java.util.*;


public class CodeForces
{
      
     static Scanner in = new Scanner(System.in);  
    public static void main(String[] args) throws IOException 
	{
            
            
            int n = in.nextInt();
            long[] a = new long[n];
            
            for(int i=0 ; i<n ; i++){
                a[i] = in.nextLong();
            }
           int count = 0 ;
           List<Long> list = new ArrayList<>();
           for(int i = 0 ; i< n-1 ; i++){
               list.add(a[i]);
               if(gcm(a[i],a[i+1]) != 1){
                   list.add(1L);
                   count++;
               }
              
           }
           list.add(a[n-1]);
         System.out.println(count);
         int len =  list.size();
         for(int i=0 ;  i< len  ; i++){
              System.out.printf("%d%s",list.get(i) , (i == len-1)? "\n":" ");
         }
        }
    
     public static long gcm(long a, long b) {
      return b == 0 ? a : gcm(b, a % b);
}
}