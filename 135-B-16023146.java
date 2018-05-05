import java.util.*;

public class Topcoder {

    
    public static void main(String[] args) {
        
        
        /*
         Anka, barbarian Chapay, sorceress Cleo, druid Troll, 
        necromancer Dracul, paladin Snowy and a professional hit girl Hexadecimal
        */
        Scanner input = new Scanner(System.in);
        int[][] p = new int[8][2];
        for(int i = 0 ; i<8 ; i++){
            p[i][0] =  input.nextInt();
            p[i][1] =  input.nextInt();
        }
        
        int[][] sets = new int[1680][5];
        int[] flag = new int[8];
        int[] arr = new int[4];
        
        List<int[]> rect = new ArrayList<>();
        List<int[]> squ =  new ArrayList<>();
        set_points(sets,arr,flag,0);
        check_sets(sets,p,rect,squ);
        
        if(squ.isEmpty()) {
            System.out.println("NO");
            return ;
        }
        if(rect.size()>0){
            for(int i=0 ; i<rect.size() ; i++){
                for(int j = 0 ; j<squ.size() ; j++){
                    if(differ(rect.get(i) , squ.get(j)) == 1){
                        System.out.println("YES");
                        print(rect.get(i),squ.get(j));
                        return ;
                    }
                }
            }
        }
        
        for(int i=0 ; i<squ.size() ; i++){
            for(int j=i+1 ; j<squ.size() ; j++){
                if(differ(squ.get(i) , squ.get(j)) == 1){
                    System.out.println("YES");
                     print(squ.get(i) , squ.get(j));
                        return ;
                }
            }
        }
        
        System.out.println("NO");
    }
    
    
    
    static int differ(int[] a ,int[] b){
        for(int i=0 ; i<4 ; i++){
            for(int j=0 ; j<4 ; j++){
                if(a[i] == b[j]) return 0;
            }
        }
        return 1;
    }
    
    static void print(int[] a ,int[] b){
        System.out.println(b[0] + " " + b[1] + " " + b[2] + " " + b[3]);
        System.out.println(a[0] + " " + a[1] + " " + a[2] + " " + a[3]);
    }
    // in main
    static int counter = 0;
    static void set_points(int[][] sets , int[] arr , int[] flag ,int index){
        if(index == 4){
           sets[counter][0] = arr[0];
           sets[counter][1] = arr[1];
           sets[counter][2] = arr[2];
           sets[counter][3] = arr[3];
           counter ++;
           return ;
        }
        
        for(int i = 0 ; i<8 ; i++){
             if(flag[i] == 0){
                 flag[i] = 1;
                 arr[index] = i+1;
                 set_points(sets , arr , flag , index+1);
                 flag[i] = 0;
             }
        }
        
        
    }
    
    
    // in main
    static void check_sets(int[][] sets , int[][] p , List<int[]> rec , List<int[]> sq){
         for(int i=0 ; i<1680 ; i++){
             int result = is_valid(sets[i] , p);
             if(result == 1) sq.add(sets[i]);
             else if(result == 2) rec.add(sets[i]);
             remove_set(sets[i] , sets);
         }
    }
    static void remove_set(int[] set , int[][] sets){
        int[] arr = new int[4];
        arr = reverse(set);
        cancel(arr,sets);
        
        for(int i = 0 ; i<3 ; i++){
            arr = shift(arr);
            cancel(arr,sets);
            arr = reverse(arr);
            cancel(arr,sets);
        }
        
    }
    
    static void cancel(int[] arr , int[][] sets){
        for(int i=0 ; i<1680 ; i++){
            if(arr[0]==sets[i][0] && arr[1]==sets[i][1] && arr[2]==sets[i][2] && arr[3]==sets[i][3]){
                sets[i][4] = -1;
                break;
            }
        }
    }
    static int[] shift(int[] arr){
        int[] a = new int[4];
        a[3] = arr[2];
        a[2] = arr[1];
        a[1] = arr[0];
        a[0] = arr[3];
        return a;
    }
    static int[] reverse(int[] set){
         int[] a = new int[4];
         a[0] = set[3];
         a[1] = set[2];
         a[2] = set[1];
         a[3] = set[0];
         return a;
    }  
    static int is_valid(int[] set , int[][] p ){
        int x1 , x2 ,x3 , x4, y1, y2 , y3 , y4;
        x1 = p[set[0]-1][0] ; y1 = p[set[0]-1][1];
        x2 = p[set[1]-1][0] ; y2 = p[set[1]-1][1];
        x3 = p[set[2]-1][0] ; y3 = p[set[2]-1][1];
        x4 = p[set[3]-1][0] ; y4 = p[set[3]-1][1];
        double slope1 = get_slope(x1, y1 , x2 , y2);
        double slope2 = get_slope(x2, y2 , x3 , y3);
        double slope3 = get_slope(x3, y3 , x4 , y4);
        double slope4 = get_slope(x4, y4 , x1 , y1);
        int len1, len2 , len3 , len4;
        len1 = get_len(x1 , y1 , x2 , y2);
        len2 = get_len(x2 , y2 , x3 , y3); 
        len3 = get_len(x3 , y3 , x4 , y4);
        len4 = get_len(x4 , y4 , x1 , y1);
        
        if(slope1 == slope3 && slope2 == slope4 && len1== len3 && len2 == len4 ){
 
         if((slope1== (0.0) && slope2== (-1000000.0)) || (slope1==(-1000000.0) && slope2==(0.0)) || (slope1*slope2 == (-1.0))){
            if(len3 == len2 )return 1;
            return 2;
          }
       
        }
        return 0;
    }
    
    static double get_slope(int x1, int y1 , int x2 , int y2){
        if(x2-x1 == 0) return -1000000.0;
        else if(y2==y1) return 0.0;
        return 1.0*(y2-y1)/(x2-x1); 
    }
    
    static int get_len(int x1, int y1 , int x2 , int y2){
        return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2); 
    }
    
    
    
}