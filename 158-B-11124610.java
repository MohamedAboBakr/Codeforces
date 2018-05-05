import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
          int n= input.nextInt();
          int[] a = {0,0,0,0};
          while(n!=0){
              int x = input.nextInt();
              a[x-1]++;
              n--;
          }
          int sum =0;
          sum+= a[3];
          sum+= a[2];
          sum+= a[1]*2 /4;
          int rem = (a[1]*2 )%4;
          if(a[0]<= a[2]) sum+= Math.ceil((double)rem/4);
          else sum+= Math.ceil((double)(rem+a[0]-a[2])/4); 
          
          System.out.printf("%d\n",sum);
}
}