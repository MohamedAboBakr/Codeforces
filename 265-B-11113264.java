import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
       int n =input.nextInt();
      int[] height = new int[n];
      for(int i=0;i<n;i++){
          height[i] = input.nextInt();
      }    
      long sum =0;
     sum+=height[0];
     sum+=n;
      for(int i=0;i<(n-1);i++){
          if(height[i]==height[i+1]){
              sum+=1;
              continue;
          }
          else if(height[i]<height[i+1]){
              sum+=1;
              sum+= height[i+1]-height[i];
              continue;
          }
          else{
              sum+=1;
              sum+= height[i]-height[i+1];
          }
       
      }
      System.out.printf("%d\n",sum);
}
}