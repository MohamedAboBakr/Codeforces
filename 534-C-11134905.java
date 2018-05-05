import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args){
       Scanner input = new Scanner(System.in);
       int n = input.nextInt();
       long r = input.nextLong();
      StringBuilder s = new StringBuilder();
       long[] a = new long[n];
       long[] b = new long[n];
       long sum =0,max=r-(n-1),min=0;
       for(int i=0;i<n;i++){
           a[i] = input.nextLong();
           sum+= a[i];
       }
       long cur_sum =0;
        for(int i=0;i<n;i++){
           cur_sum = sum - a[i];
           min = r - cur_sum;
           if(min <=0) b[i] = a[i]-max;
           else if(max > a[i]) b[i] = min -1;
           else b[i] = a[i] - (max+1-min);
          if(b[i]<0)b[i]=0;
         s.append(b[i]);
       if(i != n-1) s.append(" ");
       }
System.out.println(s);
}
}