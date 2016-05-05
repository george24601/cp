import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.math.BigDecimal;
import java.math.BigInteger;
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

/* UVA 10688 The Poor Giant
 * DP
 */

class Main {
	BigInteger[][][] total;
	int MaxSize = 100;

	BigInteger One = new BigInteger("1");
	BigInteger Zero = new BigInteger("0");

	void Process() {

		for (int numN = 0; numN <= MaxSize; numN++) {
			for (int maxLen = 0; maxLen <= MaxSize; maxLen++) {
				total[numN][maxLen][0] = Zero;
				total[numN][maxLen][1] = Zero;
			}

			if (numN > 0) {
				total[numN][numN][1] = One;
				total[numN][0][0] = One;
			}
		}

		for (int numN = 1; numN <= MaxSize; numN++) {

			for (int maxLength = 1; maxLength <= numN; maxLength++) {

				for (int tailLength = 1; tailLength <= numN; tailLength++) {
					total[numN][maxLength][0] = total[numN][maxLength][0]
							.add(total[numN - tailLength][maxLength][1]);

				}

				for (int tailLength = 1; tailLength <= maxLength; tailLength++) {

					total[numN][maxLength][1] = total[numN][maxLength][1]
							.add(total[numN - tailLength][maxLength][0]);
				}

				for (int lastMaxLength = 0; lastMaxLength < maxLength; lastMaxLength++) {

					total[numN][maxLength][1] = total[numN][maxLength][1]
							.add(total[numN - maxLength][lastMaxLength][0]);

				}

			}

		}

	}

	void Run() {
		InputStream inStream = System.in;

		/*
		try {
			inStream = new FileInputStream("C:\\Test\\Test.txt");
		} catch (IOException e) {

		}
		*/

		/*
		 * BufferedReader reader = new BufferedReader(new InputStreamReader(
		 * 
		 * inStream));
		 * 
		 * StreamTokenizer st = new StreamTokenizer(reader);
		 */

		total = new BigInteger[MaxSize + 1][MaxSize + 1][2];
		Scanner in = new Scanner(inStream);
		Process();
		while (in.hasNext()) {
			int n = in.nextInt();
			int k = in.nextInt();

			BigInteger result = Zero;
			for (int maxLength = k; maxLength <= n; maxLength++) {

				result = result.add(total[n][maxLength][0]);
				result = result.add(total[n][maxLength][1]);
			}

			System.out.println(result);

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
