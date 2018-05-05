import java.util.Scanner;
import java.util.Arrays;
import java.io.*;
public class Lifecodechef{

    public static void main(String[] args)  throws java.lang.Exception{
        
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // line = br.readLine();
        // TODO code application logic here
         Scanner in = new Scanner(System.in);
         int n = in.nextInt();
         int m = in.nextInt();
         in.nextLine();
         String[] s = new String[n];
         for(int i=0;i<n;i++){
              s[i] = in.nextLine();
         }
         if(n<2 || m<2){
             System.out.println(0);
             return;
         }
         int sum =0;
         for(int i=0;i<n-1;i++){
             for(int j=0;j<m-1;j++){
                char curr = s[i].charAt(j);
                if(curr != 'f' && curr != 'a' && curr != 'c' && curr != 'e') continue;
                else{
                    sum+= check(s,i,j);
                }
             }
         }
         System.out.println(sum);
           
    }
    public static int check(String[] a,int row,int col){
           String ch = a[row].substring(col,col+2);
           ch += a[row+1].substring(col,col+2);
           if(ch.indexOf("f") >-1 && ch.indexOf("a")>-1 && ch.indexOf("c") >-1 && ch.indexOf("e") >-1) return 1;
           return 0;
    }
}