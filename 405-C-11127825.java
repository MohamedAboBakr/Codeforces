import java.util.Scanner;
import java.util.Arrays;
import java.io.*;
public class Binarysearch {
    public static void main(String[] args)throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
    int n = Integer.parseInt(reader.readLine());
    int[][] a = new int[n][n];
       for(int i=0;i<n;i++){
           String[] row = reader.readLine().split(" ");
             for(int j=0;j<n;j++){
                 a[i][j] = Integer.parseInt(row[j]);
             }
         }
      int sum = Sum(a,0)%2;   
       StringBuilder x = new StringBuilder("");
         long g = Integer.parseInt(reader.readLine());
         while(g!=0){
             String[] r = reader.readLine().split(" ");
             if(Integer.parseInt(r[0]) ==3) {
                 x.append(Integer.toString(sum));
             } 
             else {
                 sum^=1;
             } 
             g--;
         }
         System.out.println(x.toString());
         reader.close(); writer.close();
}
 public static int Sum(int[][] s,int test){
        if(test==  s[0].length) return 0;
        int sum =0;
        for(int i=0;i<s[0].length;i++){
            sum+= (s[test][i]*s[i][test]);
        }
        return sum%2 + Sum(s,test+1);
    }
}