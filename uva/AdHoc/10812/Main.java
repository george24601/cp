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

/* UVA 10812 Beat the Spread!
 */
class Main {
	
	boolean IsValid(long s, long d)
	{
		long twoX = s + d;
		long twoY = s -d;

		if (twoX < 0 || twoX % 2 != 0)
			return false;

		if (twoY < 0 || twoY % 2 != 0)
			return false;


		//if (twoX == twoY)
		//	return false;

		return true;
	}

	void Run() {
		InputStream inStream = System.in;

		/*
		try {
			inStream = new FileInputStream(
					"D:\\PersonalCode\\Algorithms\\UVA\\10812\\Test.txt");
		} catch (Exception e) {

		}
		*/

		Scanner sc = new Scanner(inStream);

		StringTokenizer tokens = new StringTokenizer(sc.nextLine());

		int n = Integer.parseInt(tokens.nextToken());

		for( int i = 0; i < n; i++)
		{	

			StringTokenizer caseTokens = new StringTokenizer(sc.nextLine());

			long s = Long.parseLong(caseTokens.nextToken());
			long d = Long.parseLong(caseTokens.nextToken());

			long x = 0;
			long y = 0;
			if (IsValid(s, d))
			{
				x = (s + d)/2;
				y = (s - d) /2;

				if (x > y)
					System.out.println(String.format("%d %d", x, y));
				else
					System.out.println(String.format("%d %d", y, x));
			}else{
				System.out.println("impossible");
			}


		}

		sc.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
