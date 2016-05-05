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

/* UVA 10018 reverse and add
 * simple ad hoc 
 */
class Main {

	boolean IsPalindrome(long num) {
		String str = new Long(num).toString();

		for (int i = 0; i < str.length() / 2; i++) {
			if (str.charAt(i) != str.charAt(str.length() - i - 1))
				return false;
		}

		return true;

	}

	long Reverse(long num) {
		String str = new Long(num).toString();
		String reversed = "";

		for (int i = 0; i < str.length(); i++)
			reversed += str.charAt(str.length() - i - 1);

		return Long.parseLong(reversed);
	}

	void Process(int val) {
		int count = 0;
		long current = val;

		while (!IsPalindrome(current)) {
			long reversed = Reverse(current);
			current = current + reversed;
			count++;
		}

		System.out.println(String.format("%d %d", count, current));
	}

	void Run() {
		InputStream inStream = System.in;

		/*
		try {
			inStream = new FileInputStream(
					"D:\\PersonalCode\\Algorithms\\UVA\\10018\\Test.txt");
		} catch (Exception e) {
		}
		*/

		try {
			Reader r = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer s = new StreamTokenizer(r);

			s.nextToken();

			int numCases = (int) s.nval;

			for (int i = 0; i < numCases; i++) {
				s.nextToken();
				Process((int) s.nval);
			}
		} catch (IOException e) {
				
		}
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
