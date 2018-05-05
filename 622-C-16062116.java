import java.io.*;
import java.util.*;
public class CodeForces
{
	
        public static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	public static void main(String[] args) throws IOException
	{
               
                String s1 = reader.readLine();
                int n = Integer.parseInt(s1.split(" ")[0]);
                int m = Integer.parseInt(s1.split(" ")[1]);
          
                String[] s2 = reader.readLine().split(" ");
                int[] a = new int[n];
  

                for(int i = 1 ; i<n ; i++){
                    a[i] = (s2[i].equals(s2[i-1]))? a[i-1] : i;
                }
                
                int l , r  , index , j;
                String query , x;
                String[] b ;
                StringBuilder output = new StringBuilder();
                for(int i=0 ; i<m ; i++){
                    query = reader.readLine();
                    b = query.split(" ");
                    
                    l = Integer.parseInt(b[0]) ;
                    r = Integer.parseInt(b[1]) ;
                    x = b[2] ;
                    
                    index = (!(s2[r-1].equals(x)))? r :
                            ( a[r-1] < l  ) ? -1 :
                              a[r-1] ;
                    
                    output.append(String.valueOf(index) + "\n");

                }
                System.out.printf("%s",output);
               
        }
}