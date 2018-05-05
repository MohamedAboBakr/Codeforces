import java.util.*;
import java.lang.*;
import java.io.*;

public class Math
{
	
	  private static int[] _parent;
	  private static int[] _rank;

      private static int[] con_comb ;
	  public static  int find(int i) {

	    int p = _parent[i];
	    if (i == p) {
	      return i;
	    }
	    return _parent[i] = find(p);

	  }


	  public static void union(int i, int j) {

	    int root1 = find(i);
	    int root2 = find(j);

	    if (root2 == root1) return;

	    if (_rank[root1] > _rank[root2]) {
	    	con_comb[root1] += con_comb[_parent[root2]];
	      _parent[root2] = root1;
	      
	    } else if (_rank[root2] > _rank[root1]) {
	    	con_comb[root2] += con_comb[_parent[root1]];
	      _parent[root1] = root2;
	    } else {
	    	con_comb[root1] += con_comb[_parent[root2]];
	      _parent[root2] = root1;  
	      _rank[root1]++;
	    }
	    
	    
	  }


	  public  static void UnionFind(int max) {

	    _parent = new int[max];
	    _rank = new int[max];
	    con_comb = new int[max];
	    for (int i = 0; i < max; i++) {
	      _parent[i] = i;
	      con_comb[i] = 1 ;
	    }
	  }

	

	public static void main (String[] args) 
	{
	
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		UnionFind(n+1);
		long[] pow_2 = new long[50];
		pow_2[0] = 1L;
		for(int i=1 ; i<50 ; i++){
			pow_2[i] = 2*pow_2[i-1];
		}
		
		int x , y ;
		for(int i=0 ; i<m ; i++){
			x = in.nextInt();
			y = in.nextInt();
			union(x,y);
		}
		
		long ans = 1L ;
		
		for(int i=1 ; i<= n ; i++){
			if(_parent[i] == i){
				
				 ans *= pow_2[(con_comb[i])-1];
			}
		}
		System.out.println(ans);
	}  
	
	

	
}