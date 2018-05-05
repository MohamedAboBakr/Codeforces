import java.lang.* ;
import java.util.* ;


public class Main{
    
    static int[] flag ;
    
    static int search(int x , int y){
    
        if(x > y) return -1 ;
        if(flag[x] == 0) return x ;
        if(x == y) return -1 ;
        int ans = -1; 
        int mid = x + (y-x)/2 ;
        if(flag[mid] == 0) ans = mid ;
        int ans1 = search(x , mid) ;
        if(ans1 != -1) return ans1  ;
        if(ans1 == -1 && ans != -1) return ans ;
        return search(mid+1 , y) ;
        
    }
    public static void main (String[] args){
         Scanner in = new Scanner(System.in);
         int n = in.nextInt();  int m = in.nextInt();
        
         TreeSet <Integer>treeadd = new TreeSet<Integer>();
         flag = new int[n+1];
         for(int i=0 ; i<= n ; i++){
 
             treeadd.add(i);
         }
         
                  int x , y , w;
         for(int i=0 ; i<m ; i++){
             x = in.nextInt();  y = in.nextInt();  w = in.nextInt();
             int index  = treeadd.ceiling(x);
             Iterator iterator = treeadd. tailSet(index).iterator();
             List<Integer> lst = new ArrayList<>();
             
             while( iterator.hasNext() ){
                 int k =(int) iterator.next();
                 if(k <= y ){
                     if(k != w){
                         flag[k] = w ;
                         lst.add(k);
                     }
                 }
                 else break;
             }
             
             for(int k:lst){
                 treeadd.remove(k);
             }
             
             lst.clear();

         }
         
                      
             
             for(int i=1 ; i<= n ; i++){
                 System.out.print(flag[i] + " ");
             }
    }
    
    
}