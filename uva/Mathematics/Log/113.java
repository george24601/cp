import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

/* UVA 113 power of cryptography 
 * bigdecimal
 */

class Main {
	int n;
	BigDecimal p;

	void Process(long lower, long upper)
	{
		long mid = (lower + upper)/2;
		
		BigDecimal test = new BigDecimal(mid);
		
		int comp = p.compareTo(test.pow(n));

		if (comp == 0)
			System.out.println(mid);
		else if (comp < 0)
			Process(lower, mid - 1);
		else
			Process(mid + 1, upper);
	}

	void Run() {
		InputStream inStream = System.in;

		/*
		try {
			inStream = new FileInputStream(
					"C:\\Users\\user\\PersonalCode\\Algorithms\\UVA\\113\\Test.txt");
		} catch (IOException e) {

		}
		*/

		Scanner s = new Scanner(inStream);

		while (s.hasNextLine()) {
			 n = Integer.parseInt(s.nextLine());
			
			 p = new BigDecimal(s.nextLine());
			
			Process(0, 1000000000);

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
