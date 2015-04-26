import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.Arrays;

/* UVA 10306. e-Coins
 * knap sack
 */
class Main {

	void Process(int[] xs, int[] ys, int m, int S) {
		int[][] matrix = new int[S + 1][S + 1];

		for (int i = 0; i < m; i++) {
			int x = xs[i];
			int y = ys[i];
			for (int j = 0; j < S + 1; j++) {
				for (int k = 0; k < S + 1; k++) {
					int oldVal = matrix[j][k];
					if (j == x && k == y) {
						matrix[j][k] = 1;
						continue;
					} else {

						int prevX = j - x;
						int prevY = k - y;

						if (prevX < 0 || prevY < 0 || matrix[prevX][prevY] == 0) {
							continue;
						} else {
							int newVal = matrix[prevX][prevY] + 1;
							if (oldVal == 0)
								matrix[j][k] = newVal;
							else if (newVal < oldVal)
								matrix[j][k] = newVal;
						}
					}
				}
			}
		}

		int max = -1;
		for (int i = 0; i < S + 1; i++) {
			for (int j = 0; j < S + 1; j++) {
				int val = matrix[i][j];

				if (i * i + j * j == S * S) {
					if (val <= 0)
						continue;
					else if (max < 0 || val < max)
						max = val;
				}
			}
		}

		if (max < 0)
			System.out.println("not possible");
		else
			System.out.println(max);
	}

	void Run() {
		InputStream inStream = System.in;

		try {
		//	inStream = new FileInputStream(
		//			"C:\\Users\\user\\PersonalCode\\Algorithms\\UVA\\10306\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			st.nextToken();
			int n = (int) st.nval;

			for (int i = 0; i < n; i++) {
				st.nextToken();
				int m = (int) st.nval;
				st.nextToken();
				int S = (int) st.nval;

				int[] xs = new int[m];
				int[] ys = new int[m];

				for (int j = 0; j < m; j++) {
					st.nextToken();
					xs[j] = (int) st.nval;
					st.nextToken();
					ys[j] = (int) st.nval;
				}

				Process(xs, ys, m, S);
			}

		} catch (IOException e) {

		}
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
