import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
       int n =input.nextInt();
      String[] a = new String[n];
       input.nextLine();
      for(int i=0;i<n;i++)
      {
          a[i] = input.nextLine();
      }
      int k=0,sum1=1,sum2=0;
      for(int i=1;i<n;i++){
         if(a[0].equals(a[i]))sum1++; 
         else{
             sum2++;
             k=i;
         }
      
      }
      if(sum1>sum2)System.out.printf("%s\n",a[0]);
      else System.out.printf("%s\n",a[k]);
      }
}