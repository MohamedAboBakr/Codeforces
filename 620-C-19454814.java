import java.util.*;

public class Pearls {
    
    // C. Pearls in a Row
    public static void main(String[] args) {
        Scanner  input = new Scanner(System.in);
        int n  , m , k = 0;
        n = Integer.parseInt(input.nextLine());
        int start = 0;
        String[] s = input.nextLine().split(" ");
        
        int[][] arr = new int[n][2];
        Set<Integer> good_segment = new HashSet<>();
        for(int i=0; i<n ; i++){
            m = Integer.parseInt(s[i]);
            if( good_segment.contains(m)){
                arr[k][0] = start +1 ;
                arr[k][1] = i +1;
                good_segment.clear();
                k++;
                start = i+1;
            }
            else{
                good_segment.add(m);
            }
        }
        if(k == 0) {
            System.out.println("-1");
            return ;
        }
        
        arr[k-1][1] = n;
        System.out.println(k);
        for(int i=0;i<k;i++){
            System.out.println(arr[i][0] + " " + arr[i][1]);
        }
    }
    
}