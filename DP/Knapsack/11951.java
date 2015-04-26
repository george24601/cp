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
import java.util.Dictionary;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Vector;

/* UVA 11951  Area
 * Maximum sum
 */

class Main {
	long[][] board;
	long[][] states;
	int N;
	int M;
	long K;

	long curMaxPrice;
	int curMaxArea;

	long maxRowP;
	int maxRowCol;

	void CalcRow(long[] row, long[] sumRow) {

		int end = 0;

		for (int j = 0; j < M; j++) {

			if (row[j] > K) {
				end = j + 1;

			} else {

				while (end < M - 1) {

					long newSum = sumRow[end + 1] - sumRow[j] + row[j];

					if (newSum <= K) {
						end++;

					} else {
						break;
					}
				}

				if (end - j + 1 > maxRowCol) {
					maxRowCol = end - j + 1;
					long rowP = sumRow[end] - sumRow[j] + row[j];
					
					maxRowP = rowP;
				}else if (end - j + 1 == maxRowCol)
				{
					long rowP = sumRow[end] - sumRow[j] + row[j];
					
					if (maxRowP > rowP)
						maxRowP = rowP;
				}
			}
		}
	}

	void CalcCurState(int extraRow) {

		maxRowCol = 0;

		for (int i = 0; i + extraRow < N; i++) {
			long[] row = new long[M];
			long[] rowSum = new long[M];

			for (int j = 0; j < M; j++)
				row[j] = states[i][j];

			rowSum[0] = row[0];
			for (int j = 1; j < M; j++)
				rowSum[j] = row[j] + rowSum[j - 1];

			CalcRow(row, rowSum);

		}
	}

	void Process() {
		states = new long[N][M];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				states[i][j] = board[i][j];
		}

		CalcCurState(0);
		curMaxArea = maxRowCol;
		curMaxPrice = maxRowP;

		for (int extraRow = 1; extraRow < N; extraRow++) {
			for (int i = 0; i + extraRow < N; i++) {

				int index = (i + extraRow) % N;
				for (int j = 0; j < M; j++) {
					states[i][j] += board[index][j];
				}

			}

			CalcCurState(extraRow);

			int maxArea = maxRowCol * (extraRow + 1);

			if (maxArea > curMaxArea) {
				curMaxArea = maxArea;
				curMaxPrice = maxRowP;
			}else if (maxArea == curMaxArea)
			{
				if (maxRowP < curMaxPrice)
					curMaxPrice = maxRowP;
			}
		}
	}

	void Run() {
		InputStream inStream = System.in;

		try {
			//inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			st.nextToken();

			long T = (long) st.nval;

			for (long i = 0; i < T; i++) {
				st.nextToken();
				N = (int) st.nval;
				st.nextToken();
				M = (int) st.nval;
				st.nextToken();
				K = (long) st.nval;

				board = new long[N][M];

				for (int j = 0; j < N; j++) {
					for (int k = 0; k < M; k++) {
						st.nextToken();
						board[j][k] = (long) st.nval;
					}
				}

				Process();
				System.out.println(String.format("Case #%d: %d %d", i + 1,
						curMaxArea, curMaxPrice));
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
