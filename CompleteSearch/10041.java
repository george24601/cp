import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/* UVA 10041 vito's family 
 * simple complete search 
 */
class Main {

	long Process(int[] nums) {
		
		long min = Long.MAX_VALUE;
		for (int i = 0; i < nums.length; i++)
		{
			long total  = 0;
			for (int j = 0; j < nums.length; j++)
			{
				if (nums[i] > nums[j])
					total += (nums[i] - nums[j]);
				else
					total += (nums[j] - nums[i]);
			}
			
			if (total < min)
				min = total;
		}
		
		return min;
	}

	void Run() {
		InputStream inStream = System.in;

		/*
		try {
			inStream = new FileInputStream(
					"D:\\PersonalCode\\Algorithms\\UVA\\10041\\Test.txt");
		} catch (Exception e) {
		}
		*/

		try {
			Reader r = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer s = new StreamTokenizer(r);

			s.nextToken();

			int numCases = (int) s.nval;

			for (int i = 0; i < numCases; i++) {
				s.nextToken();
				int rn = (int)s.nval;
				
				int[] nums = new int[rn];
				
				for (int j =0; j < rn; j ++)
				{
					s.nextToken();
					nums[j] = (int)s.nval;
				}

				System.out.println(Process(nums));
			}
		} catch (IOException e) {
				
		}
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
