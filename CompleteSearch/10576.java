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

/* UVA 10576 Y2K Accounting Bug
 * complete search
 */

class Main {

	long s;
	long d;
	long [] months;
	int Size= 12;
	int Gap = 5;
	long maxBalance;
	
	void Process_r(int month, long balance, long prev5Balance)
	{
		if (month < Gap)
		{
			months[month - 1] = s;
			Process_r(month + 1, balance + s, 0);
			
			months[month - 1] = -d;
			Process_r(month + 1, balance - d, 0);
			return;
		}else if (month <= 12)
		{
			long newBalance = balance + s;
			if (newBalance - prev5Balance < 0)
			{
				months[month - 1] = s;
				
				if (month < 12)
				{
					Process_r(month + 1, newBalance, prev5Balance + months[month - Gap]);
				}else
				{
					if (maxBalance < balance + s)
						maxBalance = balance + s;
				}
			}
			
			newBalance = balance - d;
			if (newBalance - prev5Balance < 0)
			{
				months[month - 1] =  -d;
				
				if (month < 12)
				{
					Process_r(month + 1, newBalance, prev5Balance + months[month - Gap]);
				}else
				{
					if (maxBalance < newBalance)
						maxBalance = newBalance;
				}
			}
		}
	}
	
	void Run() {
		InputStream inStream = System.in;

		try {
			//inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			while (st.nextToken() != st.TT_EOF)
			{
				s = (long)st.nval;
				
				st.nextToken();
				d = (long)st.nval;
				months = new long[12];
				maxBalance = Integer.MIN_VALUE;
				
				Process_r(1, 0, 0);
				
				if (maxBalance >= 0)
					System.out.println(maxBalance);
				else
					System.out.println("Deficit");
			}
			

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
