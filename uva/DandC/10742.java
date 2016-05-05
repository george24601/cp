import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Dictionary;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

/* UVA 10742 New Rule in Euphomia

 * binary search
 */

class Main {

	ArrayList<Integer> primes;
	int n;
	
	void CalcPrimes()
	{
		int max = 1000000;
		boolean[] candidate = new boolean[max];
		
		for (int i = 0; i < max; i++)
			candidate[i] = true;
		
		int start = 2;
		while (start <max)
		{
			for (int i = 2; (i * start) <= max; i++)
				candidate[(i * start) - 1 ] = false;
			
			start++;
			for (; start <= max && !candidate[start -1];start++)
			{
			}
		}
		
		primes = new ArrayList<Integer>();
		for (int i = 2; i <max; i++)
		{
			if (candidate[i - 1])
				primes.add(i);
		}
	}

	int Process()
	{
		int find = Collections.binarySearch(primes, n);
		
		int endSearch = 0;
		if (find > 0)
			endSearch = find;
		else
			endSearch = -1 - find -1;
		
		if (endSearch == 0)
			return 0;
		
		int total = 0;
		for (int i = 0; i <= endSearch; i++)
		{
			if (primes.get(i) >= (n + 1)/2)
				break;
			
			int remaining = n - primes.get(i);
			
			
			int otherIndex = Collections.binarySearch(primes, remaining);
			
			if (otherIndex >= 0)
			{
				total += (otherIndex - i);
			}
			else
			{
				int insertionPoint = -1 - otherIndex;
				total += (insertionPoint - 1 - i);
			}
			
		}
		
		return total;
	}
	
	void Run() {
		InputStream inStream = System.in;

		try {
			//inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			CalcPrimes();
			
			int caseCount = 0;
			while(st.nextToken() != st.TT_EOF)
			{
				n = (int)st.nval;
				
				if ( n <= 0)
					break;
				
				caseCount++;
						
				int result = Process();
				
				System.out.println(String.format("Case %d: %d", caseCount, result));
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
