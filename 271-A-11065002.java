import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
       int year = input.nextInt();
       year++;
       while(true){
           int x = year%1000;
           int y = year/1000;
           int t = x%100;
           int r = x/100;
           int p = t%10;
           int g = t/10;
           if(y==r || y==p || y==g || r==p || r==g || p==g) year++;
           else break;
       }
       System.out.printf("%d\n",year);
        
    }
}