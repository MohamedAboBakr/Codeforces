import java.awt.geom.Point2D.Double ;
import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class CF {
	
	 static int n , m ;
	 static int mx_depth = 18 ;
	 static long mst_val = 0 ;
	 static Edge[] edges ;
	 static ArrayList<int[]>[] adj_list ;
	 static int[] dep , head  ;
	 static long[] ans ;
	 static int[][] anc , max_edge ;
	 
     public static void main(String[] args) {
       
         InputStream instream = System.in;
         OutputStream outstream = System.out;
         Scanner in = new Scanner(instream);
         PrintWriter out = new PrintWriter(outstream);
	     solve(in , out);
	     out.close(); 
      }
     
     
     public static int find(int node){
    	  if(node == head[node]) return node ;
    	  return head[node] = find(head[node]);
     }
     public static  long krus(){
    	 long res = 0 ;
    	 for(int i=1 ; i<=n ;i++){
    		 head[i] = i ;
    	 }
    	 
    	 for(int i=0 ; i<m ; i++){
    		 int u , v , w ;
    		 u = edges[i].u ;  v = edges[i].v ;  w = edges[i].w ;
    		 int h1 = find(u) , h2 = find(v);
    		 if(h1 != h2){
    			 head[h1] = h2 ;
    			 adj_list[u].add(new int[]{ v , w });
    			 adj_list[v].add(new int[]{ u , w });
    			 res += w ;
    		 }
    	 }
    	 return res;
     }
     
     
     public static void dfs(int curr , int an , int d){
    	 
    	 dep[curr] = d ;
    	 anc[curr][0] = an ;
    	 
    	 for(int arr[] : adj_list[curr]){
    		 if(arr[0] == an){
    			 max_edge[curr][0] = arr[1] ;
    			 continue;
    		 }
    		 dfs(arr[0] , curr , d+1);
    	 }
     }
     
     
     public static int lca(int u ,  int v){
    	 int res = 0 ;
    	 while(dep[u] != dep[v]){
    		 if(dep[u] < dep[v]){
    			 int tmp = u ;
    			 u = v ;
    			 v = tmp ;
    		 }
    		 
    		 int d = dep[u] - dep[v] ;
    		 for(int i=0 ; i<= mx_depth ; i++){
    			 if((d >> i) %2 == 1){
    				 res = Math.max(res , max_edge[u][i]);
    				 u = anc[u][i] ;
    			 }
    		 }
    		 
    	 }
    	 
    	 if(u == v) return res ;
    	 for(int i = mx_depth ; i>=0 ; i--){
    		  if(anc[u][i] != anc[v][i]){
    			  res = Math.max(res , Math.max(max_edge[u][i] , max_edge[v][i]));
    			  u = anc[u][i] ;
    			  v = anc[v][i] ;
    		  }
    	 }
    	 return  Math.max(res , Math.max(max_edge[u][0] , max_edge[v][0]));
     }
     
     
     public static void solve(Scanner in , PrintWriter out){
    	 n = in.nextInt(); m = in.nextInt();
    	 dep = new int[n+1] ;
    	 head = new int[n+1] ;
    	 anc = new int[n+1][mx_depth+1];
    	 max_edge = new int[n+1][mx_depth+1];
    	 ans = new long[m];
    	 edges = new Edge[m] ;
    	 
    	 for(int i=0 ; i<m ; i++){
    		 edges[i] = new Edge(i , in.nextInt() , in.nextInt() , in.nextInt());
    	 }
    	 Arrays.sort(edges);
    	 
    	 adj_list = new ArrayList[n+1];
    	 
    	 for(int i=1 ; i<=n ; i++){
    		 adj_list[i] = new ArrayList<int[]>();
    	 }
    	 
    	 mst_val = krus();
    	 dfs(1,1,0);
    	 
    	 for(int i=1 ; i<= mx_depth ; i++){
    		 
    		 for(int j=1 ; j<=n ;  j++){
    			  anc[j][i] = anc[anc[j][i-1]][i-1] ;
    			  max_edge[j][i] = Math.max(max_edge[j][i-1] , max_edge[anc[j][i-1]][i-1]); 
    		 }
    	 }
    	 
    	 for(int i=0 ; i<m ; i++){
    		 ans[edges[i].index] = mst_val - lca(edges[i].u , edges[i].v) + edges[i].w;
    	 }
    	 
    	 for(int i=0 ; i<m ; i++){
    		 out.println(ans[i]);
    	 }
     }
}




class Edge implements Comparable<Edge>
{
    int index , u , v , w;
    public Edge(int i , int u , int v , int w){
    	index = i ;
    	this.u = u ;
    	this.v = v ;
    	this.w = w ;
    }
    
	@Override
	public int compareTo(Edge e) {
		return w - e.w;
	}
	
}