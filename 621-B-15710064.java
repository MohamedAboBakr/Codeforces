import java.util.*;

public class CodeForces {
    
    // C. Constellation
    public static void main(String[] args) {
        Scanner  input = new Scanner(System.in);
        int n = input.nextInt();
        int i , j , x , y , k , max = 0 , sum;
        int[] diag1 = new int[1999];
        int[] diag2 = new int[1999];
        for(i=0;i<n;i++){
             x = input.nextInt();
             y = input.nextInt();
             diag1[(1000-x)+(y-1)]++;
             diag2[(x-1)+(y-1)]++;
        }
        
        for(i= 0 ; i<1999 ; i++){
            if(diag1[i] > 1) max += diag1[i]*(diag1[i]-1)  /2 ;
            if(diag2[i] > 1) max += diag2[i]*(diag2[i]-1)  /2 ;
        }
        
        System.out.println(max);
        
    }
  
}