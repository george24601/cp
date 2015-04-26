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
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

/* UVA 957 Popes
 * binary search
 */

class Main {

	int Y;
	int P;
	int[] popes;
	void Process()
	{
		int LN = 0;
		int First = 0;
		int Last = 0;
		for (int i = 0; i < P; i++)
		{
			int target = popes[i] + Y - 1;
			int index = Arrays.binarySearch(popes, target);
			
			int num = 0;
			if (index >= 0)
			{
				 num = index - i + 1;
			}else
			{
				int insertionPoint =  -1 - index;
				num = insertionPoint - i;
			}
			
			if (num > LN)
			{
				LN = num;
				First = popes[i];
				Last = popes[i + num - 1];
			}
				
		}
		
		System.out.println(String.format("%d %d %d", LN, First, Last));
	}
	
	void Run() {
		InputStream inStream = System.in;

		try {
		//	inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			while (st.nextToken() != st.TT_EOF)
			{
				Y = (int)st.nval;
				
				st.nextToken();
				P = (int)st.nval;
				popes = new int[P];
				
				for (int i = 0; i < P; i++)
				{
					st.nextToken();
					popes[i] = (int) st.nval;
				}
				
				Process();
			}
			

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
