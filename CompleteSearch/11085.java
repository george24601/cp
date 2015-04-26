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

/* UVA 11085 Back to the 8-Queens
 * complete search
 */

class Main {
	
	int Size = 8;
	int[] start;
	int[] queens;
	int curMin;
	int counter;
	
	boolean IsValid(int row, int col)
	{
		for (int i = 0; i < col; i++)
		{
			if (queens[i] == row)
				return false;
			else if (Math.abs(queens[i] - row) == (col - i))
				return false;
		}
		
		return true;
	}
	
	void Process_r(int curCol)
	{
		if (curCol == Size)
		{
			counter++;
			int result = 0;
			for (int i = 0; i < Size; i++)
			{
				if(queens[i] != start[i])
					result++;
			}
			
			if (curMin > result)
				curMin = result;
			
		}else
		{
			for (int i = 0; i < Size; i++)
			{
				if (IsValid(i, curCol))
				{
					queens[curCol] = i;
					Process_r(curCol + 1);
				}else
				{
					continue;
				}
			}
		}
		
	}
	
	void Run() {
		InputStream inStream = System.in;

		try {
		//	 inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			int caseNum = 0;
			while(st.nextToken() != st.TT_EOF)
			{
				caseNum++;
				start = new int[Size];
				queens = new int[Size];
				curMin = Integer.MAX_VALUE;
				counter = 0;
				
				for (int i = 0; i < Size - 1; i++)
				{
					start[i] = (int)st.nval - 1;
					st.nextToken();
				}
				
				start[Size -1] = (int)st.nval - 1;
				
				Process_r(0);
				System.out.println(String.format("Case %d: %d", caseNum, curMin));
			//	System.out.println(counter);
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
