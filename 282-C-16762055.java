import java.io.*;
import java.util.*;


public class CodeForces
{
    static InputStreamReader isr = new InputStreamReader(System.in);
    static BufferedReader br = new BufferedReader(isr);
   // static PrintWriter pt = new PrintWriter(System.out);
        
       
    public static void main(String[] args) throws IOException 
	{
                String a = br.readLine();
                String b = br.readLine();
                int len1 = a.length() , len2 = b.length();
                if(len1 != len2 ){
                    System.out.println("NO");
                    return ;
                }
               boolean a_0 = a.matches("0*") , b_0 = b.matches("0*");
               if(a_0 && b_0){
                   System.out.println("YES");
                    return ;
               }
               if(a_0 || b_0){
                   System.out.println("NO");
                    return ;
               }
               System.out.println("YES");
                   
        }
}