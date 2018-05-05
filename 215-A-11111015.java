import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
       int n =input.nextInt();
       long[] a = new long[n];
       for(int i=0;i<n;i++) a[i] = input.nextInt();
       int m = input.nextInt();
       long[] b = new long[m];
        for(int i=0;i<m;i++) b[i] = input.nextInt();
        long[] test = new long[n*m];
        int count =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(b[i]%a[j] ==0){
                    test[count++] = b[i]/a[j];
                }
            }
        }
        int num=1;
      long max = test[0];
      for(int i=1;i<count;i++){
          if(test[i]>max){
              max = test[i];
              num=1;
          }
          else if(test[i]==max) num++;
      }
 
        System.out.printf("%d\n",num);
}
}