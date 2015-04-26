import java.io.FileInputStream;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.StringTokenizer;

/* UVA 10363 tic tac toe  
 */
class Main {

	final int Size = 3;
	final char X = 'X';
	final char O = 'O';
	final char Dot = '.';

	boolean IsValid(char[][] game) {
		int numX = 0;
		int numO = 0;
		int numDot = 0;

		//only one wins
		char lastWinner = Dot;

		for (int i = 0; i < Size; i++) {
			for (int j = 0; j < Size; j++) {
				char curChar = game[i][j];
				if (curChar == X)
					numX++;
				else if (curChar == O)
					numO++;
				else if (curChar == Dot)
					numDot++;
			}

			if (game[i][0] == game[i][1] && game[i][1] == game[i][2] && 
					(game[i][0] == X||game[i][0] == O)){

				char firstInRow =  game[i][0];
				if (lastWinner == Dot)
					lastWinner = firstInRow;
				else if (lastWinner != firstInRow)
					return false;

			}

			if (game[0][i] == game[1][i] && game[1][i] == game[2][i] && 
					(game[0][i] == X||game[0][i] == O)) {

				char firstInCol =  game[0][i];
				if (lastWinner == Dot)
					lastWinner = firstInCol;
				else if (lastWinner != firstInCol)
					return false;

			}
		}
		
		if ((game[0][0] == game[1][1] && game[1][1] == game[2][2])
			 ||(game[0][2] == game[1][1] && game[1][1] == game[2][0]))
		{
				char firstInCol =  game[1][1];
				if (lastWinner == Dot)
					lastWinner = firstInCol;
				else if (lastWinner != firstInCol)
					return false;
			
		}

		boolean validInput = numX + numO + numDot == 9;
		boolean correctOXNum = numO + 1 >= numX && numX >= numO;

		 if (!(validInput && correctOXNum))
			 return false;
		 
		 if (lastWinner == X)
			 return numX == numO + 1;
		 else if (lastWinner == O)
			 return numX == numO;
		 
		 return true;
	}

	void Run() {
		InputStream inStream = System.in;

		/*
		try {
			inStream = new FileInputStream(
					"D:\\PersonalCode\\Algorithms\\UVA\\10363\\Test.txt");
		} catch (Exception e) {

		}
		*/

		Scanner s = new Scanner(inStream);

		StringTokenizer firstLine = new StringTokenizer(s.nextLine());
		int numCases = Integer.parseInt(firstLine.nextToken());

		for (int i = 0; i < numCases; i++) {
			if (i > 0)
				s.nextLine(); // blank line

			char[][] game = new char[Size][Size];

			for (int j = 0; j < Size; j++) {
				String row = s.nextLine();

				for (int k = 0; k < Size; k++)
					game[j][k] = row.charAt(k);
			}

			boolean isValid = IsValid(game);

			if (isValid)
				System.out.println("yes");
			else
				System.out.println("no");

		}

		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
