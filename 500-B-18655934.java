import java.util.*;
import java.lang.*;
import java.io.*;

public class Math
{
	
	  private static int[] _parent;
	  private static int[] _rank;

      private static int con_comb ;
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
	      _parent[root2] = root1;
	    } else if (_rank[root2] > _rank[root1]) {
	      _parent[root1] = root2;
	    } else {
	      _parent[root2] = root1;
	      _rank[root1]++;
	    }
	    
	    con_comb--;
	  }


	  public  static void UnionFind(int max) {

	    _parent = new int[max];
	    _rank = new int[max];
	    con_comb = max ;
	    for (int i = 0; i < max; i++) {
	      _parent[i] = i;
	    }
	  }


	 
	public static void main (String[] args) 
	{
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] arr = new int[n] ;
		UnionFind(n);
		for(int i=0 ; i<n ; i++){
			arr[i] = in.nextInt();
		}
		
		in.nextLine();
		int[] flag  = new int[n] ;
		int[] per = new int[n] ;
		
		for(int i=0 ; i<n ; i++){
			String s = in.nextLine();
			for(int j=0 ; j<n ; j++){
				char sw = s.charAt(j);
				if(sw == '1' && i<j) {
					union(i,j);
				}
			}
		}
		
        for(int  i = 0  ; i<n ; i++){
        	find(i);
        }
		List<Integer> index = new ArrayList<>();
		List<Integer> elem = new ArrayList<>();
		for(int i = 0 ; i<n ; i++){
			if(flag[i] == 1) continue ;
			if(_parent[i] == i){
				flag[i] = 1 ;
				index.add(i);
				elem.add(arr[i]);
				for(int j = 0 ; j<n ; j++){
					 if(flag[j] == 0 && _parent[j] == i){
						 flag[j] = 1 ;
						 index.add(j);
						 elem.add(arr[j]);
					 }
				}
				
				Collections.sort(index);
				Collections.sort(elem);
				for(int t=0 ; t<index.size() ; t++){
					  per[index.get(t)] = elem.get(t);
				}
				
				index.clear();
				elem.clear();
			}
		}
		
		System.out.printf("%d",per[0]);
		for(int i=1 ; i<n ; i++){
			System.out.printf(" %d",per[i]);

		}
		System.out.printf("\n");

	}  
	
	
	
}