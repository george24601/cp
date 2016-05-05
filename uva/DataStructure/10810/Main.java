import java.io.FileInputStream;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;

/* UVA 10810 inversion index with merge sort
 */
class Main {

	long Merge(int[] unsorted, int start, int midIndex, int end) {
		long totalOp = 0;

		int leftSize = midIndex - start + 1;
		int[] left = new int[leftSize];
		System.arraycopy(unsorted, start, left, 0, leftSize);
		int rightSize = end - midIndex;
		int[] right = new int[rightSize];
		System.arraycopy(unsorted, midIndex + 1, right, 0, rightSize);

		int currentIndex = start;
		int leftIndex = 0;
		int rightIndex = 0;

		while (leftIndex < leftSize || rightIndex < rightSize) {
			int actualLeftIndex = start + leftIndex;
			int actualRightIndex = midIndex + 1 + rightIndex;

			if (leftIndex < leftSize && rightIndex < rightSize) {
				int leftNum = left[leftIndex];
				int rightNum = right[rightIndex];
				if (leftNum < rightNum) {
					unsorted[currentIndex] = leftNum;

					if (actualLeftIndex > currentIndex)
						totalOp += actualLeftIndex - currentIndex;

					leftIndex++;

				} else if (left[leftIndex] > right[rightIndex]) {
					unsorted[currentIndex] = rightNum;

					if (actualRightIndex > currentIndex)
						totalOp += actualRightIndex - currentIndex;

					rightIndex++;
				} else {
					unsorted[currentIndex] = leftNum;

					if (actualLeftIndex > currentIndex)
						totalOp += actualLeftIndex - currentIndex;

					leftIndex++;
				}

			} else if (leftIndex < leftSize) {
				int leftNum = left[leftIndex];
				unsorted[currentIndex] = leftNum;

				if (actualLeftIndex > currentIndex)
					totalOp += actualLeftIndex - currentIndex;

				leftIndex++;

			} else {
				int rightNum = right[rightIndex];
				unsorted[currentIndex] = rightNum;

				if (actualRightIndex > currentIndex)
					totalOp += actualRightIndex - currentIndex;

				rightIndex++;
			}

			currentIndex++;
		}

		return totalOp;
	}

	long Process_r(int[] unsorted, int start, int end) {
		if (start >= end)
			return 0;

		int midIndex = start + ((end - start) / 2);

		long left = Process_r(unsorted, start, midIndex);
		long right = Process_r(unsorted, midIndex + 1, end);

		long mergeOps = Merge(unsorted, start, midIndex, end);

		return left + right + mergeOps;
	}

	void Run() {
		InputStream inStream = System.in;

		/*
		try {
			inStream = new FileInputStream(
					"C:\\Users\\user\\Downloads\\B.1.dat");
					//"D:\\PersonalCode\\Algorithms\\UVA\\10810\\Test.txt");
		} catch (Exception e) {

		}
		*/

		Scanner s = new Scanner(inStream);
		while (s.hasNextLine()) {
			int n = Integer.parseInt(s.nextLine());

			if (n == 0)
				break;

			int[] unsorted = new int[n];

			for (int i = 0; i < n; i++) {
				int nextNum = Integer.parseInt(s.nextLine());
				unsorted[i] = nextNum;
			}

			System.out.println(Process_r(unsorted, 0, n - 1));
		}

		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
