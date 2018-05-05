import java.util.Scanner;

public class Main{
    public static void main(String[] args){
      Scanner in = new Scanner(System.in);
     int n = in.nextInt();
     int t = in.nextInt();
     int[] a = new int[n-1];
     for(int i=0;i<n-1;i++){
      a[i] = in.nextInt();
 }
int k=1,i=1;
   while(k<n){
     k = i+a[i-1];
     if(k==t){
      System.out.println("YES");
      return;     
}
     i = k;
    
}
    System.out.println("NO");
} 

}