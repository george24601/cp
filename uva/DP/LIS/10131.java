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

/* UVA 10130  Is Bigger Smarter?
 * LIS
 */

class Main {

	class El {
		public int LineNum;
		public int Kg;
		public int IQ;

		public El(int lineNum, int kg, int iq) {
			LineNum = lineNum;
			Kg = kg;
			IQ = iq;
		}
	}

	class ElComparator implements Comparator<El> {
		public int compare(El first, El second) {
			if (first.Kg > second.Kg)
				return 1;
			else if (first.Kg < second.Kg)
				return -1;

			if (first.IQ > second.IQ)
				return -1;
			else if (first.IQ < second.IQ)
				return 1;

			return 0;
		}
	}

	List<El> els;
	int size;

	void Print_r(int curMaxEnd, int[] prev, int count) {
		if (prev[curMaxEnd] == -1) {
			System.out.println(count + 1);
			System.out.println(els.get(curMaxEnd).LineNum);
			return;
		}

		Print_r(prev[curMaxEnd], prev, count + 1);

		System.out.println(els.get(curMaxEnd).LineNum);
	}

	void Process() {
		int[] LIS = new int[size];
		int[] prev = new int[size];

		LIS[0] = 1;
		prev[0] = -1;

		for (int i = 1; i < size; i++) {
			int curMaxLIS = 1;
			int curPrev = -1;

			El atI = els.get(i);

			for (int j = 0; j < i; j++) {
				El atJ = els.get(j);

				if (atI.IQ >= atJ.IQ || atI.Kg <= atJ.Kg)
					continue;

				int potentialLIS = LIS[j] + 1;

				if (potentialLIS > curMaxLIS) {
					curMaxLIS = potentialLIS;
					curPrev = j;
				}
			}

			LIS[i] = curMaxLIS;
			prev[i] = curPrev;
		}

		int curMax = -1;
		int curMaxEnd = 0;

		for (int i = 0; i < size; i++) {
			if (LIS[i] > curMax) {
				curMax = LIS[i];
				curMaxEnd = i;
			}
		}

		Print_r(curMaxEnd, prev, 0);

	}

	void Run() {
		InputStream inStream = System.in;

		try {
		//	inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			els = new ArrayList<El>();
			int count = 0;
			while (st.nextToken() != st.TT_EOF) {
				count++;

				int kg = (int) st.nval;

				st.nextToken();
				int IQ = (int) st.nval;

				els.add(new El(count, kg, IQ));
			}

			size = count;

			Collections.sort(els, new ElComparator());
			Process();

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
