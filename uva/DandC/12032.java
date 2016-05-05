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
	int[] rs;

	boolean CanComplete_r(int jumpHeight, int at)
	{
		if (at == n)
			return true;
		
		int nextToJump = at == 0? rs[0] : rs[at] - rs[at - 1];

		if (nextToJump > jumpHeight)
			return false;
		else if (nextToJump == jumpHeight)
			return CanComplete_r(jumpHeight -1, at + 1);
		else
			return CanComplete_r(jumpHeight, at + 1);
	}

	int Process_r(int min, int max) {
		if (min == max)
			return min;

		int mid = (min + max) / 2;
		
		if (CanComplete_r(mid, 0))
			return Process_r(min, mid);
		else
			return Process_r(mid + 1, max);
	}

	void Run() {
		InputStream inStream = System.in;

		try {
		//	inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);
			st.nextToken();
			int T = (int) st.nval;

			for (int i = 0; i < T; i++) {
				st.nextToken();
				n = (int) st.nval;
				rs = new int[n];

				for (int j = 0; j < n; j++) {
					st.nextToken();
					rs[j] = (int) st.nval;
				}
				
				System.out.println(String.format("Case %d: %d", i +1, Process_r(1, rs[n-1])));
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
