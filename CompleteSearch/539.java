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
import java.util.List;
import java.util.Scanner;

/* UVA 539 The Settlers of Catan
 * longest path: NP-complete
 */

class Main {
	List<List<Integer>> edges;
	int curLength;
	int maxLength;
	int[] visited;
	
	void Process_r(int current)
	{
		for(Integer i : edges.get(current))
		{
			if(((visited[current] >> i) & 1) == 1)
				continue;
			
			curLength++;
			
			if (curLength > maxLength)
				maxLength = curLength;
			
			int visitedCurrentBefore = visited[current];
			visited[current] = visitedCurrentBefore | 1 << i;
			
			int visitedIBefore = visited[i];
			visited[i] = visitedIBefore | 1 << current;
			
			Process_r(i);
			curLength--;
			
			visited[current] = visitedCurrentBefore;
			visited[i] = visitedIBefore;
			
		}
	}
	
	void Run() {
		InputStream inStream = System.in;

		try {
			// inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			while (true) {
				st.nextToken();
				int n = (int) st.nval;
				st.nextToken();
				int m = (int) st.nval;
				
				if (n == 0 || m == 0)
					break;
				
				edges = new ArrayList<List<Integer>>();
				curLength = 0;
				maxLength = 0;
				visited = new int[n];
				
				for (int i = 0; i < n; i++)
					visited[i] = 0;
				
				for (int i = 0; i < n; i++)
					edges.add(new ArrayList<Integer>());
				
				for (int i = 0; i < m ; i++)
				{
					st.nextToken();
					int u = (int) st.nval;
					st.nextToken();
					int v = (int) st.nval;
					
					edges.get(u).add(v);
					edges.get(v).add(u);
				}
				
				for (int i = 0; i < n; i++)
					Process_r(i);
				
				
				System.out.println(maxLength);
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
