import java.io.FileInputStream;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Collections;
import java.util.Comparator;
import java.util.Dictionary;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;
import java.util.SortedMap;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;

/* UVA 459:  Graph connectivity
 * union find 
 */
class Main {

	class UnionFind 
	{
		ArrayList<Character> _entries;
		ArrayList<Integer> _parents;
		public UnionFind()
		{
			_entries = new ArrayList<Character>();
			_parents = new ArrayList<Integer>();
		}
		
		
		public void Union(char a, char b)
		{
			int aIndex = _entries.indexOf(a);
			int bIndex = _entries.indexOf(b);
			
			if (aIndex < 0 || bIndex < 0)
				return;
			
			_parents.set(FindInternal(aIndex), FindInternal(bIndex));
		}
		
		public void Add (char c)
		{
			int newIndex = _parents.size();
			_entries.add(c);
			_parents.add(newIndex);
		}

		int FindInternal(int index)
		{
			int current = index;
			int currentParent = _parents.get(current);

			while(currentParent != current)
			{
				_parents.set(current, FindInternal(currentParent));
				current = currentParent;
				currentParent = _parents.get(current);
			}
			
			return currentParent;
		}

		public char Find(char c)
		{
			int cIndex = _entries.indexOf(c);
			int cParentIndex = FindInternal(cIndex);
			return _entries.get(cParentIndex);
		}
	}

	void Run() {
		InputStream inStream = System.in;

		/*
		try {
			inStream = new FileInputStream(
					"D:\\PersonalCode\\Algorithms\\UVA\\459\\Test.txt");
		} catch (Exception e) {

		}
		*/
		

		Scanner s = new Scanner(inStream);
		int N = Integer.parseInt(s.nextLine());
		
		s.nextLine();

		for (int i = 0; i < N; i++)
		{
			char maxC = s.nextLine().charAt(0);
			UnionFind uf = new UnionFind();
			
			for (char c = 'A'; c <= maxC; c++)
				uf.Add(c);
			
			while(s.hasNextLine())
			{
				String line = s.nextLine();
				
				if (line.length() == 0)
					break;
				
				uf.Union(line.charAt(0), line.charAt(1));
			}
			HashSet<Character> distinctSets = new HashSet<Character>();

			for (char c = 'A'; c <= maxC; c++)
				distinctSets.add(uf.Find(c));
			
			if (i > 0)
				System.out.println();
			
			System.out.println(distinctSets.size());
			
		}

		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
