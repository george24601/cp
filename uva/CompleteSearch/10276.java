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

/* UVA 10276 Hanoi Tower Troubles Again!
 * (smart) complete search
 */

class Main {

	int N;
	int[] pegs;
	int curNum;
	int maxNum;
	
	boolean IsSquare(int num)
	{
		int root = (int)Math.sqrt(num);
		return (root * root) == num;
	}
	
	void TryPlace_r(int curNum, int usedPegs)
	{
		for (int i = 0; i < usedPegs; i++)
		{
			if (IsSquare(pegs[i] + curNum))
			{
				if (maxNum < curNum)
					maxNum = curNum;
				
				int prevVal = pegs[i];
				pegs[i] = curNum;
				TryPlace_r(curNum + 1, usedPegs);
				pegs[i] = prevVal;
				return;
			}
		}
		
		if (usedPegs < N)
		{
			int prevVal = pegs[usedPegs];
			pegs[usedPegs] = curNum;
			
			if (maxNum < curNum)
				maxNum = curNum;
			
			TryPlace_r(curNum + 1, usedPegs+1);
			pegs[usedPegs] = prevVal;
		}
	}
	
	
	void Run() {
		InputStream inStream = System.in;

		try {
		//	inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			st.nextToken();
			int T = (int)st.nval;
			
			for (int i = 0; i < T; i++)
			{
				st.nextToken();
				N = (int)st.nval;
				pegs = new int[N];
				maxNum = 0;
				TryPlace_r(1, 0);
				System.out.println(maxNum);
			}
			

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
