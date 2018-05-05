import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args){
       Scanner input = new Scanner(System.in);
       int n = input.nextInt();
       int[] a= new int[100];
        input.nextLine();
       String s = input.nextLine();
       int count =0;
       a[count++] = 0;
       for(int i=1;i< s.length();i++){
           if(s.lastIndexOf(s.charAt(i), i-1) <0) a[count++]= i;
       }
       if(count<n){
           System.out.println("NO");
           return;
       }
       System.out.println("YES");
       for(int i=0;i<n;i++){
           if(i == n-1) System.out.println(s.substring(a[i]));
           else  System.out.println(s.substring(a[i],a[i+1]));
       }
}
}