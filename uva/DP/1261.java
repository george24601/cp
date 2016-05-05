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

/* UVA 1261 String poppling
 * DP
 */

class Main {

	String s;
	int size;
	boolean[][][] canGet;

	boolean IsStartCut(int index) {
		if (index == 0)
			return true;
		else
			return s.charAt(index) != s.charAt(index - 1);
	}

	boolean IsEndCut(int index) {
		if (index == size - 1)
			return true;
		else
			return s.charAt(index) != s.charAt(index + 1);
	}

	void Init() {
		int i = 0;
		int curStart = 0;
		while (i < size) {
			int curChar = s.charAt(i);

			if (IsEndCut(i)) {
				if (i - curStart > 0)
					canGet[curStart][i][0] = true;

				if (curChar == 'a')
					canGet[curStart][i][1] = true;
				else if (curChar == 'b')
					canGet[curStart][i][2] = true;

				curStart = i + 1;
			}

			i++;
		}
	}

	void Process() {
		size = s.length();
		canGet = new boolean[size][size][3];

		Init();
		for (int length = 1; length <= size; length++) {
			for (int start = 0; start + length <= size; start++) {
				if (!IsStartCut(start))
					continue;

				int endIndex = start + length - 1;
				if (!IsEndCut(endIndex))
					continue;

				for (int mid = start + 1; mid <= endIndex; mid++) {
					if (!(IsStartCut(mid) && IsEndCut(mid - 1)))
						continue;

					boolean[] firstHalf = canGet[start][mid - 1];
					boolean[] secondHalf = canGet[mid][endIndex];

					if ((firstHalf[0] && secondHalf[0])
							|| (firstHalf[1] && secondHalf[1])
							|| (firstHalf[2] && secondHalf[2]))
						canGet[start][endIndex][0] = true;

					if ((firstHalf[0] && secondHalf[1])
							|| (firstHalf[1] && secondHalf[0])
							|| (firstHalf[1] && secondHalf[1]))
						canGet[start][endIndex][1] = true;

					if ((firstHalf[0] && secondHalf[2])
							|| (firstHalf[2] && secondHalf[0])
							|| (firstHalf[2] && secondHalf[2]))
						canGet[start][endIndex][2] = true;

				}
			}
		}

		if (canGet[0][size - 1][0])
			System.out.println(1);
		else
			System.out.println(0);
	}

	void Run() {
		InputStream inStream = System.in;

		try {
		//	inStream = new FileInputStream("C:\\Test\\Test.txt");
			BufferedReader reader = new BufferedReader(new InputStreamReader(
					inStream));
			StreamTokenizer st = new StreamTokenizer(reader);
			st.nextToken();
			int T = (int) st.nval;

			for (int i = 0; i < T; i++) {
				st.nextToken();
				s = st.sval;

				Process();

			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
