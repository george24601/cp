import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.Arrays;

/* UVA 111  History grading
 * longest increasing subsequence
 */
class Main {


	void LIS(int[] a, int size)
	{
		int[] M = new int[size + 1];
		int[] MVals = new int[size + 1];
		int L = 1;
		M[1] = 0;
		MVals[1] =  a[0];
		
		//init logic here
		for (int i = 1; i < size; i++)
		{
			//binary search
			int index = Arrays.binarySearch(MVals, 1, L + 1, a[i]);
			
			int insertionPoint = (index + 1) * -1;

			if (insertionPoint == L + 1)
			{
				L++;
				M[L] = i;
				MVals[L] = a[i];
				
			}else{
				M[insertionPoint] = i;
				MVals[insertionPoint] = a[i];
			}
			
		}
		
		System.out.println(L);
	}

	void Run() {
		InputStream inStream = System.in;

		try {
			//inStream = new FileInputStream(
			//		"C:\\Users\\user\\PersonalCode\\Algorithms\\UVA\\111\\Test2.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);
			
			int n  =0;
			st.nextToken();
			n = (int)st.nval;
			
			int[] correct = new int[n];
			for (int i = 0; i < n; i++)
			{
				st.nextToken();
				correct[i] = (int)st.nval - 1;
			}
			
			while (true)
			{
				int[] input = new int[n];
				for (int j = 0; j < n; j++)
				{
					if (st.nextToken() == st.TT_EOF)
						return;
					
					input[(int)st.nval - 1] = correct[j];
				}
				
				LIS(input, n);
			}


		} catch (IOException e) {

		}
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
