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

/* UVA 1237 
 * complete search
 */

class Main {

	class Car
	{
		public String M;
		public int L;
		public int H;
		
		public Car (String name, int max, int min)
		{
			M = name;
			L = max;
			H = min;
		}
	}
	
	void Process(Car[] cars, int P, int D)
	{
		int toReturnIndex = -1;
		for (int i = D-1; i >= 0; i--)
		{
			if (cars[i].L > P || cars[i].H < P)
				continue;
			
			if (toReturnIndex >= 0)
			{
				System.out.println("UNDETERMINED");
				return;
			}else
			{
				toReturnIndex = i;
			}
			
		}
		
		if (toReturnIndex < 0)
			System.out.println("UNDETERMINED");
		else
			System.out.println(cars[toReturnIndex].M);
	}

	void Run() {
		InputStream inStream = System.in;

		try {
	//	 inStream = new FileInputStream(
	//			 "C:\\Test\\Test.txt");
		Reader reader = new BufferedReader(new InputStreamReader(inStream));
		StreamTokenizer st = new StreamTokenizer(reader);

			st.nextToken();
			int T = (int)st.nval;
			
			for (int i = 0; i < T; i++)
			{
				if (i > 0)
					System.out.println();
				
				st.nextToken();
				int D = (int)st.nval;
				
				Car[] cars = new Car[D];
				for (int j = 0; j < D; j++)
				{
					st.nextToken();
					String M = st.sval;
					st.nextToken();
					int L = (int) st.nval;
					st.nextToken();
					int H = (int) st.nval;
					
					cars[j] = new Car(M, L, H);
				}
				
				st.nextToken();
				int Q = (int) st.nval;
				
				for (int j = 0; j < Q; j++)
				{
					st.nextToken();
					int P = (int) st.nval;
					
					Process(cars, P, D);
				}
				
			}
		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
