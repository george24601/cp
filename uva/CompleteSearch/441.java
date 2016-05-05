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
import java.util.List;

/* UVA 441 Lotto 
 * complete search
 */

class Main {

	long[] nums;
	int k;
	final int Size = 6;

	void Process(int index, int cacheIndex, long cache[]) {
		if (index == k && cacheIndex < Size)
			return;

		if (cacheIndex == Size) {
			System.out.print(cache[0]);

			for (int i = 1; i < Size; i++) {
				System.out.print(' ');
				System.out.print(cache[i]);
			}

			System.out.println();
			return;
		}

		long[] progCopy = Arrays.copyOf(cache, Size);
		progCopy[cacheIndex] = nums[index];
		Process(index + 1, cacheIndex + 1, progCopy);

		Process(index + 1, cacheIndex, cache);
	}

	void Run() {
		InputStream inStream = System.in;

		try {
	//		inStream = new FileInputStream(
	//				"C:\\Users\\user\\PersonalCode\\Algorithms\\UVA\\441\\Test.txt");
			Reader r = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer s = new StreamTokenizer(r);

			boolean isFirst = true;
			while (s.nextToken() != s.TT_EOF) {
				k = (int) s.nval;

				if (k == 0)
					break;

				if (isFirst)
					isFirst = false;
				else
					System.out.println();

				nums = new long[k];

				for (int i = 0; i < k; i++) {
					s.nextToken();
					nums[i] = (long) s.nval;
				}

				Arrays.sort(nums);

				long[] cache = new long[Size];
				Process(0, 0, cache);
			}

		} catch (IOException e) {

		}
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
