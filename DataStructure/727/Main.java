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

/* UVA 727: equation
 */
class Main {

	int GetPriority (char c) 
	{
		if (c == '+'  || c == '-')
			return 1;
		if (c == '*'  || c == '/')
			return 2;

		if (c == ')')
			return 0;

		if (c == '(' )
			return -1;
		
		return -1000;
	}

	boolean IsOperator(char c)
	{
		return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
	}

	void Process_r(Stack<Character> operators, List<Character> inputs,
			int curIndex) {
		if (curIndex >= inputs.size()) {
			// when we read the end of input, pop until the stack is empty;
			while(!operators.isEmpty())
				System.out.print(operators.pop());

			return;
		}

		char currentInput = inputs.get(curIndex);

		if (currentInput == '(')
		{
			operators.push(currentInput);
		}else if (currentInput == ')')
		{
			while (!operators.isEmpty() && operators.peek() != '(')
			{
				char operator = operators.pop();
				
				System.out.print(operator);
			}
			
			operators.pop();
			
		}else if (IsOperator(currentInput)) {
			
		// when an operator is read
		// pop until the top of the satch has an elemetn of lower preciende
			while (!operators.isEmpty() && GetPriority(currentInput) <= GetPriority(operators.peek()))
			{
				char operator = operators.pop();
				
				System.out.print(operator);
			}
			
			operators.push(currentInput);

		} else {
			// when an operand is read, output it
			System.out.print(currentInput);
		
		}

		// when ) is found, pop until we find the macthing (
		// ( has lowest precensdne when in the stack, but has thehightest
		// predence when i the input
		Process_r(operators, inputs, curIndex + 1);
	}

	void Run() {
		InputStream inStream = System.in;

		/*
		  try { inStream = new FileInputStream(
				  "D:\\PersonalCode\\Algorithms\\UVA\\FailedToSolve\\727\\Test.txt"); } catch
		  (Exception e) {
		  
		  }
		  */
		  
		  
		 

		Scanner s = new Scanner(inStream);

		int n = Integer.parseInt(s.nextLine());

		for (int i = 0; i < n; i++) {
			List<Character> input = new ArrayList<Character>();

			if (i == 0)
				s.nextLine();

			while (s.hasNextLine()) {
				String line = s.nextLine();
				if (line.length() == 0)
					break;
				else
					input.add(line.charAt(0));
			}

			Stack<Character> operators = new Stack<Character>();
			Process_r(operators, input, 0);
			System.out.println();

			if (i < n - 1)
				System.out.println();
		}

		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
