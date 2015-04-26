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

/* UVA 11001 Necklace
 * complete search
 */

class Main {

	long calcN(long n, long vtotal, long v0)
	{
		return vtotal * n - v0 * n * n;
	}
	
	void Process(long vtotal, long v0)
	{
		long candidate = vtotal / (2* v0);
		
		if (vtotal % (2* v0) == 0)
		{
			System.out.println(candidate);
			return;
		}
		
		long val1 = calcN(candidate, vtotal, v0); 
		long val2 = calcN(candidate + 1, vtotal, v0);
		
		if (val1 == val2)
			System.out.println(0);
		else if (val1 > val2)
			System.out.println(candidate);
		else
			System.out.println(candidate + 1);
	}
	
	void Run() {
		InputStream inStream = System.in;

		try {
		// inStream = new FileInputStream(
		//		 "C:\\Test\\Test.txt");
		Reader reader = new BufferedReader(new InputStreamReader(inStream));
		StreamTokenizer st = new StreamTokenizer(reader);

		while(true)
		{
			st.nextToken();
			long vtotal = (long) st.nval;
			st.nextToken();
			long v0 = (long) st.nval;
			
			if (vtotal == 0 && v0 == 0)
				break;
			
			Process(vtotal, v0);
		}
		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
