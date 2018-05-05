import java.util.*;
public class DP {

    static long n , len; 
    static long[] dp ;
    static long[] flag ;
    static long[] a ;
    static Set<Long> set ;
    static Object[] elements ;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextLong();
        dp = new long[100001];
        a = new long[100001];
        flag = new long[100001];
        set = new TreeSet<>();
        long x ;
        for(int i=0 ; i<n ;i++){
             x = in.nextLong();
             a[(int)x] ++;
             set.add(x);
        }
        len = set.size();
        elements = new Object[(int)len];
        elements = set.toArray();
         solve(0,0);
         System.out.println(dp[0]);
    }
    
    static long solve(int index , long last){
        if(index == len) return 0;
        long curr = (long)elements[index] ;
        if( curr == last){
            return solve(index+1 , 0);
        }
        if(flag[index] == 1){
            return dp[index];
        }
        flag[index] = 1;
        long ans1 , ans2 ;
        ans1 = curr*a[(int)curr] + solve(index+1 , curr+1 );
        ans2 = solve(index+1 , 0);
        dp[index] = Math.max(ans1,ans2);
        return dp[index];
    } 
    

    
}