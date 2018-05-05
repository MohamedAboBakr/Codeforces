import java.util.Scanner;
public class Binarysearch {
    public static void main(String[] args){
       Scanner input = new Scanner(System.in);
       int n = input.nextInt();
       if(n==1){    
         System.out.println(0);
      return;
       }
           int index=input.nextInt()-1;
       input.nextLine();
       String s = input.nextLine();
       char[] c = s.toCharArray();
       int start =-1,end =0,min=0,flag=0;
        for(int i=0;i<n/2;i++){
            if(c[i]==c[n-1-i]) continue;
            int def = Math.abs((int)c[i]-(int)c[n-1-i]);
            min+= Math.min(def,26-def);
            if(start==-1) start =i;
            else end =i;
        }
  if(min==0){
 System.out.println(0);
return;
}
        if(index >= n/2){
            start = n-1-start;
            end = (end==0)?0: n-1-end;
        }
        if(end!=0){
            min+= Math.abs(start-end)+Math.min(Math.abs(start-index),Math.abs(end-index));
        }
        else min+= Math.abs(start-index);
   
    System.out.printf("%d\n",min);
}
}