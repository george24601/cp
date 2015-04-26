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

/* UVA 10036 Divisibility
 */

class Main {
	int N;
	int K;
	int[] nums;

	void Process() {
		boolean[] last = new boolean[K];
		last[0] = true;
		for (int i = 0; i < N; i++) {
			boolean[] next = new boolean[K];
			int curNum = nums[i];
			int curMod = curNum % K;

			if (curMod < 0)
				curMod += K;

			for (int j = 0; j < K; j++) {
				int plusMod = j - curMod;

				if (plusMod < 0)
					plusMod += K;

				if (last[plusMod])
					next[j] = true;

				int minusMod = (j + curMod) % K;

				if (last[minusMod])
					next[j] = true;
			}

			last = next;
		}

		if (last[0])
			System.out.println("Divisible");
		else
			System.out.println("Not divisible");

	}

	void Run() {
		InputStream inStream = System.in;

		try {
			//inStream = new FileInputStream("C:\\Test\\Test.txt");
			BufferedReader reader = new BufferedReader(new InputStreamReader(
					inStream));

			StreamTokenizer st = new StreamTokenizer(reader);

			st.nextToken();
			int M = (int) st.nval;

			for (int i = 0; i < M; i++) {
				st.nextToken();
				N = (int) st.nval;
				st.nextToken();
				K = (int) st.nval;

				nums = new int[N];
				for (int j = 0; j < N; j++) {
					st.nextToken();
					nums[j] = (int) st.nval;
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
