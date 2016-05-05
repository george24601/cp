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

/* UVA 10976  Fractions Again?!
 * smart complete search
 */
class Main {

	void Process (int k)
	{
		ArrayList<Integer> feasibleYs = new ArrayList<Integer>();
		
		for (int y = k + 1; y <= 2 * k; y++)
		{
			int above = y -k;
			int below = y * k;
			
			if (below % above == 0)
				feasibleYs.add(y);
		}
		
		System.out.println(feasibleYs.size());
		
		for (int i = 0; i < feasibleYs.size(); i++)
		{
			int y = feasibleYs.get(i);
			int x = (y * k) / (y - k);
			System.out.println(String.format("1/%d = 1/%d + 1/%d", k, x, y));
		}
		
	}
	void Run() {
		InputStream inStream = System.in;

		try {
			 //inStream = new FileInputStream(
			 //"C:\\UVATest\\10976\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);
			
			while (st.nextToken() != st.TT_EOF)
			{
				int k = (int)st.nval;
				
				Process(k);
				
			}

		} catch (IOException e) {

		}
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
