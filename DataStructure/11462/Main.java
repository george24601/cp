import java.io.FileInputStream;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;

/* UVA 11462: age sort
 * couting sort problem
 */
class Main {

	final int Size = 99;

	void Run() {
		InputStream inStream = System.in;

		/*
		try {
			inStream = new FileInputStream(
					"D:\\PersonalCode\\Algorithms\\UVA\\11462\\Test.txt");
		} catch (Exception e) {

		}*/
		
		

		Scanner s = new Scanner(inStream);
		while (s.hasNextLine()) {
			
			int n = Integer.parseInt(s.nextLine());

			if (n == 0)
				break;
			
			int[] counts = new int[Size];

			for (int i = 0; i < n; i++)
			{
				int nextNum = s.nextInt();
				counts [nextNum - 1] += 1;
			}
			
			s.nextLine();
			
			boolean isFirst = true;
			for (int i = 0; i < Size; i++)
			{
				for (int j = 0; j < counts[i]; j++)
				{
					if (isFirst)
						isFirst = false;
					else
						System.out.print(' ');

					System.out.print(i + 1);
				}
			}
			
			System.out.println();

		}

		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
