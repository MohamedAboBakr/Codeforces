import java.util.Scanner;

public class Main{

     public static void main(String[] args){
      Scanner in  = new Scanner(System.in);

      int n = in.nextInt();
     
     int flag =0;
      int num25 = 0 , num50=0;
     for(int i=0;i<n;i++){
     int curr = in.nextInt();
      if(curr == 25) num25++;
      else if(curr == 50){
           if(num25 > 0) {
                  num25--;
                  num50++;
        }
           else{
               flag =1;
           }
}
        else{
               if(num25 >0 && num50 >0) {
                        num25--; num50--;
}
              else if(num25 > 2) num25 -= 3;
              else flag = 1 ; 
        }
}
     if(flag == 1) System.out.println("NO");
     else System.out.println("YES");

}
       
}