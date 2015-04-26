import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

/* UVA 927 Integer Sequences from Addition of Terms
 * complete search
 */

class Main {

	long calcTotalItem(long d, long n) {
		return (d + n * d) * n / 2;

	}

	long MaxN(long d, long k) {
		long current = 1;

		while (current < Long.MAX_VALUE / 2) {
			if (calcTotalItem(d, current) >= k)
				return current;
			else
				current = current * 2;
		}

		return Long.MAX_VALUE / 2;
	}

	long findN_r(long d, long k, long start, long end) {
		if (start == end)
			return start;
		long mid = (start + end) / 2;

		if (k <= calcTotalItem(d, mid) && calcTotalItem(d, mid - 1) < k)
			return mid;
		else if (k > calcTotalItem(d, mid))
			return findN_r(d, k, mid + 1, end);
		else if (k <= calcTotalItem(d, mid - 1))
			return findN_r(d, k, start, mid - 1);
		else
			return -1;
	}

	long GetN(long d, long k) {
		long maxN = MaxN(d, k);
		return findN_r(d, k, 0, maxN);
	}

	void Calc(long[] coeffs, int maxOrder, long n) {
		long result = 0;
		long curOrder = 1;
		for (int i = 0; i <= maxOrder; i++) {
			result += curOrder * coeffs[i];
			curOrder *= n;
		}

		System.out.println(result);
	}

	void Run() {
		InputStream inStream = System.in;

		try {
			 //inStream = new FileInputStream(
			//"C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			st.nextToken();
			int C = (int) st.nval;

			for (int i = 0; i < C; i++) {
				st.nextToken();
				int maxOrder = (int) st.nval;

				long[] coeffs = new long[maxOrder + 1];

				for (int j = 0; j <= maxOrder; j++) {
					st.nextToken();
					coeffs[j] = (long) st.nval;
				}

				st.nextToken();
				long d = (long) st.nval;
				st.nextToken();
				long k = (long) st.nval;

				long n = GetN(d, k);

				Calc(coeffs, maxOrder, n);
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
