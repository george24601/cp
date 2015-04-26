import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.Arrays;
import java.util.Scanner;

/* UVA 836 Largest Submatrix
 * max sum
 */
class Main {

	int SingleRow(int[] bets, int s) {
		int[] endMaxSum = new int[s];
		endMaxSum[0] = bets[0];

		for (int i = 1; i < s; i++) {

			if (bets[i] == 0) {
				endMaxSum[i] = 0;
				continue;
			}

			int sumWithLast = endMaxSum[i - 1] + bets[i];

			if (bets[i] > 0 && sumWithLast >= bets[i]) {
				endMaxSum[i] = sumWithLast;
			} else {
				endMaxSum[i] = bets[i];
			}
		}

		int maxSum = Integer.MIN_VALUE;

		for (int i = 0; i < s; i++) {
			if (endMaxSum[i] > maxSum)
				maxSum = endMaxSum[i];
		}

		return maxSum;
	}

	void Calc(int[][] input, int numRows, int numCols) {
		int[][] sumBase = new int[numRows][numCols];

		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				sumBase[i][j] = input[i][j];
			}
		}

		int max = 0;

		for (int i = 0; i < numRows; i++) {
			int curVal = SingleRow(sumBase[i], numCols);

			if (curVal > max)
				max = curVal;
		}

		int[][] sumNext = new int[numRows][numCols];

		for (int i = 1; i < numRows; i++) {
			for (int j = 0; j + i < numRows; j++) {
				for (int k = 0; k < numCols; k++) {
					if (input[j + i][k] == 0 || sumBase[j + i - 1][k] == 0)// TODO:
																			// check
																			// this
					{
						sumNext[j + i][k] = 0;
					} else {
						sumNext[j + i][k] = sumBase[j + i - 1][k] + 1;
					}
				}

				int curVal = SingleRow(sumNext[j + i], numCols);

				if (curVal > max)
					max = curVal;

			}

			sumBase = sumNext;
			sumNext = new int[numRows][numCols];
		}

		System.out.println(max);
	}

	void Run() {
		InputStream inStream = System.in;

		try {
			//inStream = new FileInputStream(
			//		"C:\\Users\\user\\PersonalCode\\Algorithms\\UVA\\10074\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);
			
			while (true)
			{
				st.nextToken();
				int M = (int)st.nval;
				st.nextToken();
				int N = (int)st.nval;
				
				if (M == 0 && N == 0)
					break;
				
				int [][] input = new int[M][N];
				
				for (int i = 0; i < M; i++)
				{
					for (int j = 0; j < N; j++)
					{
						st.nextToken();
						int nextVal =  (int)st.nval;
						
						if (nextVal == 0)
							input[i][j] = 1;
						else
							input[i][j] = 0;
					}
				}
				
				Calc(input, M, N);
			}

		} catch (Exception e) {

		}
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
