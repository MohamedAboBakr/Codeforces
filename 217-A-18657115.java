import java.util.*;
import java.lang.*;
import java.io.*;

public class Math
{
	
	  
	public static void dfs2(int[][] arr  , int c , int[][] flag , int n , int col , int val){
		
		for(int i = 0 ; i<n  ; i++){
			
			if(arr[i][col] == val && flag[i][col] == 0){
				flag[i][col] = c ;
				dfs2(arr, c , flag , n , (col+1)%2 , arr[i][(col+1)%2] );
			}
		}
	}
	
    public static int dfs1(int[][] arr , int c , int[][] flag , int n ){
       int comb = c;
    	for(int i=0  ; i<n ; i++){
    		if(flag[i][0] == 0){
    			dfs2(arr  , c , flag , n , 0 , arr[i][0]);
    			comb++;
    		}
    	}
    	return comb ;
    }
	public static void main (String[] args) 
	{
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[][] arr = new int[n][2] ;
		int[][] flag = new int[n][2] ;
		for(int i=0 ; i<n ; i++){
			arr[i][0] = in.nextInt();
			arr[i][1] = in.nextInt();
		}
	int min = dfs1(arr , 1 , flag , n);
	System.out.println(min-2);
	}  
	
	
	
}