import java.util.*;
import java.lang.*;
import java.io.*;

public class Math
{

    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), x, y;
		int[] arr = new int[1000010], res = new int[n + 1];

		Set<Integer> fst = new HashSet<>(200005), snd = new HashSet<>(200005);
		
		for (int i = 0; i < n; i++) {
			x = in.nextInt();
			y = in.nextInt();
			arr[x] = y;
			fst.add(x);
			snd.add(y);
		}

		fst.removeAll(snd);
		String index = fst.toString();

		int t= 0, j = 2;
		while (arr[t] != 0) {
			t = arr[t];
			res[j] = t;
			j += 2;
		}

		t = Integer.parseInt(index.substring(1, index.length() - 1));
		j = 1;
		while (t != 0) {
			res[j] = t;
			j += 2;
			t = arr[t];
		}

		for (int i = 1; i < n + 1; i++) {
			System.out.print(res[i] + " ");
		}

	}

	
	
}