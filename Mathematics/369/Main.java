import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.math.BigDecimal;
import java.util.Scanner;

/* UVA 369 Combinations
 * bigdecimal
 */

class Main {

	BigDecimal Calc(int n, int m)
	{
		
		BigDecimal below = new BigDecimal(1);
		
		for (int i  = m; i  > 1; i --)
			below = below.multiply(new BigDecimal(i));

		BigDecimal up = new BigDecimal(1);
		
		for (int i =  n; i >= n -m + 1; i--)
			up = up.multiply(new BigDecimal(i));

		return up.divide(below);
	}

	void Run() {
		InputStream inStream = System.in;

		/*
		try {
			inStream = new FileInputStream(
					"C:\\Users\\user\\PersonalCode\\Algorithms\\UVA\\369\\Test.txt");
		} catch (IOException e) {

		}
		*/

		Scanner s = new Scanner(inStream);
		while(true)
		{
			int n = s.nextInt();
			int m = s.nextInt();
			
			if ( n == 0 && m == 0)
				break;
			
			BigDecimal c = n > 2 * m ? Calc(n, m) : Calc(n , n - m);
			System.out.println(String.format("%d things taken %d at a time is %s exactly.", n, m, c.toString()));
		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
