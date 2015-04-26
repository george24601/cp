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
import java.util.StringTokenizer;

/* UVA 10664 Luggage
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
	//		 inStream = new FileInputStream(
	//		 "C:\\Users\\user\\PersonalCode\\Algorithms\\UVA\\10664\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			Scanner sc = new Scanner(reader);

			int m = Integer.parseInt(sc.nextLine());
			for (int i = 0; i < m; i++)
			{
				String line = sc.nextLine();
				
				StringTokenizer  st = new StringTokenizer(line);
				
				int[] weights = new int[20];
				
				int j = 0;
				for (; st.hasMoreTokens(); j++)
				{
					weights[j] = Integer.parseInt(st.nextToken());
				}
				
				int[] vals = new int[j];
				int[] ws = new int[j];
				
				int totalWeight  =0;
				for (int k = 0; k < j; k++)
				{
					vals[k] = weights[k];
					ws[k] = weights[k];
					totalWeight += weights[k];
				}
				
				int max = Knapsack(vals, ws, totalWeight/2);
				
				if (max * 2 == totalWeight)
					System.out.println("YES");
				else
					System.out.println("NO");
			}

		} catch (Exception e) {

		}
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
