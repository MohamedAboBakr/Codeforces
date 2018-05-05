import java.util.*;
import java.lang.*;
import java.io.*;

public class Math
{
	
	
	 public static int gcd (int a , int b){
		  if(b == 0) return a ;
		  return gcd(b,a%b);
	 }  
	 
	
	 
	public static void main (String[] args) 
	{
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int gcD= gcd(n, m);
		int[] boyes = new int[n] ;
		int[] girls = new int[m] ;
		int a = in.nextInt();
		for(int i=0 ; i<a ; i++){
			int index = in.nextInt();
			boyes[index] = 1 ;
		}
		
		a = in.nextInt();
		for(int i=0 ; i<a ; i++){
			int index = in.nextInt();
			girls[index] = 1 ;
		}
		
		

	   for(int i=0 ; i<gcD ; i++){
		   int flag = 0 ;
		    for(int j=i ; j<n ; j+=gcD){
		    	 if(boyes[j] == 1) {
		    		 flag = 1 ;
		    		 break;
		    	 }
		    }
		    if(flag == 0){
		    	int flag2 = 0;
		    	for(int j=i ; j<m ; j+=gcD){
		    		if(girls[j] == 1){
		    			flag2 = 1 ;
		    			break;
		    		}
		    	}
		    	if(flag2 == 0){
		    		System.out.println("NO");
		    		return  ;
		    	}
		    }
	   }
	   
		System.out.println("YES");

	}  
	
	
}