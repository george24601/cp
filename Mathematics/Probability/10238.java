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
	BigInteger[][] total;
	int F, N, S;

	void Process() {

		total[0][0] = new BigInteger("1");

		for (int tossN = 1; tossN <= N; tossN++) {
			for (int sum = 1; sum <= tossN * F; sum++) {
				total[tossN][sum] = new BigInteger("0");

				for (int tV = 1; tV <= F && tV <= sum; tV++) {

					if (total[tossN - 1][sum - tV] != null) {
						total[tossN][sum] = total[tossN][sum]
								.add(total[tossN - 1][sum - tV]);
					}
				}
			}
		}
	}

	void Run() {
		InputStream inStream = System.in;

	//	try {
		//	inStream = new FileInputStream("C:\\Test\\Test.txt");
			/*
			 * BufferedReader reader = new BufferedReader(new InputStreamReader(
			 * 
			 * inStream));
			 * 
			 * StreamTokenizer st = new StreamTokenizer(reader);
			 */

			Scanner in = new Scanner(inStream);
			while (in.hasNext()) {
				F = in.nextInt();
				N = in.nextInt();
				S = in.nextInt();

				if (S > N * F) {
					System.out.print(0);
				} else {
					total = new BigInteger[N + 1][N * F + 1];
					Process();

					if (total[N][S] == null)
						System.out.print(0);
					else
						System.out.print(total[N][S]);
				}

				System.out.print("/");
				BigInteger bottom = new BigInteger(new Integer(F).toString());
				System.out.println(bottom.pow(N));
			}

			/*
		} catch (IOException e) {

		}
		*/

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
