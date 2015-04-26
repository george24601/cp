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

/* UVA 562 Dividing coins
 * knapsack problem
 */
class Main {
	long Knapsack(int[] values, int room) {
		int[] base = new int[room + 1];
		int[] next = new int[room + 1];

		int n = values.length;
		
		for (int i = 0; i < room + 1; i++)
			base[i] = 0;

		for (int i = 0; i < n; i++) {
			for (int stepRoom = 0; stepRoom < room + 1; stepRoom++) {

				int noUseVal = base[stepRoom];

				if (stepRoom < values[i]) {
					next[stepRoom] = noUseVal;
				} else {

					int useVal = base[stepRoom - values[i]] + values[i];

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
	//		inStream = new FileInputStream(
	//				"C:\\Users\\user\\PersonalCode\\Algorithms\\UVA\\562\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);
			st.nextToken();
			int n = (int) st.nval;

			for (int i = 0; i < n; i++) {
				st.nextToken();
				int m = (int) st.nval;
				int[] coins = new int[m];

				int sum = 0;

				for (int j = 0; j < m; j++) {
					st.nextToken();
					int coin = (int) st.nval;
					coins[j] = coin;
					sum += coin;
				}

				int target = sum / 2;

				long maxLong = Knapsack(coins, target);

				System.out.println(sum - maxLong - maxLong);
			}

		} catch (IOException e) {

		}
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
