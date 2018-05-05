import java.util.*;

public class Topcoder {

    
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
        int flag = 0 , k=0; 
        int[][] p = new int[4][4];
        int[] len = new int[4];
        for(int i=0;i<4;i++){
            p[i][0] = input.nextInt();
            p[i][1] = input.nextInt();
            p[i][2] = input.nextInt();
            p[i][3] = input.nextInt();
        }
        
        
        flag = test(p , 1 ,2,3,4);
        if(flag == 1) {
            System.out.println("YES");
            return;
        }
        flag = test(p , 1 ,2,4,3);
        if(flag == 1) {
            System.out.println("YES");
            return;
        }
        flag = test(p , 1 ,3,2,4);
        if(flag == 1) {
            System.out.println("YES");
            return;
        }
        flag = test(p , 1 ,3,4,2);
        if(flag == 1) {
            System.out.println("YES");
            return;
        }

       else System.out.println("NO");
       
    }
    
 static int test(int[][] p , int n1 , int n2 , int n3 , int n4){
     
     if(check_ok(p[n1-1][0],p[n1-1][1],p[n1-1][2],p[n1-1][3]) == 0 ||
        check_ok(p[n2-1][0],p[n2-1][1],p[n2-1][2],p[n2-1][3]) == 0 ||
        check_ok(p[n3-1][0],p[n3-1][1],p[n3-1][2],p[n3-1][3]) == 0 ||
        check_ok(p[n4-1][0],p[n4-1][1],p[n4-1][2],p[n4-1][3]) == 0       ) {
         
         return 0;
     }
     
     if(check_vert(p[n1-1][0],p[n1-1][1],p[n1-1][2],p[n1-1][3],p[n3-1][0],p[n3-1][1],p[n3-1][2],p[n3-1][3]) == 1
        &&check_hor(p[n2-1][0],p[n2-1][1],p[n2-1][2],p[n2-1][3],p[n4-1][0],p[n4-1][1],p[n4-1][2],p[n4-1][3]) == 1
        && Math.max(p[n1-1][0], p[n3-1][0]) == Math.max(p[n2-1][0], p[n2-1][2]) &&
           Math.max(p[n1-1][1], p[n1-1][3]) == Math.max(p[n2-1][1], p[n4-1][1])  ){
         return 1;
     }
     
    
     if(check_hor(p[n1-1][0],p[n1-1][1],p[n1-1][2],p[n1-1][3],p[n3-1][0],p[n3-1][1],p[n3-1][2],p[n3-1][3]) == 1
        &&check_vert(p[n2-1][0],p[n2-1][1],p[n2-1][2],p[n2-1][3],p[n4-1][0],p[n4-1][1],p[n4-1][2],p[n4-1][3]) == 1
        && Math.max(p[n1-1][0], p[n1-1][2]) == Math.max(p[n2-1][0], p[n4-1][0]) &&
           Math.max(p[n1-1][1], p[n3-1][1]) == Math.max(p[n2-1][1], p[n2-1][3])  ){
         return 1;
     }
     return 0;
     
 }
 
 static int check_ok(int x1 , int y1 , int x2 , int y2){
     if(x1 == x2 || y1==y2) return 1;
     return 0;
 }
 
 static int check_vert(int x1 , int y1 , int x2 , int y2 , int x3 ,int y3 , int x4 , int y4){
        if(x1==x2 && x3==x4 && x2!= x3){
           if( Math.abs(y1-y2) == Math.abs(y3-y4)){
               if((y1==y3)||(y1==y4)) return 1;
               return 0;
           }
           return 0;
        }
        return 0;
 }
    
  static int check_hor(int x1 , int y1 , int x2 , int y2 , int x3 ,int y3 , int x4 , int y4){
        if(y1==y2 && y3==y4 && y2 != y3){
           if( Math.abs(x1-x2) == Math.abs(x3-x4)){
               if((x1==x3 )||(x1==x4)) return 1;
               return 0;
           }
           return 0;
        }
        return 0;
 }
  
  
}