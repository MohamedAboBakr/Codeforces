import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int m = input.nextInt();
        char[][] a = new char[n][m];
        int C = -1;
       for(int i =0;i<n ;i++){
           for(int j =0 ;j<m;j++){
               if(i%2==0) a[i][j] = '#';
               
                else if(i%4 ==1 && j==(m-1))a[i][j] = '#';
                else if(i%4 ==3 && j==0) a[i][j] = '#';
               
               else a[i][j] = '.';
               System.out.printf("%c", a[i][j]);
           }
           System.out.println();
       }   
    }
}