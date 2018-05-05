import java.util.*;

public class CodeForces {
    
    // C. Pearls in a Row
    public static void main(String[] args) {
        Scanner  input = new Scanner(System.in);
        int n  = input.nextInt() , x , Max = 0 , flag = 0;
        int[] arr = new int[n];
        for(int i = 0; i< n ;i++){
            int max = 0;
            for(int j = 0 ; j<n ; j++){
                x = input.nextInt();
                max = (x > max)? x : max ;
            }
            arr[i] = max;
            Max = (Max > max)? Max : max ;
        }
        
        for(int i=0; i<n  ; i++){
            if(arr[i] == Max && flag == 0) {
                System.out.printf("%d%s",arr[i]+1 , (i == n-1)?"\n" : " ");
                flag = 1;
            }
            else System.out.printf("%d%s",arr[i] , (i == n-1)?"\n" : " ");
        }
       
    }
  
}