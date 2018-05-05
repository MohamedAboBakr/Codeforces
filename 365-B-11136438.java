import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args){
       Scanner input = new Scanner(System.in);
       int m = input.nextInt();
       long[] a = new long[m];
       if(m<3){
           System.out.printf("%d\n",m);
           return;
       }
       int l=0,r=0,len=0;
       for(int i=0;i<m;i++){
           a[i] = input.nextLong();
           if(i>1){
               if(a[i] == a[i-1]+a[i-2]){
                   r=i;
                  // System.out.printf("%d\n",r);
               }
               else{
                   len=Math.max(len,r-l+1);
                   l=i-1;
               }
           }
       }
        len=Math.max(len,r-l+1);
       if(len==1){
           if(m==1)System.out.println(1);
           else System.out.println(2);
       }
       else System.out.printf("%d\n",len);
}
}