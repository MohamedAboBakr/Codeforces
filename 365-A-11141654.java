import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args){
       Scanner input = new Scanner(System.in);
       int n = input.nextInt();
       int k = input.nextInt();
       input.nextLine();
       char[] test = new char[k+1];
       for(int i=0;i<=k;i++) test[i] = (char)(i+48);
       int sum=0,flag=0;
       while(n!=0){
           String s = input.nextLine();
           for(int i=0;i<=k;i++){
               if(s.indexOf(test[i]) > -1) flag++;
           }
           if(flag== k+1) sum++;
           flag=0;
           n--;
       }
    System.out.printf("%d\n",sum);
}
}