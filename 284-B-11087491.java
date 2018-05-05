import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        input.nextLine();
       String one = input.nextLine();
          int sum=0,sumi=0;
          for(int i=0;i<one.length();i++){
              if(one.charAt(i)=='A')sum++;
              else if(one.charAt(i)=='I')sumi++;
          }
          if(sumi>1)System.out.printf("%d\n",0);
          else if(sumi ==1)System.out.printf("%d\n",1);
          else{
          System.out.printf("%d\n",sum);
          }
    }
}