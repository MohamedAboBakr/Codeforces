import java.util.Arrays;
import java.util.Scanner;
/**
 *
 * @author p
 */
public class Codeforces {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner input = new Scanner(System.in);
        int k = input.nextInt();
        int[] a = new int[k];
        int prog_sum=0,pro[] = new int[k];
        int math_sum=0,ma[] = new int[k];
        int pe_sum=0 ,p[] = new int[k];
        for(int i=0;i<k;i++){
            a[i] = input.nextInt();
            if(a[i]==1){
                pro[prog_sum++] = i+1; 
            }
            else if(a[i] ==2){
                ma[math_sum++] = i+1;
                
        }
            else {
               p[pe_sum++] = i+1;
              }
        }
        if(prog_sum==0 || math_sum==0 || pe_sum==0){
            System.out.println(0);
            return;
         }
        int min = Math.min(prog_sum, Math.min(math_sum,pe_sum));
        System.out.printf("%d\n",min);
        for(int i=0;i<min;i++){
           System.out.printf("%d %d %d\n",pro[i],ma[i],p[i]);
        }
    }
    
}