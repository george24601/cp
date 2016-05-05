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
import java.util.Scanner;

/* UVA 167 The Sultan's Successors
 * complete search
 */

class Main {
	int[][] board;
	int[] queens;
	int currentMax;
	int Dim = 8;
	
	int Calc()
	{
		int result = 0;
		
		for (int i = 0; i < Dim; i++)
			result += board[queens[i]][i];
		
		return result;
			
	}
	
	boolean Valid(int col, int row)
	{
		for (int i = 0; i < col; i++)
		{
			int queenRow = queens[i];
			
			if (queenRow == row)
				return false;
			
			if (Math.abs(queenRow - row) == Math.abs(i - col))
				return false;
		}
		
		return true;
	}
	
	void Process_r(int currentCol)
	{
		for (int i = 0; i < Dim; i++)
		{
			if(Valid(currentCol, i))
			{
				queens[currentCol] = i;
				
				if (currentCol == Dim - 1)
				{
					int val = Calc();
					
					if (currentMax < val)
						currentMax = val;
					
				}else
				{
					Process_r(currentCol+1);
				}
			}else
			{
				continue;
			}
		}
		
	}

	void Run() {
		InputStream inStream = System.in;

		try {
			// inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			st.nextToken();
			int k = (int) st.nval;

			for (int i = 0; i < k; i++) {
				currentMax = 0;
				board = new int[Dim][Dim];
				queens = new int[Dim];
				for (int j = 0; j < Dim; j++) {
					for (int l = 0; l < Dim; l++) {
						st.nextToken();
						board[j][l] = (int) st.nval;
					}
				}

				Process_r(0);
				
				for (int m = 0; m < 5 - Integer.toString(currentMax).length(); m++)
					System.out.print(' ');
				
				System.out.println(currentMax);

			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
