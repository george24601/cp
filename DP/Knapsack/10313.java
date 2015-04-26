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
import java.util.StringTokenizer;
import java.util.Vector;

/* UVA 10313 Pay the Price
 * Knapsack
 */

class Main {

	int Max = 300;
	int p;
	int min;
	int max;

	long[][] last;

	void Precompute() {
		last = new long[Max + 1][Max + 1];

		last[0][0] = 1;

		for (int types = 1; types <= Max; types++) {
			long[][] next = new long[Max + 1][Max + 1];

			for (int value = 0; value <= Max; value++) {
				for (int numCoins = 0; numCoins <= Max; numCoins++) {
					next[value][numCoins] = last[value][numCoins];

					if (types > value || numCoins < 1)
						continue;

					next[value][numCoins] += next[value - types][numCoins - 1];
				}
			}

			last = next;
		}

	}

	void Process() {
		long total = 0;

		int maxNumC = max;

		if (max > Max)
			maxNumC = Max;

		for (int i = min; i <= maxNumC; i++)
			total += last[p][i];

		System.out.println(total);
	}

	void Run() {
		InputStream inStream = System.in;

		try {
		//	inStream = new FileInputStream("C:\\Test\\Test.txt");
			BufferedReader reader = new BufferedReader(new InputStreamReader(
					inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			Precompute();
			while (true) {
				String line = reader.readLine();
				if (line == null)
					break;

				StringTokenizer strtok = new StringTokenizer(line, " ");

				int tokenCounts = strtok.countTokens();

				if (tokenCounts == 1) {
					p = Integer.parseInt(strtok.nextToken());
					min = 0;
					max = Max;

				} else if (tokenCounts == 2) {
					p = Integer.parseInt(strtok.nextToken());
					max = Integer.parseInt(strtok.nextToken());
					min = 0;
				} else {
					p = Integer.parseInt(strtok.nextToken());
					min = Integer.parseInt(strtok.nextToken());
					max = Integer.parseInt(strtok.nextToken());
				}

				Process();
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
