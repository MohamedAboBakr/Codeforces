import java.util.Scanner;

public class Main{
     public static void main(String[] args){

        Scanner in = new Scanner(System.in);

         int n = in.nextInt();
if(n==1){
    System.out.println(1);
   return;
}
        int[] a =new int[10000];
        int[] b = new int[10000];

     a[1] = 1;
     b[1] = 1;
    for(int i =2;i>0;i++){
       a[i] = a[i-1]+i;
       b[i] = a[i] + b[i-1];
      if(b[i]==n){
        System.out.printf("%d\n",i);
        return;
}
     if(b[i]>n){
      System.out.printf("%d\n",i-1);
        return;
}


} 
}


}