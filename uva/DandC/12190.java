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
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Vector;

/* UVA 12190 Electricity Bills

 * binary search
 */

class Main {

	long mn;
	long B;
	
	long ReverseCalc(long min, long max, long cost)
	{
		long mid = (min + max)/2;
		
		if (Calc(mid) == cost)
			return mid;
		else if (Calc(mid) > cost)
			return ReverseCalc(min, mid - 1, cost);
		else
			return ReverseCalc(mid + 1, max, cost);
	}
	
	long Calc(long usage)
	{
		long total = 0;

		if (usage <= 100)
			return (usage) * 2;
		
		total += 100 * 2;
		
		if (usage <= 10000)
		{
			total += (usage - 100) * 3;
			return total;
		}
		
		total += (10000 - 100) * 3;

		if (usage <= 1000000)
		{
			total += (usage - 10000) * 5;
			return total;
		}
		
		total += (1000000 - 10000) * 5;
		
		total += (usage - 1000000) * 7;
		
		return total;

		
	}

	void Process_r(long min, long max)
	{
		long mid = (min + max) / 2;
		
		long n = mn - mid;
		
		long nBill = Calc(n);
		long mBill = Calc(mid);
		
		long diff = nBill - mBill;
		
		if (diff == B)
			System.out.println(Calc(mid));
		else if (diff > B)
			Process_r(mid + 1, max);
		else
			Process_r(min, mid - 1);
	}

	void Run() {
		InputStream inStream = System.in;

		try {
			//inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			while (true) {
				st.nextToken();
				long A = (long) st.nval;

				st.nextToken();
				B = (long) st.nval;

				if (A == 0 && B == 0)
					break;
				
				mn = ReverseCalc(1, 1000000000, A);
				Process_r(1, mn/2);
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
