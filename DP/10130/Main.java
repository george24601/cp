import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.math.BigDecimal;
import java.util.Arrays;
import java.util.Scanner;

/* UVA 10130 SuperSale
 * knapsack problem
 */
class Main {
	int Knapsack(int[] values, int[] weights, int room) {
		int[] base = new int[room + 1];
		int[] next = new int[room + 1];

		int n = values.length;

		for (int i = 0; i < room + 1; i++)
			base[i] = 0;

		for (int i = 0; i < n; i++) {
			for (int stepRoom = 0; stepRoom < room + 1; stepRoom++) {

				int noUseVal = base[stepRoom];

				if (stepRoom < weights[i]) {
					next[stepRoom] = noUseVal;
				} else {

					int useVal = base[stepRoom - weights[i]] + values[i];

					if (noUseVal > useVal)
						next[stepRoom] = noUseVal;
					else
						next[stepRoom] = useVal;

				}
			}

			base = next;
			next = new int[room + 1];
		}

		return base[room];
	}

	void Run() {
		InputStream inStream = System.in;

		try {
			// inStream = new FileInputStream(
			 //"C:\\Users\\user\\PersonalCode\\Algorithms\\UVA\\10130\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);
			st.nextToken();
			int T = (int) st.nval;

			for (int i = 0; i < T; i++) {
				st.nextToken();
				int N = (int) st.nval;
				int[] prices = new int[N];
				int[] weights = new int[N];

				for (int j = 0; j < N; j++) {
					st.nextToken();
					prices[j] = (int) st.nval;
					st.nextToken();
					weights[j] = (int) st.nval;
				}

				st.nextToken();
				int G = (int) st.nval;

				long total = 0;
				for (int j = 0; j < G; j++) {

					st.nextToken();
					int room = (int) st.nval;
					int maxVal = Knapsack(prices, weights, room);
					total += maxVal;
				}
				
				System.out.println(total);
			}

		} catch (IOException e) {

		}
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
