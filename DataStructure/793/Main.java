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

/* UVA 793: network connections 
 * union find 
 */
class Main {

	class UnionFind 
	{
		ArrayList<Integer> _entries;
		ArrayList<Integer> _parents;
		public UnionFind()
		{
			_entries = new ArrayList<Integer>();
			_parents = new ArrayList<Integer>();
		}
		
		
		public void Union(int a, int b)
		{
			int aIndex = _entries.indexOf(a);
			int bIndex = _entries.indexOf(b);
			
			if (aIndex < 0 || bIndex < 0)
				return;
			
			_parents.set(FindInternal(aIndex), FindInternal(bIndex));
		}
		
		public void Add (int c)
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
				_parents.set(current, FindInternal(currentParent));//path compression
				current = currentParent;
				currentParent = _parents.get(current);
			}
			
			return currentParent;
		}

		public int Find(int c)
		{
			int cIndex = _entries.indexOf(c);
			int cParentIndex = FindInternal(cIndex);
			return _entries.get(cParentIndex);
		}
	}

	void Run() {
		InputStream inStream = System.in;

	/*	try {
			inStream = new FileInputStream(
					"D:\\PersonalCode\\Algorithms\\UVA\\793\\Test.txt");
		} catch (Exception e) {

		}
		*/
		

		Scanner s = new Scanner(inStream);
		int N = Integer.parseInt(s.nextLine());
		
		s.nextLine();

		for (int i = 0; i < N; i++)
		{
			int maxC = Integer.parseInt(s.nextLine());
			UnionFind uf = new UnionFind();
			
			for (int c = 1; c <= maxC; c++)
				uf.Add(c);
			
			int successful = 0;
			int unsuccessful = 0; 
			while(s.hasNextLine())
			{
				String line = s.nextLine();
				
				if (line.length() == 0)
					break;

				StringTokenizer tokens = new StringTokenizer(line);
				char action = tokens.nextToken().charAt(0);
				int a  = Integer.parseInt(tokens.nextToken());
				int b  = Integer.parseInt(tokens.nextToken());
				
				if (action == 'c')
				{
					uf.Union(a, b);
				}else
				{
					if (uf.Find(a) == uf.Find(b))
						successful ++;
					else
						unsuccessful++;
				}
			}
			
			if (i > 0)
				System.out.println();

			System.out.println(String.format("%d,%d", successful, unsuccessful));
		}

		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
