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

/* UVA 11078 Open Credit System 
 * complete search
 */

class Main {

	void Process(int[] nums, int n)
	{
		int maxSenior = nums[0];
		int maxDiff = Integer.MIN_VALUE;
		
		for (int i = 1; i < n; i++)
		{
			int curStu = nums[i];
			
			int curDiff = maxSenior - curStu;
			
			if (curDiff > maxDiff)
				maxDiff = curDiff;
			
			if (maxSenior < curStu)
				maxSenior = curStu;
		}
		
		System.out.println(maxDiff);
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
				st.nextToken();
				int n = (int)st.nval;
				
				int[] nums = new int[n];
				for (int j = 0; j < n; j++)
				{
					st.nextToken();
					nums[j] = (int)st.nval;
				}
				
				Process(nums, n);
				
			}
		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
