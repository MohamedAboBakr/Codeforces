import java.io.*;
import java.util.*;


public class CodeForces
{
       
    public static void main(String[] args) throws IOException 
	{
                 Scanner in = new Scanner(System.in);
                 int n , l , x , y ;
                 n = in.nextInt();
                 l = in.nextInt();
                 x = in.nextInt();
                 y = in.nextInt();
              
                 int sum = x+y ;
                 int[] a = new int[n];
                 for(int i =0 ; i<n ; i++){
                     a[i] = in.nextInt();
                 }
                
                 List<Integer> x_y_list = new ArrayList<>();
               
                 int x_found = 0 , y_found = 0 , x_plus_y_found = 0 , between_found =  0;
                 for(int i=0 ; i<n ; i++){
                     
                  
                   
                     if(x_found == 1 && y_found == 1){
                         System.out.println(0);
                         return ;
                     }
                     
                     if(x_found == 0){
                         
                         int index = Arrays.binarySearch( a , i , n , x+a[i]);
                         
                         if(index >= 0){
                             x_found = 1 ;
                             
                         }
                     }
                     if(y_found == 0){
                         int index = Arrays.binarySearch(a, i , n ,  y+a[i]);
                         if(index >= 0){
                             y_found = 1 ;
                           
                         }
                     }
                     
                        
                     if(between_found == 0){
                         if((a[i]+x) <= l ){
                            
                         int index = Arrays.binarySearch(a,a[i]+x-y);
                        
                         if(index >= 0) {
                             
                             between_found = 1 ;
                             x_y_list.add(a[i]+x);
                         }
                     }
                         if((a[i]-x) >= 0){
                            int index = Arrays.binarySearch(a,a[i]-x+y);
                           
                            
                          if(index >= 0) {
                              
                             between_found = 1 ;
                             x_y_list.add(a[i]-x);
                         } 
                       }
                         
                     }
                     
                     
                     if(x_plus_y_found == 0 && x != y){
                        int index = Arrays.binarySearch(a, i , n ,  x+y+a[i]);
                         if(index >= 0){
                             x_plus_y_found = 1 ;
                             x_y_list.add(a[i]+x);
                         }
                     }
                     
                 }
                 
                 if(x_found == 1 && y_found == 1){
                         System.out.println(0);
                         return ;
                     }
                 if(x_found == 1) {
                        
                         System.out.println(1 + "\n" + y);
                         return ;
                 }
                 if(y_found == 1){
                        System.out.println(1 + "\n" + x);
                         return ;
                 }
                 if(x_plus_y_found == 1 || between_found == 1){
                        System.out.println(1 + "\n" + (x_y_list.get(0)));
                         return ;
                 }
                
                   System.out.printf("2\n%d %d\n" , x , y);
                     
        }
}