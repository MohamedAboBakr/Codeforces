import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
   int x1,x2,x3,x4,y1,y2,y3,y4;
   x1 = input.nextInt();
   y1 = input.nextInt();
   x2 = input.nextInt();
   y2 = input.nextInt();
   if(x1 == x2){
       int def  = Math.abs(y1-y2);
       x3 = x4 = x1+def;
       y3 = y1;
       y4 = y2;
       System.out.printf("%d %d %d %d\n",x3,y3,x4,y4);
   }
  else if(y1 == y2){
       int def  = Math.abs(x1-x2);
       y3 = y4 = y1+def;
      x3 = x1;
      x4 = x2;
       System.out.printf("%d %d %d %d\n",x3,y3,x4,y4);
   }
  else{
      int def1 = Math.abs(x1-x2);
      int def2 = Math.abs(y1-y2);
      if(def1==def2){
          x3 = x2;
          y3 = y1;
          x4 = x1;
          y4 = y2;
          System.out.printf("%d %d %d %d\n",x3,y3,x4,y4);
          
      }
      else{
          System.out.printf("%d\n",-1);
      }
  }
  }
}