import java.util.Scanner;
import java.util.Arrays;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
           int n= input.nextInt();
           int m= input.nextInt();
           int[] a = new int[m];
           int[] max_test = new int[m];
           int[] min_test= new int[m];
    for(int i=0;i<m;i++){
        a[i] = input.nextInt();
        max_test[i] = min_test[i] = a[i];
    }
        int sum_max=0;
        for(int i=0;i<n;i++){
          Arrays.sort(max_test);
          sum_max+= max_test[m-1];
          max_test[m-1] --;
        }
         int sum_min=0;
        for(int i=0;i<n;i++){
          Arrays.sort(min_test);
          sum_min+= min_test[0];
          if(min_test[0]-1 ==0) min_test[0] = min_test[m-1];
          else min_test[0]--;
        }
        System.out.printf("%d %d\n",sum_max,sum_min);
}
}