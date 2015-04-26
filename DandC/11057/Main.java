import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.Arrays;


/* UVA 11057 exact sum
 * simple binary search
 */
class Main {

	void Process(int[] books,int N, int M)
	{
		Arrays.sort(books);
		
		int i = 0, j = Integer.MAX_VALUE;
		for (int index = 0;index < N; index++)
		{
			int target = M - books[index];
			int matchIndex = Arrays.binarySearch(books, target);
			
			if (matchIndex < 0)
				continue;
			
			if (target >= books[index] && target - books[index] < (j - i))
			{
				j = target;
				i = books[index];
			}
		}
		
		System.out.println(String.format("Peter should buy books whose prices are %d and %d.", i, j));
		System.out.println();
	}

	void Run() {
		InputStream inStream = System.in;


		try {
	//		inStream = new FileInputStream(
	//				"C:\\Users\\user\\PersonalCode\\Algorithms\\UVA\\11057\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer s = new StreamTokenizer(reader);
			
			while (s.nextToken() != s.TT_EOF)
			{
				int N = (int)s.nval;
				int[] books = new int[N];
				
				for (int i = 0; i < N; i++)
				{
					s.nextToken();
					books[i] = (int) s.nval;
				}
				
				s.nextToken();
				int M = (int)s.nval;
				
				Process(books, N, M);
			}


		} catch (IOException e) {

		}
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
