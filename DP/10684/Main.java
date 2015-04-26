import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.Arrays;

/* UVA 10684 The jackpot
 * max sum
 */
class Main {

	void Process(int[] bets, int s) {
		int[] endMaxSum = new int[s];
		endMaxSum[0] = bets[0];

		for (int i = 1; i < s; i++) {
			int sumWithLast = endMaxSum[i - 1] + bets[i];

			if (sumWithLast >= bets[i]) {
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

		if (maxSum > 0)
			System.out.println(String.format(
					"The maximum winning streak is %d.", maxSum));
		else
			System.out.println("Losing streak.");
	}

	void Run() {
		InputStream inStream = System.in;

		try {
		//	inStream = new FileInputStream(
		//			"C:\\Users\\user\\PersonalCode\\Algorithms\\UVA\\10684\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			while (true)
			{
				st.nextToken();
				int s = (int)st.nval;
				
				if (s == 0)
					break;
				
				int [] bets = new int[s];
				
				for (int i = 0; i < s; i++)
				{
					st.nextToken();
					bets[i] = (int)st.nval;
				}
				
				Process(bets, s);
			}

		} catch (IOException e) {

		}
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
