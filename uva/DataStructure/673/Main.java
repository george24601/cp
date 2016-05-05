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
import java.util.Stack;
import java.util.StringTokenizer;

/* UVA 673: parentheses balance
 */
class Main {

	boolean Process_r(Stack<Character> chars, String line, int curIndex) {
		if (curIndex == line.length())
			return chars.size() == 0;

		char curChar = line.charAt(curIndex);

		if (curChar == '[' || curChar == '(') {
			chars.push(curChar);
			return Process_r(chars, line, curIndex + 1);
		} else if (curChar == ']') {
			if (chars.size() > 0 && chars.peek() == '[') {
				chars.pop();
				return Process_r(chars, line, curIndex + 1);
			} else {
				return false;
			}

		} else if (curChar == ')') {
			if (chars.size() > 0 && chars.peek() == '(') {
				chars.pop();
				return Process_r(chars, line, curIndex + 1);
			} else {
				return false;
			}

		}

		return false;
	}

	void Run() {
		InputStream inStream = System.in;

		/*
		try {
			inStream = new FileInputStream(
					"D:\\PersonalCode\\Algorithms\\UVA\\673\\Test.txt");
		} catch (Exception e) {

		}
		*/

		Scanner s = new Scanner(inStream);

		int n = Integer.parseInt(s.nextLine());

		for (int i = 0; i < n; i++) {
			String line = s.nextLine();
			Stack<Character> chars = new Stack<Character>();

			if (Process_r(chars, line, 0))
				System.out.println("Yes");
			else
				System.out.println("No");
		}

		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
