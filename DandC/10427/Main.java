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
import java.util.Scanner;

/* UVA 10427 Naughty Sleepy Boys
 *binary search
 */

class Main {

	int SingleSeqLength(int k)
	{
		int total = 0;
		int comp = 1;
		int charLength = 1;
		while (true) {
			int nextComp = comp * 10;

			if (nextComp <= k) {
				total +=   comp * 9 * charLength;
			} else {
				total += (k - comp + 1) * charLength;
				break;
			}

			comp = nextComp;
			charLength++;
		}

		return total;	
	}
	
	int ResolveSingle_r(int low, int high, int pos)
	{
		int mid = (low + high) /2;
		
		int midLength =  SingleSeqLength(mid);
		int curSeg = (new Integer(mid)).toString().length();
		
		if (pos <= midLength - curSeg)
		{
			return ResolveSingle_r(low, mid -1, pos);
			
		}else if(midLength - curSeg < pos && pos <= midLength)
		{
			int digit =   pos - midLength + curSeg;
			return (new Integer(mid)).toString().charAt(digit -1) - '0';
		}else
		{
			return ResolveSingle_r(mid +1, high, pos);
		}
	}
	

	void Run() {
		InputStream inStream = System.in;

		try {
		//	inStream = new FileInputStream(
		//			"C:\\Users\\IBM_ADMIN\\PersonalCode\\Algorithms\\UVA\\10427\\Test.txt");

			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			while(st.nextToken() != st.TT_EOF)
			{
				int pos = (int) st.nval;

				System.out.println(ResolveSingle_r(1, 100000000, pos));
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
