import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.Arrays;


/* UVA 10474 where is the marbel 
 * simple binary search
 */
class Main {

	void Run() {
		InputStream inStream = System.in;

		/*
		try {
			inStream = new FileInputStream(
					"C:\\Users\\user\\PersonalCode\\Algorithms\\UVA\\10474\\Test.txt");
		} catch (Exception e) {
		}
		*/

		try {
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer s = new StreamTokenizer(reader);

			int caseNum = 0;
			while (s.nextToken() != s.TT_EOF) {
				int N  = (int) s.nval;
				s.nextToken();
				int Q = (int) s.nval;
				
				if (N == 0 && Q == 0)
					break;
				
				caseNum++;

				int[] marbles = new int[N];
				
				for (int i = 0; i < N; i++)
				{
					s.nextToken();
					marbles[i] = (int)s.nval;
				}
				
				Arrays.sort(marbles);
				
				System.out.println(String.format("CASE# %d:", caseNum));
				for (int i = 0; i < Q; i++)
				{
					s.nextToken();
					int query = (int)s.nval;
					
					int index = Arrays.binarySearch(marbles, query);
					
					if (index < 0)
						System.out.println(String.format("%d not found", query));
					else
					{
						while (index > 0 && marbles[index - 1] == query)
							index--;
						
						System.out.println(String.format("%d found at %d", query, index + 1));
					}
				}
			}


		} catch (IOException e) {

		}
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
