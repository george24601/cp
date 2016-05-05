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

/* UVA 1260 Sales
 * ad hoc
 */

class Main {

	void Process(long[] as, int n)
	{
		long sum = 0;
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (as[j] <= as[i])
					sum++;
			}
		}
		
		System.out.println(sum);
	}

	void Run() {
		InputStream inStream = System.in;

		try {
			//inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			st.nextToken();
			int T = (int) st.nval;

			for (int i = 0; i < T; i++) {
				st.nextToken();
				int n = (int) st.nval;

				long[] as = new long[n];
				
				for (int j = 0; j < n; j++)
				{
					st.nextToken();
					as[j] = (long) st.nval;
					
				}
				
				Process(as, n);
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
