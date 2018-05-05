import java.util.*;
public class DP {

    static int n ; 
    static int[] a ;
    static int max_size = 0 , count =0;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        a = new int[n];
        for(int i = 0 ; i<n ; i++){
            a[i] = in.nextInt();
        }
        
        for(int i=1 ; i<n ; i++){
            if(a[i] >= a[i-1]) count ++;
            else{
                max_size = Math.max(max_size,count);
                count = 0;
            }
        }
         max_size = Math.max(max_size,count);
       
       System.out.println(max_size+1);
    }
    

    
}