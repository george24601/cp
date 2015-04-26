import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/* UVA 10487 closes sums 
 * binary search
 */
class Main {

	long abs(List<Long> sorted, int index, long current, long q, long minDiff) {
		long diff = sorted.get(index) + current - q;

		long val = diff > 0 ? diff : (-1 * diff);
		return val > minDiff ? minDiff : val;
	}

	long p(List<Long> sorted, long q) {
		long minDiff = Integer.MAX_VALUE;
		long minDiffSum = 0;

		for (int i = 0; i < sorted.size(); i++) {
			long current = sorted.get(i);
			long target = q - current;
			int index = Collections.binarySearch(sorted, target);

			int insertionP = index > 0 ? index : (-1 * index - 1);

			if (insertionP > 0 && insertionP - 1 != i) {
				long newMinDiff = abs(sorted, insertionP - 1, current, q, minDiff);

				if (newMinDiff < minDiff)
				{
					minDiffSum = current + sorted.get(insertionP - 1);
					minDiff = newMinDiff;
				}

			}

			if (insertionP < sorted.size() - 1 && insertionP + 1 != i) {
				long newMinDiff = abs(sorted, insertionP + 1, current, q, minDiff);

				if (newMinDiff < minDiff)
				{
					minDiffSum = current + sorted.get(insertionP + 1);
					minDiff = newMinDiff;
				}
			}

			if (insertionP >= 0 && insertionP < sorted.size()
					&& insertionP != i) {
				long newMinDiff = abs(sorted, insertionP, current, q, minDiff);

				if (newMinDiff < minDiff)
				{
					minDiffSum = current + sorted.get(insertionP);
					minDiff = newMinDiff;
				}
			}

		}

		return minDiffSum;
	}

	void Run() {
		InputStream inStream = System.in;
		/*
		try {
			inStream = new FileInputStream(
					"D:\\PersonalCode\\Algorithms\\UVA\\10487\\Test.txt");
		} catch (Exception e) {
		}
		*/

		try {
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer s = new StreamTokenizer(reader);

			int count = 0;
			while (true) {
				s.nextToken();
				int n = (int) s.nval;
				if (n == 0)
					break;
				count++;
				System.out.println(String.format("Case %d:", count));

				List<Long> nums = new ArrayList<Long>();

				for (int i = 0; i < n; i++) {
					s.nextToken();
					nums.add((long) s.nval);
				}
				s.nextToken();
				int m = (int) s.nval;

				Collections.sort(nums);
				for (int i = 0; i < m; i++) {
					s.nextToken();
					long q = (long) s.nval;
					long result = p(nums, q);

					System.out.println(String.format(
							"Closest sum to %d is %d.", q, result));
				}
			}

		} catch (IOException e) {

		}
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
