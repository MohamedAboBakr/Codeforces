import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
    int n = input.nextInt();
    int[] a = new int[n];
    int min=0,min_index=0;
    int max=0,max_index=0;
    for(int i=0;i<n;i++){
        a[i] = input.nextInt();
        if(i==0){
            min=max=a[i];
        }
        else{
            if(a[i] <= min){
                min = a[i];
                min_index=i;
            }
            if(a[i]> max){
                max = a[i];
                max_index = i;
            }
        }
    }
    int max_steps = max_index;
    int min_steps = 0;
    if(max_index> min_index) min_steps = a.length - min_index - 2;
    else min_steps =  a.length - min_index - 1;
    System.out.printf("%d\n",max_steps + min_steps);
  }
}