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

/* UVA 10667  Largest Block 
 * Maximum sum
 */

class Main {
	int[][] board;
	int[][] states;
	int s;
	int curMax;

	void CalcCurState() {
		for (int i = 0; i < s; i++) {
			int[] rowResult = new int[s];

			rowResult[0] = states[i][0];

			for (int j = 1; j < s; j++) {
				if (states[i][j] > 0) {
					if (rowResult[j - 1] == 0)
						rowResult[j] = states[i][j];
					else
						rowResult[j] = rowResult[j - 1] + states[i][j];

				} else {
					rowResult[j] = 0;
				}

			}
			int rowMax = 0;

			for (int j = 0; j < s; j++) {
				if (rowResult[j] > rowMax)
					rowMax = rowResult[j];
			}

			if (curMax < rowMax)
				curMax = rowMax;
		}

	}

	void Process() {
		states = new int[s][s];
		curMax = -1;

		for (int i = 0; i < s; i++) {
			for (int j = 0; j < s; j++)
				states[i][j] = board[i][j];
		}

		CalcCurState();
		for (int extraRow = 1; extraRow < s; extraRow++) {
			for (int i = 0; i + extraRow < s; i++) {
				for (int j = 0; j < s; j++) {
					if (states[i][j] > 0 && board[i + extraRow][j] > 0)
						states[i][j] += 1;
					else
						states[i][j] = 0;
				}

			}

			CalcCurState();
		}
		
		System.out.println(curMax);
	}

	void Run() {
		InputStream inStream = System.in;

		try {
			 //inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			st.nextToken();

			int p = (int) st.nval;

			for (int i = 0; i < p; i++) {
				st.nextToken();
				s = (int) st.nval;

				board = new int[s][s];

				for (int j = 0; j < s; j++) {
					for (int k = 0; k < s; k++)
						board[j][k] = 1;
				}

				st.nextToken();

				int b = (int) st.nval;

				for (int j = 0; j < b; j++) {
					st.nextToken();
					int r1 = (int) st.nval;
					st.nextToken();
					int c1 = (int) st.nval;
					st.nextToken();
					int r2 = (int) st.nval;
					st.nextToken();
					int c2 = (int) st.nval;

					for (int k = r1; k <= r2; k++) {
						for (int l = c1; l <= c2; l++)
							board[k - 1][l - 1] = 0;
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
