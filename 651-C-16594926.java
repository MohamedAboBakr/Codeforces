import java.util.*;


public class CodeForces
{

    public static void main(String[] args)
	{
            
            Scanner in = new Scanner(System.in);
            int  n ;
            n = in.nextInt();
            Map<Integer , List<Integer>> map1 = new HashMap<>();
            Map<Integer , List<Integer>> repeats = new HashMap<>();
            Map<Integer , List<Integer>> map2 = new HashMap<>();
            int x , y ;
            for(int i=0 ; i<n ; i++){
                x = in.nextInt();
                y = in.nextInt();
                
                if(map1.containsKey(x)) {
                    map1.get(x).add(y);
                }else{
                    List<Integer> list = new ArrayList<>();
                    map1.put(x, list);
                    map1.get(x).add(y);
                }
                
                if(map2.containsKey(y)){
                    map2.get(y).add(x);
                }else{
                    List<Integer> list = new ArrayList<>();
                    map2.put(y, list);
                    map2.get(y).add(x);
                }
            }
            
            
            long sum = 0 ;
            
            for(Integer k : map1.keySet()){
               Integer[] elements = new Integer[map1.get(k).size()];
               map1.get(k).toArray(elements) ;
               long len = elements.length ;
               sum += len*(len-1)/2;
               mergeSort((Integer[]) elements);
            long count = 0 ;
            for(int i=1 ; i<len ; i++){
                if(elements[i].intValue() == elements[i-1].intValue()) count ++ ;
                else{
                   count += 1 ;
                   
                   sum -= count*(count-1)/2 ;
                    count = 0;
                }
            }
           
            if(count != 0)
            {
                 sum -= count*(count+1) /2 ;
            }
            }
            
            
            for(Integer k : map2.keySet()){
                long len = map2.get(k).size();
                sum += len*(len-1)/2 ;
            }
            
            System.out.println(sum);

           
        }
    
  
    
    public static void mergeSort(Comparable [ ] a)
	{
		Comparable[] tmp = new Comparable[a.length];
		mergeSort(a, tmp,  0,  a.length - 1);
	}


	private static void mergeSort(Comparable [ ] a, Comparable [ ] tmp, int left, int right)
	{
		if( left < right )
		{
			int center = (left + right) / 2;
			mergeSort(a, tmp, left, center);
			mergeSort(a, tmp, center + 1, right);
			merge(a, tmp, left, center + 1, right);
		}
	}


    private static void merge(Comparable[ ] a, Comparable[ ] tmp, int left, int right, int rightEnd )
    {
        int leftEnd = right - 1;
        int k = left;
        int num = rightEnd - left + 1;

        while(left <= leftEnd && right <= rightEnd)
            if(a[left].compareTo(a[right]) <= 0)
                tmp[k++] = a[left++];
            else
                tmp[k++] = a[right++];

        while(left <= leftEnd)    // Copy rest of first half
            tmp[k++] = a[left++];

        while(right <= rightEnd)  // Copy rest of right half
            tmp[k++] = a[right++];

        // Copy tmp back
        for(int i = 0; i < num; i++, rightEnd--)
            a[rightEnd] = tmp[rightEnd];
    }
}