import java.util.*;
public class DP {

    static int n ; 
    static int[] dp ;
    static int[] flag ;
    static int[] a ;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        a = new int[3] ;
        a[0] = in.nextInt();
        a[1] = in.nextInt();
        a[2] = in.nextInt();
        Arrays.sort(a);
        dp = new int[n+1];
        flag = new int[n+1];
         int max =  solve(n , 0);
         System.out.println(max);
    }
    
    static int solve(int rest ,int steps){
        
        if(rest < 0) return -1;
        if(rest == 0){
            return steps;
        }
        
        if(flag[rest] == 1) return dp[rest];
        flag[rest] = 1;
        int x1 , x2 , x3 ;
        
        x1 = solve(rest-a[0] , steps+1);
        x2 = solve(rest-a[1] , steps+1);
        x3 = solve(rest-a[2], steps+1);
        
        dp[rest] = Math.max(x1, Math.max(x2,x3));
        
        return dp[rest];
         
    }
  
    
}