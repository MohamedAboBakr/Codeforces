import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

public class CodeForces {

   
    public static void main(String[] args) throws FileNotFoundException {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int m = input.nextInt(); 
        input.nextLine();
        String[] s = new String[n];
        int[][] grid = new int[n][n];
        int[] arr = new int[n];
        for(int i= 0 ; i < n ; i++){
            s[i] = input.nextLine();
        }
        List<String> list = Arrays.asList(s);
        String s1 , s2 , s3;
        for(int i=0;i<m;i++){
            s3 = input.nextLine();
            s1 = s3.split(" ")[0];
            s2 = s3.split(" ")[1];
            grid[list.indexOf(s1)][list.indexOf(s2)] = 1 ;
            grid[list.indexOf(s2)][list.indexOf(s1)] = 1 ;
        }
        
        
        Map<Integer,TreeSet<String>> map = new HashMap<>();
        count(n,arr,0,map,s,grid);
        
        Object[] values = map.keySet().toArray();
        Arrays.sort(values);
        int size = values.length;
       // System.out.println(size);
        int max = (int)values[size-1]; 
        System.out.println(max);
        TreeSet<String> team = map.get(max);
         Iterator it = team.iterator();
        while (it.hasNext()){
            System.out.println(it.next());
        }
        
        
    }
    
    static void count(int n , int[] arr , int index , Map<Integer,TreeSet<String>> map , String[] names , int[][] grid ){
          if(index == n){
             // print(arr);
              check_set(n,arr,map,names,grid);
              return ;
          }  
        
          for(int i = 0 ; i<2 ; i++){
               arr[index] = i ; 
               count(n,arr,index+1,map,names,grid);
          }
        
    }
    
  
    static void check_set(int n , int[] arr , Map<Integer,TreeSet<String>> map , String[] names , int[][] grid ){
        
           int counter = 0 , flag = 0;
           TreeSet<String> taken = new TreeSet<>();
           for(int i=0 ; i<n ; i++){
               flag = 0;
               if(arr[i] == 1){
               for(int j=i+1 ; j<n ; j++){
                    if(arr[j]== 1 && grid[i][j] == 1){
                        flag = 1;
                        break;
                    }
                    
               }
               
               if(flag == 1){
                    return;
               }
               
               counter ++;
               taken.add(names[i]);
           }
           }
           
         if(counter > 0)  map.put(counter, taken);
        
    }
  
}