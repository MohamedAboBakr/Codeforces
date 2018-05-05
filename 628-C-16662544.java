import java.io.*;
import java.util.*;


public class CodeForces
{

     static InputStreamReader isr = new InputStreamReader(System.in);
     static BufferedReader br = new BufferedReader(isr);
   //  static PrintWriter pt = new PrintWriter(System.out);
    public static void main(String[] args) throws IOException 
	{
              //  Scanner in = new Scanner(System.in);
              int n , k ;
              String s2 = br.readLine();
              n = Integer.parseInt(s2.split(" ")[0]);
              k = Integer.parseInt(s2.split(" ")[1]);
              String s = br.readLine() ;
              br.close();
              char[] c = s.toCharArray();
              char[] dis = new char[n] ;
              int d1 , d2;
              for(int i=0 ; i<n ; i++){
                  if(k == 0) dis[i] = c[i];
                  else{
                      d1 = 'z' - c[i];
                      d2 = c[i] - 'a' ;
                      if(k >= d1 && k >= d2){
                      if(d1 > d2){
                          dis[i] = 'z' ;
                          k -= d1 ;
                      }else{
                          dis[i] = 'a' ;
                          k -= d2 ;
                      }
                      }
                      else{
                      if(c[i] + k <= 'z') dis[i] = (char)(c[i]+k) ;
                      else dis[i] = (char)((int)c[i] - k) ;
                      k = 0;
                     }
                  }
              }
              
              if(k != 0) {
                 System.out.println("-1");
                  return ;
              }
              System.out.println(new String(dis));
              
        }
        
}