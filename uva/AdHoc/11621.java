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
import java.util.Dictionary;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

/* UVA 11621 Small Factors

 * binary search
 */

class Main {

	long m;
	
	long Process()
	{
		long pow3 = 1;
		long n = Long.MAX_VALUE;
		
		for (int i = 0; i <=31; i++)
		{
			if (pow3 >= n)
				break;
			long pow2 = 1;
			
			for (int j = 0; j <= 31; j++ )
			{
				long candidate = pow3 * pow2;
				
				if (candidate >= n)
					break;
				else if (candidate >= m)
				{
					n =  candidate;
					break;
				}else
				{
					pow2 *= 2;
				}
			}
			
			pow3 *= 3;
		}
		
		return n;
	}
	
	void Run() {
		InputStream inStream = System.in;

		try {
			//inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			while (st.nextToken() != st.TT_EOF)
			{
				m = (long) st.nval;
				if (m == 0)
					break;
				
				long next = Process();
				
				System.out.println(next);
				
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
