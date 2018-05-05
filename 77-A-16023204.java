import java.util.*;

public class Topcoder {

    
    public static void main(String[] args) {
        
        
        /*
         Anka, barbarian Chapay, sorceress Cleo, druid Troll, 
        necromancer Dracul, paladin Snowy and a professional hit girl Hexadecimal
        */
        Scanner input = new Scanner(System.in);
        int[][] likes = new int[7][7]; 
        int n = input.nextInt();
        input.nextLine();
        int p , q , a , b , c;
        String[] names = new String[7];
        String s;
        names[0] = "Anka";
        names[1] = "Chapay";
        names[2] = "Cleo";
        names[3] = "Troll";
        names[4] = "Dracul";
        names[5] = "Snowy";
        names[6] = "Hexadecimal";
        
        for(int i=0 ; i<n ; i++){
            s = input.nextLine(); 
            p =  Arrays.asList(names).indexOf(s.split(" ")[0]);
            q =  Arrays.asList(names).indexOf(s.split(" ")[2]);
            likes[p][q] = 1;   
        } 
        
        a = input.nextInt();
        b = input.nextInt();
        c = input.nextInt();
       
        
        int[] evils = new int[3];
        int[][] sets = new int[15][4];
        int[][] in_teams = new int[5040][7];
        evils[0] = a; evils[1] = b; evils[2] = c;
        int[] arr_1  = new int[3];
        int[] arr_2  = new int[7];
        int[] flag = new int[7];
        
    /*   for(int i=0 ; i<7 ; i++){
            for(int  j= 0 ; j<7 ; j++){
                System.out.printf("%d ",likes[i][j]);
            }
            System.out.println();
        }*/
       
        set_sets_1(sets , arr_1 , evils , 0 , 0);
        set_sets_2(in_teams , arr_2 , flag , 0);
    /*   for(int i = 0 ; i< 15 ; i++){
     System.out.println(sets[i][0] + " " + sets[i][1] + " " + sets[i][2] + " " + sets[i][3]);
        }*/
        int min_1 = get_min_2(sets);
        int min_2 = get_min_3(min_1, in_teams , sets , likes);
        System.out.println(min_1 + " " + min_2);
        
    }
    
    // in main
    static void set_sets_1(int[][]sets , int[] arr , int[] evil , int sum , int index){
        if(index == 2){
            arr[2] = 7-sum;
            add_set(sets,arr,evil);
            return ;
        }
        
        int i ;
        for(i = 1 ; i < 6 ; i++){
            if((7-(sum+i)) >= (3-index-1)){
                arr[index] = i;
                set_sets_1(sets,arr,evil,sum+i,index+1);
            }
        }
        
    }
    
    static void add_set(int[][] sets, int[] arr , int[] evil){
       int i ; 
       for(i=0;i<15 ; i++){
           if(sets[i][0] == 0) break;
       }
       sets[i][0] = arr[0];
       sets[i][1] = arr[1];
       sets[i][2] = arr[2];
       sets[i][3] = get_min_1(arr,evil);
 }
    
    static int get_min_1(int[] arr , int[] evil){
        int[]  a = new  int[3];
     //   if(evil[0]<arr[0] || evil[1]<arr[1] || evil[2]<arr[2]) return -1;
        a[0] = (int)Math.floor(evil[0]/arr[0]);
        a[1] = (int)Math.floor(evil[1]/arr[1]);
        a[2] = (int)Math.floor(evil[2]/arr[2]);
        
        Arrays.sort(a);
        return a[2]-a[0];
    }
    
    // in main
    static int get_min_2(int[][] sets){
        int min = sets[0][3];
       //   System.out.println(sets[0][0] + " " + sets[0][1] + " " + sets[0][2] + " " + sets[0][3]);
        for(int i=0; i<15 ; i++){
           
                if (sets[i][3] < min) min = sets[i][3];
          //      System.out.println(sets[i][0] + " " + sets[i][1] + " " + sets[i][2] + " " + sets[i][3]);
            }
                 
             
        return min ;
    }
    
    
    // in main
    static void set_sets_2(int[][] teams ,int[] arr, int[] flag,int index){
         if(index == 7){
             add_set_2(teams , arr);
             return ;
         }
         
         int i ;
       for(i = 0 ; i < 7  ; i++ ){
      if(flag[i] == 0){
         arr[index] = i+1;
         flag[i] = 1;
         set_sets_2(teams , arr , flag , index+1);
         flag[i] = 0;
      }

  }
    }
    
    static void add_set_2(int[][] teams ,int[] arr){
        int i;
        
        for(i=0; i<5040 ; i++){
            if(teams[i][0] == 0) break;
        }
        
        for(int j = 0 ; j < 7 ; j++){
            teams[i][j] = arr[j];
        }
    }
    
    // in main
    
    static int get_min_3(int min , int[][] teams , int[][] sets , int[][] likes){
        
        int m = 0 , x;
        for(int i = 0 ; i<15 ; i++){
            if(sets[i][3] == min){
                x = get_likes(sets[i] , teams , likes);
                m = (x > m )? x : m;
            }
        }
        
        return m;
    }
    
    static int get_likes(int[] set ,int[][] teams , int [] []likes){
        
       // System.out.println(set[0]+ " "+ set[1]+ " " +set[2]);
        int max = 0;
        for(int i = 0 ; i < 5040 ; i++){
            int m = 0 , index = 0;
            
            for(int j= index ; j<set[0] ; j++){
                for(int k=j+1 ; k<set[0] ; k++){
                    m += likes[teams[i][k]-1][teams[i][j]-1];
                    m += likes[teams[i][j]-1][teams[i][k]-1];
                }
                
                
            }
            
            index += set[0];
            for(int j= 0 ; j<set[1] ; j++){
                for(int k=j+1 ; k<set[1] ; k++){
                    m += likes[teams[i][k+index]-1][teams[i][j+index]-1];
                    m += likes[teams[i][j+index]-1][teams[i][k+index]-1];
                }
                
            }
            index += set[1];
            for(int j= 0 ; j<set[2] ; j++){
                for(int k=j+1 ; k<set[2] ; k++){
                    m += likes[teams[i][k+index]-1][teams[i][j+index]-1];
                    m += likes[teams[i][j+index]-1][teams[i][k+index]-1];
                }
                
           
            }
            
            max = (m>max)? m : max ;
        }
       return max ; 
    }
}