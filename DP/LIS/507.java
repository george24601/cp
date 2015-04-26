import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.Arrays;

/* UVA 507 Jill Rides Again
 * max sum
 */
class Main {

	int caseNum;

	void Process(int[] intervals, int s) {
		int[] endMaxSum = new int[s - 1];
		endMaxSum[0] = intervals[0];

		int[] sumStart = new int[s - 1];
		sumStart[0] = 0;

		for (int i = 1; i < s - 1; i++) {
			int sumWithLast = endMaxSum[i - 1] + intervals[i];

			if (sumWithLast >= intervals[i]) {
				endMaxSum[i] = sumWithLast;
				sumStart[i] = sumStart[i - 1];
			} else {
				endMaxSum[i] = intervals[i];
				sumStart[i] = i;
			}
		}

		int maxSum = Integer.MIN_VALUE;
		int start = 0;
		int end = 0;

		for (int i = 0; i < s - 1; i++) {
			if (endMaxSum[i] > maxSum) {
				maxSum = endMaxSum[i];
				start = sumStart[i];
				end = i;

			} else if (endMaxSum[i] == maxSum) {
				int newStart = sumStart[i];

				if (i - newStart > end - start) {
					start = newStart;
					end = i;
				}
			}
		}

		if (maxSum > 0)
			System.out.println(String.format(
					"The nicest part of route %d is between stops %d and %d",
					caseNum, start + 1, end + 2));
		else
			System.out.println(String.format("Route %d has no nice parts",
					caseNum));
	}

	void Run() {
		InputStream inStream = System.in;

		try {
		//	inStream = new FileInputStream(
		//			"C:\\Users\\user\\PersonalCode\\Algorithms\\UVA\\507\\Test2.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			st.nextToken();
			int b = (int) st.nval;

			for (int i = 0; i < b; i++) {
				st.nextToken();
				int s = (int) st.nval;

				int[] stops = new int[s - 1];

				for (int j = 0; j < s - 1; j++) {
					st.nextToken();
					stops[j] = (int) st.nval;
				}

				caseNum = i + 1;
				Process(stops, s);
			}

		} catch (IOException e) {

		}
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
