import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/* UVA 725 division 
 * backtracking
 */
class Main {
	final int Size = 10;
	final int HalfSize = 5;
	int[] digits;
	List<Integer> results;
	int n;

	void Swap(int a, int b)
	{
		int temp = digits[a];
		digits[a] = digits[b];
		digits[b] = temp;
	}

	void P_r(int permIndex) {

		if (permIndex >= HalfSize)
		{
			if (digits[0] == 0)
				return; //for the bigger number, first digit cant be 0

			int num = 0;
			for(int i = 0; i < HalfSize; i++)
				num = num * 10 + digits[i];
			
			if (num % n != 0)
				return;
			
			//each digit appears only once
			int other = num/ n;
			int bitmasks = 0;
			for (int i = HalfSize; i < Size; i++)
				bitmasks = bitmasks | (1 << digits[i]);
			
			int reduceNum = num/ n;
			int bm2 = 0;
			for(int i = 0; i < HalfSize; i++)
			{
				int digit = reduceNum % 10;
				bm2 = bm2 | (1 << digit);
				reduceNum = reduceNum/10;
			}
			
			if (!(reduceNum == 0 && bitmasks == bm2))
				return;
			
			results.add(num);
			
		}else
		{
			for (int i = permIndex; i < Size; i++)
			{
				Swap (permIndex, i);
				P_r(permIndex + 1);
				Swap (permIndex, i);
			}
		}

	}

	void Run() {
		InputStream inStream = System.in;
		/*
		  try { inStream = new FileInputStream(
		  "D:\\PersonalCode\\Algorithms\\UVA\\725\\Test.txt"); } catch
		  (Exception e) { }
		  */

		try {
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer s = new StreamTokenizer(reader);
			digits = new int[Size];
			results = new ArrayList<Integer>();

			for (int i = 0; i < Size; i++)
				digits[i] = i;

			boolean isFirst = true;

			while (s.nextToken() != s.TT_EOF) {
				n = (int) s.nval;
				if (n == 0)
					break;
				
				if (isFirst)
					isFirst = false;
				else
					System.out.println();

				P_r(0);


				if (results.size() == 0) {
					System.out.println(String.format(
							"There are no solutions for %d.", n));
				} else {

					Collections.sort(results);

					for (int i = 0; i < results.size(); i++) {
						int result = results.get(i);
						int other = result / n;
						String otherStr = ("00000" + Integer.toString(other));
						System.out.println(String.format("%d / %s = %d",
								result, otherStr.substring(
										otherStr.length() - 5,
										otherStr.length()), n));
					}
				}
				
				results.clear();
			}

		} catch (IOException e) {

		}
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
