import java.util.Scanner;
import java.util.Arrays;
/**
 *
 * @author win7
 */
public class Lifecodechef{

    /**
     * @param args the command line arguments
     */
    private static String vowel = "IE A O U Y";
    public static void main(String[] args)  throws java.lang.Exception{
        // TODO code application logic here
           Scanner input = new Scanner(System.in);
         int n = input.nextInt();
         int m = input.nextInt();
         input.nextLine();
         char[][] a = new char[n][m];
         int[][] b = new int[n][m];
         for(int i=0;i<n;i++){
             String x = input.nextLine();
             a[i] = x.toCharArray();
         }
        for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 char current = a[i][j];
                 int flag =0;
                 for(int k = j+1 ; k < m ;k++){
                     if(a[i][k] == current){
                         b[i][k] = 1;
                         flag =1;
                     }
                   
                 }
                 if(flag==1) b[i][j] = 1;
                 flag=0;
                 for(int r = i+1 ;r<n ;r++){
                    if(a[r][j] == current) {
                        b[r][j] = 1;
                        flag =1;
                    }
                   
                 }
                 if(flag==1) b[i][j] = 1;
             }
         }
        for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 if(b[i][j] == 0) System.out.printf("%c",a[i][j]);
             } 
        }
        System.out.println();
    }
}