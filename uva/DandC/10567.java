import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Dictionary;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

/* UVA 10567 Helping Fill Bates

 * binary search
 */

class Main {

	HashMap<Character, ArrayList<Integer>> sequences;
	String SS;
	
	int first;
	int last;
	
	boolean Process()
	{
		int lastIndex = -1;
		for (int i = 0; i < SS.length(); i++)
		{
			char toCheck = SS.charAt(i);
			
			ArrayList<Integer> toSearch = sequences.get(toCheck);
			
			int candidate = Collections.binarySearch(toSearch, lastIndex + 1);
			
			if (candidate >= 0)
			{
				lastIndex = toSearch.get(candidate);
			}
			else
			{
				int insertionPoint = -1 - candidate;
				
				if (insertionPoint == toSearch.size())
					return false;
				else
					lastIndex = toSearch.get(insertionPoint);
			}
			
			if (i == 0)
				first = lastIndex;
			else if (i == SS.length() - 1)
				last = lastIndex;
				
		}
		
		return true;
	}

	void Run() {
		InputStream inStream = System.in;

		try {
			//inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			
			sequences = new HashMap<Character, ArrayList<Integer>>();
			
			for (char key = 'a'; key <='z'; key++)
				sequences.put(key, new ArrayList<Integer>());
			
			for (char key = 'A'; key <='Z'; key++)
				sequences.put(key, new ArrayList<Integer>());
			
			st.nextToken();
			String s = (String) st.sval;
			for (int i = 0; i < s.length(); i++)
				sequences.get(s.charAt(i)).add(i);
			
			st.nextToken();
			int Q = (int)st.nval;
			
			for(int i = 0; i < Q; i++)
			{
				st.nextToken();
				
				SS = (String)st.sval;
				boolean result = Process();
				
				if(result)
					System.out.println(String.format("Matched %d %d", first, last));
				else
					System.out.println("Not matched");
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
