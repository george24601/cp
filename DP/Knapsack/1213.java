import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Dictionary;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Vector;

/* UVA 1213 Sum of Different Primes
 * Knapsack
 */

class Main {

	int n;
	int k;

	ArrayList<Integer> primes;

	void Sieve() {
		int maxSize = 1120;
		boolean[] nums = new boolean[maxSize];
		primes = new ArrayList<Integer>();

		for (int i = 2; i < maxSize; i++)
			nums[i] = true;

		for (int i = 2; i < maxSize; i++) {
			for (int j = 2; j * i < maxSize; j++)
				nums[j * i] = false;
		}

		for (int i = 2; i < maxSize; i++) {
			if (nums[i])
				primes.add(i);
		}
	}

	void Process() {
		if (k == 0) {
			System.out.println(0);
			return;
		}

		long[][] oldWays = new long[n + 1][k + 1];

		for (int m = 0; m < primes.size(); m++) {
			int curPrime = primes.get(m);

			if (curPrime > n)
				break;

			long[][] ways = new long[n + 1][k + 1];
			
			ways[curPrime][1] = 1;

			for (int ki = 1; ki <= k; ki++) {
				for (int ni = 1; ni <= n; ni++) {
					ways[ni][ki] += oldWays[ni][ki];

					if (curPrime <= ni)
						ways[ni][ki] += oldWays[ni - curPrime][ki - 1];
				}
			}

			oldWays = ways;
		}

		System.out.println(oldWays[n][k]);
	}

	void Run() {
		InputStream inStream = System.in;

		try {
			//inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			Sieve();
			while (true) {
				st.nextToken();
				n = (int) st.nval;
				st.nextToken();
				k = (int) st.nval;

				if (n == 0 && k == 0)
					break;

				Process();
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
