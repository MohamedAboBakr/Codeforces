import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
  int num = input.nextInt();
  int even = 0,e=0;
  int odd = 0,o=0;
  for(int i=0;i<num;i++){
      int x = input.nextInt();
      if(x%2==0){
          even++;
          e=i;
      }
      else{
          odd++;
          o=i;
      }
      
  }
  if(even==1){
      System.out.printf("%d\n",e+1);
  }
  else{
      System.out.printf("%d\n",o+1);
  }
  
  }
}