import java.io.FileInputStream;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;

/* UVA 10703 free spots
 */
class Main {
	void Process(int W, int H, int N, int[] x1s, int[] y1s, int[] x2s, int[] y2s)
	{
		boolean[][] board = new boolean [H] [W];

		for (int i = 0; i < N; i++)
		{
			for (int j = x1s[i] -1; j <= x2s[i] -1; j++)
			{
				for (int k = y1s[i] -1; k <= y2s[i] -1; k++)
					board[k][j] = true;
			}
		}

		int count = 0;
		
		for (int i  = 0; i < H; i++)
		{
			for(int j = 0; j < W; j++)
			{
				if (!board[i][j])
					count++;
			}
		}


		if (count == 0)
			System.out.println("There is no empty spots.");
		else if (count == 1)
			System.out.println("There is one empty spot.");
		else
			System.out.println(String.format("There are %d empty spots.", count));
	}
	
	void Run() {
		InputStream inStream = System.in;

		/*
		try {
			inStream = new FileInputStream(
					"D:\\PersonalCode\\Algorithms\\UVA\\10703\\Test.txt");
		} catch (Exception e) {

		}
		*/

		Scanner s = new Scanner(inStream);


		boolean isFirst = true;

		while(s.hasNextLine())
		{
			if (isFirst)
				isFirst = false;
			else
				s.nextLine(); //empty line

			StringTokenizer tokens = new StringTokenizer(s.nextLine());

			int W = Integer.parseInt(tokens.nextToken());
			int H = Integer.parseInt(tokens.nextToken());
			int N = Integer.parseInt(tokens.nextToken());

			if (W == 0 && H == 0)
				break;


			int [] x1s = new int[N];
			int [] y1s = new int[N];
			int [] x2s = new int[N];
			int [] y2s = new int[N];

			for (int i = 0; i < N; i++)
			{
				StringTokenizer posTokens = new StringTokenizer(s.nextLine());

				int x1 = Integer.parseInt(posTokens.nextToken());
				int y1 = Integer.parseInt(posTokens.nextToken());
				int x2 = Integer.parseInt(posTokens.nextToken());
				int y2 = Integer.parseInt(posTokens.nextToken());

				if (x1 > x2)
				{
					x1s[i] = x2;
					x2s[i] = x1;
				}else{
					x1s[i] = x1;
					x2s[i] = x2;
				}

				if (y1 > y2)
				{
					y1s[i] = y2;
					y2s[i] = y1;
				}else{
					y1s[i] = y1;
					y2s[i] = y2;
				}
			}

			Process(W, H, N, x1s, y1s, x2s, y2s);
		}

		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
