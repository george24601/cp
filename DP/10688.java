import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Dictionary;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Vector;

/* UVA 10688 The Poor Giant
 * DP
 */

class Main {
	int n, k;
	long[][] total;

	int Weight(int i) {
		return i + k + 1;
	}

	void Process()
	{
		for (int i = 0; i < n; i++)
			total[i][i] = 0;

		for (int i = 0; i + 1 < n; i++)
			total[i][i + 1] = 2 * Weight(i);
		
		for (int size = 3; size <= n; size++)
		{
			for(int i = 0; i+ size - 1 < n; i++)
			{
				int endIndex = i + size - 1;
				for(int j = i; j <=endIndex; j++)
				{
					long leftVal = j > i ? total[i][j -1] : 0;
					long midVal = size * Weight(j);
					long rightVal = j < endIndex ? total[j + 1][endIndex] : 0;
					
					long tc = leftVal + midVal + rightVal;
					
					if (total[i][endIndex] == 0 || total[i][endIndex] > tc)
						total[i][endIndex] = tc;
				}
			}
			
		}
		
		System.out.println(total[0][n - 1]);
	}

	void Run() {
		InputStream inStream = System.in;

		try {
		//	inStream = new FileInputStream("C:\\Test\\Test.txt");
			BufferedReader reader = new BufferedReader(new InputStreamReader(
					inStream));

			StreamTokenizer st = new StreamTokenizer(reader);
			st.nextToken();

			int t = (int) st.nval;

			for (int i = 0; i < t; i++) {
				st.nextToken();
				n = (int) st.nval;
				st.nextToken();
				k = (int) st.nval;

				total = new long[n + 1][n + 1];
				
				System.out.print(String.format("Case %d: ", i + 1));
				Process();
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
