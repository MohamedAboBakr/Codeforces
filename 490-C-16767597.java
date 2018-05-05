import java.io.*;
import java.util.*;


public class CodeForces
{
      
    static InputStreamReader isr = new InputStreamReader(System.in);
    static BufferedReader br = new BufferedReader(isr);
 //   static PrintWriter pt = new PrintWriter(System.out);
        
       
    public static void main(String[] args) throws IOException 
	{
                String s1 = br.readLine();
                
                String s2 = br.readLine();
                Long a = Long.parseLong(s2.split(" ")[0]);
                Long b = Long.parseLong(s2.split(" ")[1]); 
                int len1 = s1.length() , len2 = s2.split(" ")[0].length() , len3 = s2.split(" ")[1].length() ;
                if( len1 < (len2+len3)){
                    System.out.println("NO");
                    return ;
                }
                long left_num = 0 ;
                int[] flag = new int[len1];
                for(int i=0; i<len1 ; i++){
                   left_num = (Integer.parseInt(s1.charAt(i)+"") + (left_num*10))%a ;
                   if(left_num%a == 0) flag[i] = 1;
                }
                
                long right_num = 0 , power = 1;
                for(int i= len1-1 ; i>0 ; i--){
                    right_num += Integer.parseInt(s1.charAt(i)+"")*power ;
                    power *= 10 ;
                    
                    // ((x1*1) + (x2*10) + (x3*100) +...) % b = 
                    // ((x1*1)%b + (x2*10)%b + (x3*100)%b +...)%b = 
                    // ((x1%b * 1%b)%b + (x2%b * 10%b)%b ...) %b
                    right_num %= b ;
                    power %= b ;
                    if(right_num  == 0 && s1.charAt(i)!='0' && flag[i-1] == 1){
                        System.out.println("YES");
                        System.out.println(s1.substring(0,i));
                        System.out.println(s1.substring(i,len1));
                        return ;
                    }
                }
                System.out.println("NO");
        }
}