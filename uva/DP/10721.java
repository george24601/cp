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

/* UVA 10688 The Poor Giant
 * DP
 */

class Main {
	long[][] total;
	int mn, mm, mk;

	void PreProcess() {
		total = new long[mn + 1][mk + 1];

		for (int n = 1; n<=mm && n <= mn; n++) {
			total[n][1] = 1;
		}

		for (int k = 2; k <= mk; k++) {
			for (int n = k; n <= mn; n++) {

				for (int lastBarSize = 1; lastBarSize <= mm && lastBarSize <= n; lastBarSize++) {
					total[n][k] += total[n - lastBarSize][k - 1];
				}
			}
		}

		System.out.println(total[mn][mk]);
	}

	void Run() {
		InputStream inStream = System.in;

		try {
	//		inStream = new FileInputStream("C:\\Test\\Test.txt");
			BufferedReader reader = new BufferedReader(new InputStreamReader(
					inStream));

			StreamTokenizer st = new StreamTokenizer(reader);

			while (st.nextToken() != st.TT_EOF) {
				mn = (int) st.nval;
				st.nextToken();
				mk = (int) st.nval;
				st.nextToken();
				mm = (int) st.nval;

				PreProcess();
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
