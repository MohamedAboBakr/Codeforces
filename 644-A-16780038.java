import java.io.*;
import java.util.*;


public class CodeForces
{
      
     static Scanner in = new Scanner(System.in);  
       
    public static void main(String[] args) throws IOException 
	{
               int  n , a ,b ;
               n = in.nextInt();
               a = in.nextInt();
               b = in.nextInt();
               if(a*b < n) {
                   System.out.println(-1);
                   return ;
               
               }
               
               int[][] arr = new int[a][b];
               int count = 0 , first_odd = 1 , first_even = 2;
               for(int i =0 ; i<a ; i++){
                   for(int j = 0 ; j<b ; j++){
                       if(count >= n) System.out.printf("0%s",(j == b-1)? "" : " ");
                       else{
                           if(i>0){
                               if(arr[i-1][j]%2  == 0) {
                                   if(first_odd <= n){
                                       System.out.printf("%d%s",first_odd,(j == b-1)? "" : " ");
                                       arr[i][j] = first_odd ;
                                       first_odd += 2 ;
                                       count++ ;
                                   }
                                   else {
                                       System.out.printf("0%s",(j == b-1)? "" : " ");
                                       arr[i][j] = 0 ;
                                   }
                               }
                               else {
                                   if(arr[i-1][j]%2  == 1) {
                                   if(first_even <= n){
                                       System.out.printf("%d%s",first_even,(j == b-1)? "" : " ");
                                       arr[i][j] = first_even ;
                                       first_even += 2 ;
                                       count++ ;
                                   }
                                   else {
                                       System.out.printf("0%s",(j == b-1)? "" : " ");
                                       arr[i][j] = 0 ;
                                   }
                               }
                           }
                       }
                           
                           else {
                               if(j%2 == 0 && first_odd <= n){
                                       System.out.printf("%d%s",first_odd,(j == b-1)? "" : " ");
                                       arr[i][j] = first_odd ;
                                       first_odd += 2 ;
                                       count++ ;
                               }
                               if(j%2 == 1 && first_even <= n){
                                       System.out.printf("%d%s",first_even,(j == b-1)? "" : " ");
                                       arr[i][j] = first_even ;
                                       first_even += 2 ;
                                       count++ ;
                               }
                           }
                   }
                  
               }
                    System.out.println();
           } 
        }
}