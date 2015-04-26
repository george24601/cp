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

/* UVA 11616 Roman Numerals
 */
class Main {
	
	final char I = 'I';
	final int IVal = 1;
	final char V = 'V';
	final int VVal = 5;
	final char X = 'X';
	final int XVal = 10;
	final char L = 'L';
	final int LVal = 50;
	final char C = 'C';
	final int CVal = 100;
	final char D = 'D';
	final int DVal = 500;
	final char M = 'M';
	final int MVal = 1000;

	void ValToLetter_r(int i)
	{
		if (i == 0)
		{
			System.out.println();
		}else if (i >= 1000)
		{
			System.out.print(M);
			ValToLetter_r(i - MVal);
		}else if (i >= 900)
		{
			System.out.print(C);
			System.out.print(M);

			ValToLetter_r(i - MVal + CVal);
		}else if (i >= 500)
		{
			System.out.print(D);
			ValToLetter_r(i - DVal);
		}else if (i >= 400)
		{
			System.out.print(C);
			System.out.print(D);
			ValToLetter_r(i - DVal + CVal);
		}else if (i >= 100)
		{
			System.out.print(C);
			ValToLetter_r(i - CVal);
		}else if (i >= 90)
		{
			System.out.print(X);
			System.out.print(C);
			ValToLetter_r(i - CVal + XVal);
		}else if(i >= 50)
		{
			System.out.print(L);
			ValToLetter_r(i - LVal);
		}else if (i >= 40)
		{
			System.out.print(X);
			System.out.print(L);
			ValToLetter_r(i - LVal + XVal);
		}else if (i >= 5)
		{
			System.out.print(V);
			ValToLetter_r(i - VVal);
		}else if (i >= 4)
		{
			System.out.print(I);
			System.out.print(V);
			ValToLetter_r(i - VVal + IVal);
		}else if (i >= 1)
		{
			System.out.print(I);
			ValToLetter_r(i - IVal);
		}
	}
	
	int Val(char c)
	{
		if (c == M)
			return MVal;
		if (c == D)
			return DVal;
		if (c == C)
			return CVal;
		if (c == L)
			return LVal;
		if (c == X)
			return XVal;
		if (c == V)
			return VVal;
		if (c == I)
			return IVal;
		
		return 0;
	}

	void LetterToValue_r(String line, int index, int sum)
	{
		if (index == line.length())
		{
			System.out.println(sum);
			return;
		}
		
		char curChar = line.charAt(index);
		
		if (index == line.length() -1)
		{
			LetterToValue_r(line, index + 1, sum + Val(curChar));
		}else if (curChar == M || curChar == D || curChar == L || curChar == V)
		{
			LetterToValue_r(line, index + 1, sum + Val(curChar));
		}else if (curChar == C || curChar == X || curChar == I)
		{
			char nextChar = line.charAt(index + 1);
			
			if (Val(curChar) < Val(nextChar))
				LetterToValue_r(line, index + 2, sum -  Val(curChar) + Val(nextChar));
			else
				LetterToValue_r(line, index + 1, sum + Val(curChar));
		}
	}

	void Run() {
		InputStream inStream = System.in;

		/*
		 try { inStream = new FileInputStream(
		  "D:\\PersonalCode\\Algorithms\\UVA\\11616\\Test.txt"); } catch
		  (Exception e) {
		  
		  }
		*/

		Scanner s = new Scanner(inStream);

		while(s.hasNextLine())
		{
			String line = s.nextLine();
			
			if (line.charAt(0) >= '0' && line.charAt(0) <= '9')
				ValToLetter_r(Integer.parseInt(line));
			else
				LetterToValue_r(line, 0, 0);
		}

		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
