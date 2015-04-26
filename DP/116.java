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

/* UVA 116 Unidirectional TSP
 * DP
 */

class Main {

	int m;
	int n;
	int[][] matrix;
	int[][] prev;
	int[][] minWeights;

	void Print_r(int rowIndex, int colIndex) {
		if (colIndex == 0) {
			System.out.print(rowIndex + 1);
			return;
		}

		Print_r(prev[rowIndex][colIndex], colIndex - 1);

		System.out.print(" ");
		System.out.print(rowIndex + 1);
	}

	int LexSmaller(int rowIndex1, int rowIndex2, int colIndex) {

		if (colIndex > 0) {
			int prevSmaller = LexSmaller(prev[rowIndex1][colIndex],
					prev[rowIndex2][colIndex], colIndex - 1);

			if (prevSmaller != 0)
				return prevSmaller;
		}

		if (rowIndex1 < rowIndex2)
			return 1;
		if (rowIndex1 == rowIndex2)
			return 0;
		else
			return -1;
	}

	void Process() {
		for (int i = 0; i < m; i++) {
			prev[i][0] = -1;
			minWeights[i][0] = matrix[i][0];
		}

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int levelW = minWeights[j][i - 1] + matrix[j][i];

				minWeights[j][i] = levelW;
				prev[j][i] = j;

				int lowerIndex = (j + m - 1) % m;
				int lowerW = minWeights[lowerIndex][i - 1] + matrix[j][i];

				if (lowerW < minWeights[j][i]
						|| (lowerW == minWeights[j][i] && LexSmaller(
								lowerIndex, prev[j][i], i - 1) == 1)) {
					minWeights[j][i] = lowerW;
					prev[j][i] = lowerIndex;
				}

				int upperIndex = (j + 1) % m;
				int upperW = minWeights[upperIndex][i - 1] + matrix[j][i];

				if (upperW < minWeights[j][i]
						|| (upperW == minWeights[j][i] && LexSmaller(
								upperIndex, prev[j][i], i - 1) == 1)) {
					minWeights[j][i] = upperW;
					prev[j][i] = upperIndex;
				}
			}
		}

		int minTotal = minWeights[0][n - 1];
		int minEnd = 0;
		for (int i = 1; i < m; i++) {
			int curVal = minWeights[i][n - 1];

			if (curVal < minTotal || (curVal == minTotal && LexSmaller(i, minEnd, n - 1) == 1)) {
				minTotal = curVal;
				minEnd = i;
			}
		}

		Print_r(minEnd, n - 1);
		System.out.println();
		System.out.println(minTotal);
	}

	void Run() {
		InputStream inStream = System.in;

		try {
		//	inStream = new FileInputStream("C:\\Test\\Test.txt");
			BufferedReader reader = new BufferedReader(new InputStreamReader(
					inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			while (st.nextToken() != st.TT_EOF) {
				m = (int) st.nval;

				st.nextToken();
				n = (int) st.nval;

				matrix = new int[m][n];
				prev = new int[m][n];
				minWeights = new int[m][n];

				for (int i = 0; i < m; i++) {
					for (int j = 0; j < n; j++) {
						st.nextToken();
						matrix[i][j] = (int) st.nval;
					}
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
