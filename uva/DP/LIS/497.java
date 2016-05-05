import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

/* UVA 497  Strategic Defense Initiative
 * longest increasing subsequence
 */
class Main {

	int[] M;
	int[] MVals;
	int[] Prevs;
	int L;

	void PrintLongest_r(Integer[] a, int i) {
		if (Prevs[i] >= 0)
			PrintLongest_r(a, Prevs[i]);

		System.out.println(a[i]);
	}

	void LIS(Integer[] a, int size) {
		M = new int[size + 1];
		MVals = new int[size + 1];
		Prevs = new int[size + 1];
		L = 1;
		M[0] = -1;
		M[1] = 0;
		MVals[1] = a[0];
		Prevs[0] = -1;
		Prevs[1] = -1;

		// init logic here
		for (int i = 1; i < size; i++) {
			// binary search
			int index = Arrays.binarySearch(MVals, 1, L + 1, a[i]);

			if (index >= 0) {
				// duplicate entry

			} else {

				int insertionPoint = (index + 1) * -1;

				Prevs[i] = M[insertionPoint - 1];

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

		System.out.println(String.format("Max hits: %d", L));
		PrintLongest_r(a, M[L]);
	}

	void Run() {
		InputStream inStream = System.in;

		// inStream = new FileInputStream(
		// "C:\\UVATest\\497\\Test.txt");
		/*
		 * Reader reader = new BufferedReader(new InputStreamReader(inStream));
		 * StreamTokenizer st = new StreamTokenizer(reader);
		 */

		Scanner sc = new Scanner(inStream);

		int numCases = Integer.parseInt(sc.nextLine());
		sc.nextLine();// empty line skipped

		for (int i = 0; i < numCases; i++) {

			if (i > 0)
				System.out.println();

			ArrayList<Integer> list = new ArrayList<Integer>();

			while (sc.hasNextLine()) {
				String line = sc.nextLine();

				if (line.length() == 0)
					break;

				list.add(Integer.parseInt(line));
			}

			Integer[] input = list.toArray(new Integer[list.size()]);
			LIS(input, list.size());
		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
