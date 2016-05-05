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

/* UVA 617 Nonstop Travel
 * ad hoc
 */

class Main {

	double[] Ls;
	int[] Gs;
	int[] Ys;
	int[] Rs;
	int N;

	boolean Valid(int speed) {
		
		for (int i = 0; i < N; i++)
		{
			int cycleLength = Gs[i] + Ys[i] + Rs[i];
			
			double arrivalSecDouble = Ls[i]/speed;
			int arrivalSecInt = (int) arrivalSecDouble;
			
			int secInCycle = arrivalSecInt % cycleLength;
			
			if (secInCycle >= Gs[i] + Ys[i])
				return false;
		}
		
		return true;
	}

	void Process(ArrayList<Integer> validSpeeds) {
		
		int start = validSpeeds.get(0);
		int end = validSpeeds.get(0);
		
		for (int i = 1; i < validSpeeds.size() - 1; i++)
		{
			int currentVal =validSpeeds.get(i);  
			if (currentVal > end + 1)
			{
				if (start == end)
					System.out.print(String.format("%d, ",end));
				else
					System.out.print(String.format("%d-%d, ", start, end));
				
				start = currentVal;
			}
			
			end = currentVal;
		}
		
		int lastVal = validSpeeds.get(validSpeeds.size() - 1);
		
		if (lastVal == end + 1)
		{	
			System.out.println(String.format("%d-%d", start, lastVal));
		}
		else
		{
			if (start == end)
				System.out.print(String.format("%d, ",end));
			else
				System.out.print(String.format("%d-%d, ", start, end));
			
			System.out.println(String.format("%d", lastVal));
		}

	}

	void Run() {
		InputStream inStream = System.in;

		try {
			//inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			int caseCount = 0;
			while (true) {
				st.nextToken();
				N = (int) st.nval;

				if (N < 0)
					break;

				caseCount++;

				Ls = new double[N];
				Gs = new int[N];
				Ys = new int[N];
				Rs = new int[N];
				
				for (int i = 0; i < N; i++)
				{
					st.nextToken();
					Ls[i] = ((double) st.nval) * 3600;
					
					st.nextToken();
					Gs[i] = (int) st.nval;
					
					st.nextToken();
					Ys[i] = (int) st.nval;
					
					st.nextToken();
					Rs[i] = (int) st.nval;
				}

				ArrayList<Integer> validSpeeds = new ArrayList<Integer>();
				for (int speed = 30; speed <= 60; speed++) {
					if (Valid(speed))
						validSpeeds.add(speed);
				}

				System.out.print(String.format("Case %d: ", caseCount));

				if (validSpeeds.size() == 0)
					System.out.println("No acceptable speeds.");
				else
					Process(validSpeeds);

			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
