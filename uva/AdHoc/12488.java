import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

/* UVA 12488 Start Grid
 * ad hoc -inversion index
 */

class Main {
	int[] start;
	int N;


	void Run() {
		InputStream inStream = System.in;

		try {
			//inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);
			
			while(st.nextToken() != st.TT_EOF)
			{
				 N = (int)st.nval;
				
				start = new int[N];
				
				for (int i = 0; i < N; i++)
				{
					st.nextToken();
					
					start[i] = (int)st.nval;
				}
			
				HashMap<Integer, Integer> end = new HashMap<Integer, Integer>();
				
				for(int i = 0; i < N; i++)
				{
					st.nextToken();
					end.put((int)st.nval, i);
				}
				
				int [] processed = new int[N];
				
				for (int i = 0; i < N; i++)
				{
					processed[i] = end.get(start[i]);
				}
				
				int sum = 0;
				
				for (int i = 0; i < N; i++)
				{
					for (int j = i+ 1; j < N; j++)
					{
						if (processed[j] < processed[i])
							sum++;
					}
				}
				
				System.out.println(sum);
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
