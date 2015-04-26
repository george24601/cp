import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Dictionary;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Vector;

/* UVA 11413 Fill the Containers

 * binary search
 */

class Main {

	int n;
	int m;
	int[] cs;
	int[] sumCs;

	boolean CanFit_r(int capacity, int numContainers, int startVessel) {

		if (startVessel >= n)
			return true;

		if (numContainers == 0)
			return false;

		int targetCapacity = startVessel == 0 ? capacity
				: sumCs[startVessel - 1] + capacity;

		int nextVessel = Arrays.binarySearch(sumCs, startVessel, n - 1,
				targetCapacity);

		if (nextVessel >= 0) {
			return CanFit_r(capacity, numContainers - 1, nextVessel + 1);
		} else {
			int insertionPt = -1 - nextVessel;

			if (insertionPt == 0) {
				return false;
			} else if (insertionPt >= n - 1) {

				if (targetCapacity >= sumCs[n - 1])
					return true;
				else
					return CanFit_r(capacity, numContainers - 1, insertionPt);
			} else {
				return CanFit_r(capacity, numContainers - 1, insertionPt);
			}
		}
	}

	void Process_r(int min, int max) {
		if (min == max) {
			System.out.println(min);
			return;
		}

		int mid = (min + max) / 2;

		if (CanFit_r(mid, m, 0))
			Process_r(min, mid);
		else
			Process_r(mid + 1, max);
	}

	void Run() {
		InputStream inStream = System.in;

		try {
		//	inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			while (st.nextToken() != st.TT_EOF) {
				n = (int) st.nval;
				st.nextToken();
				m = (int) st.nval;

				cs = new int[n];
				sumCs = new int[n];

				for (int i = 0; i < n; i++) {
					st.nextToken();
					cs[i] = (int) st.nval;

					if (i == 0)
						sumCs[i] = cs[i];
					else
						sumCs[i] = sumCs[i - 1] + cs[i];

				}

				Process_r(1, 1000000000);
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
