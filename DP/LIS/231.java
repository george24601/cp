import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.Arrays;

/* UVA 231  Testing the CATCHER 
 * longest increasing subsequence
 */
class Main {

	void LIS(Integer[] a, int size) {
		int[] M = new int[size + 1];
		int[] MVals = new int[size + 1];
		int L = 1;
		M[1] = 0;
		MVals[1] = a[0];

		// init logic here
		for (int i = 1; i < size; i++) {
			// binary search
			int index = Arrays.binarySearch(MVals, 1, L + 1, a[i]);

			if (index >= 0) {
				for (int j = index + 1; j <= L + 1; j++)
				{
					M[j] = M[j - 1];
					MVals[j] = MVals[j - 1];
				}
				
				L++;
				
			} else {

				int insertionPoint = (index + 1) * -1;

				if (insertionPoint == L + 1) {
					L++;
					M[L] = i;
					MVals[L] = a[i];

				} else {
					M[insertionPoint] = i;
					MVals[insertionPoint] = a[i];
				}
			}

		}

		System.out.println(String.format("  maximum possible interceptions: %d", L));
	}

	void Run() {
		InputStream inStream = System.in;

		try {
		//	inStream = new FileInputStream(
		//			"C:\\Users\\user\\PersonalCode\\Algorithms\\UVA\\231\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			int caseNum = 0;
			while (true) {
				st.nextToken();
				int n = (int) st.nval;

				if (n == -1)
					break;
				
				caseNum++;
				
				if (caseNum > 1)
					System.out.println();
				
				System.out.println(String.format("Test #%d:", caseNum));

				ArrayList<Integer> list = new ArrayList<Integer>();

				list.add(n * -1);

				while (true) {
					st.nextToken();
					int m = (int) st.nval;

					if (m == -1)
						break;

					list.add(m * -1);
				}

				Integer[] input = list.toArray(new Integer[list.size()]);
				LIS(input, list.size());

			}

		} catch (IOException e) {

		}
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
