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

/* UVA 10827  Maximum sum on a torus
 * Maximum sum
 */

class Main {
	int[][] board;
	int[][] states;
	int N;
	int curMax;

	void CalcCurState() {
		for (int i = 0; i < N; i++) {
			int[] row = new int[N];
			int[] row2 = new int[N];

			for (int j = 0; j < N; j++)
				row[j] = states[i][j];

			int rowMax = row[0];

			for (int j = 1; j < N; j++) {
				if (rowMax < row[j])
					rowMax = row[j];
			}

			for (int L = 1; L < N; L++) {
				for (int j = 0; j < N; j++) {

					int prevIndex = j == 0 ? N - 1 : j - 1;

					int candidate = row[prevIndex] + states[i][j];

					if (candidate > states[i][j])
						row2[j] = candidate;
					else
						row2[j] = states[i][j];
				}

				row = row2;
				row2 = new int[N];
				
				for (int j = 0; j < N; j++)
				{
					if (row[j] > rowMax)
						rowMax = row[j];
				}
			}

			if (curMax < rowMax)
				curMax = rowMax;
		}

	}

	void Process() {
		states = new int[N][N];
		curMax = -1;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				states[i][j] = board[i][j];
		}

		CalcCurState();
		for (int extraRow = 1; extraRow < N; extraRow++) {
			for (int i = 0; i < N; i++) {
				
				int index = (i + extraRow) % N;
				for (int j = 0; j < N; j++) {
					states[i][j] += board[index][j];
				}

			}

			CalcCurState();
		}

		System.out.println(curMax);
	}

	void Run() {
		InputStream inStream = System.in;

		try {
	//		inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			st.nextToken();

			int p = (int) st.nval;

			for (int i = 0; i < p; i++) {
				st.nextToken();
				N = (int) st.nval;

				board = new int[N][N];

				for (int j = 0; j < N; j++) {
					for (int k = 0; k < N; k++) {
						st.nextToken();
						board[j][k] = (int) st.nval;
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
