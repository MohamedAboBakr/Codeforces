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
             int m = in.nextInt();
             in.nextLine();
             long ans = 1;
             int[][] chars = new int[m][27];
             int[] diff_chars = new int[m];
             for(int i = 0 ; i<n ; i++){
                 String s = in.nextLine();
                 for(int j =0 ; j<m ; j++){
                     if(chars[j][s.charAt(j)-'A'] == 0){
                        chars[j][s.charAt(j)-'A'] = 1 ;
                        diff_chars[j] ++ ;
                     }
                 }
             }
             
             for(int i = 0 ; i<m ; i++){
                 ans = (ans * diff_chars[i]%mod )%mod;
             }
             System.out.println(ans);
        }
    
}