import java.io.*;
import java.util.*;


public class NestedSegmaents {

	
	public static void main(String[] args) throws Exception {
		
		    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	        FastScanner in = new FastScanner(br);
            PrintWriter out= new PrintWriter(System.out);
	        solve(in , out);
	        out.close(); 

	}
	
	public static void solve(FastScanner in , PrintWriter out) throws Exception{
		  
		  int n = in.nextInt();
		  nde[] nodes = new nde[n] ;
		  int[] ends  = new int[n];
		  int[] ans = new int[n] ;
		  
		  FenwickTree tree = new FenwickTree(n);
		  
		  for(int i=0 ; i<n ; i++){
			  nodes[i] = new nde(in.nextInt() , in.nextInt() , i);
			  ends[i] = nodes[i].r ;
		  }
		  Arrays.sort(ends);
		  int j=0 ;
		  for(int i=0 ; i<n ; i++){
			  nodes[i].r = Arrays.binarySearch(ends, nodes[i].r) ;
		  }
		  
		  Arrays.sort(nodes);
		  for(int i=n-1 ; i>=0 ; i--){
			  ans[nodes[i].index] = tree.SUM(nodes[i].r) ;
			  tree.updateTree(nodes[i].r);
		  }
		  
		  for(int i=0 ; i<n ; i++){
			  System.out.println(ans[i]);
		  }
	}
	
}



class nde implements Comparable<nde>{
	int l,r,index ;
	public nde(int l , int r , int i){
		 this.l = l ;
		 this.r = r ;
		 index = i ;
	}
	
	public int compareTo(nde n)
	{
		return Integer.compare(this.l,n.l);
	}
	
}


class FenwickTree {
    
	// int Base_array[] ;
	int fen_tree[] ;
	int len ;
	
	public FenwickTree(){}
	
	public FenwickTree(int n){
		// Base_array = arr ;
		len = n+1;
		fen_tree = new int[len] ;
	 //	create_tree();
	}
	

	public void updateTree(int index){
		//  int delta = new_val - Base_array[index] ;
		  index +=  1 ;
		  while(index < len){
				 fen_tree[index] += 1 ;
				 index = getNext(index);
		 }
	}
	
	public int SUM(int index){
		index += 1 ;   
        int sum = 0;		
		while(index > 0){
			sum += fen_tree[index] ;
			index = getParent(index);
		}
		return sum ;
	}
	
	public int getSum(int i1 , int i2){
		 int sum = SUM(i2);
		 if(i1 > 0) sum -= SUM(i1-1);
		 return sum ;
	}
	
	private int getParent(int index){
		 return index - (index & -index);
	}
	private int getNext(int index){
		return index + (index & -index) ;
	}
	
}


class FastScanner
{
    BufferedReader in;
    StringTokenizer st;

    public FastScanner(BufferedReader in) {
        this.in = in;
    }
	
    public String nextToken() throws Exception {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(in.readLine());
        }
        return st.nextToken();
    }
	
	public String next() throws Exception {
		return nextToken().toString();
	}
	
    public int nextInt() throws Exception {
        return Integer.parseInt(nextToken());
    }

    public long nextLong() throws Exception {
        return Long.parseLong(nextToken());
    }

    public double nextDouble() throws Exception {
        return Double.parseDouble(nextToken());
    }
}