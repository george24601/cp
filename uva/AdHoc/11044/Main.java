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

/* UVA 11044 Searching for Nessy
 */
class Main {

	
	void Run() {
		InputStream inStream = System.in;

		/*
		try {
			inStream = new FileInputStream(
					"D:\\PersonalCode\\Algorithms\\UVA\\11044\\Test.txt");
		} catch (Exception e) {

		}
		*/

		Scanner s = new Scanner(inStream);

		StringTokenizer tokens = new StringTokenizer(s.nextLine());
		int t = Integer.parseInt(tokens.nextToken());


		for (int i = 0; i < t; i++)
		{
			tokens = new StringTokenizer(s.nextLine());
			int n = Integer.parseInt(tokens.nextToken());
			int m = Integer.parseInt(tokens.nextToken());

			int totalNumber = (n/3) * (m /3);
			System.out.println(totalNumber);
		}

		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
