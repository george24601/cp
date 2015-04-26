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

/* UVA 11503: war 
 * union find 
 */
class Main {

	class UnionFind {
		Map<String, Integer> _entries;
		ArrayList<String> _strings;
		ArrayList<Integer> _parents;
		ArrayList<Integer> _rootSizes;

		public UnionFind() {
			_entries = new HashMap<String, Integer>();
			_strings = new ArrayList<String>();
			_parents = new ArrayList<Integer>();
			_rootSizes = new ArrayList<Integer>();
		}

		public void Union(String a, String b) {
			int aIndex = _entries.get(a);
			int bIndex = _entries.get(b);

			if (aIndex < 0 || bIndex < 0)
				return;

			int rootA =FindInternal(aIndex);
			int rootB =FindInternal(bIndex);
			_parents.set(rootA, rootB);

			int newRootSize = _rootSizes.get(rootA) + _rootSizes.get(rootB);

			_rootSizes.set(rootA, newRootSize);
			_rootSizes.set(rootB, newRootSize);
		}

		public void Add(String c) {
			
			int newIndex = _parents.size();
			_entries.put(c, newIndex);
			_strings.add(c);
			_parents.add(newIndex);
			_rootSizes.add(1);
		}

		int FindInternal(int index) {
			int current = index;
			int currentParent = _parents.get(current);

			while (currentParent != current) {
				_parents.set(current, FindInternal(currentParent));// path compression
				current = currentParent;
				currentParent = _parents.get(current);
			}

			return currentParent;
		}

		public String Find(String c) {
			int cIndex = _entries.get(c);
			int cParentIndex = FindInternal(cIndex);
			return _strings.get(cParentIndex);
		}
		
		public int GetRootSize(String key)
		{
			int cIndex = _entries.get(key);
			int cParentIndex = FindInternal(cIndex);
			return _rootSizes.get(cParentIndex);
		}
	}

	void Run() {
		InputStream inStream = System.in;

		/*
		try {
			inStream = new FileInputStream(
					"D:\\PersonalCode\\Algorithms\\UVA\\11503\\Test4.txt");
		} catch (Exception e) {

		}
		*/

		Scanner s = new Scanner(inStream);
		int n = Integer.parseInt(s.nextLine());

		for (int i = 0; i < n; i++)
		{
			int numLines = Integer.parseInt(s.nextLine());
			UnionFind friends = new UnionFind();
			
			HashSet<String> allPeople = new HashSet<String>();
			for (int j =0; j < numLines; j++)
			{
				StringTokenizer tokens = new StringTokenizer(s.nextLine());
				
				String a = tokens.nextToken();
				
				if (!allPeople.contains(a))
				{
					friends.Add(a);
					allPeople.add(a);
				}

				String rootA = friends.Find(a);
				String b = tokens.nextToken();

				if (!allPeople.contains(b))
				{
					friends.Add(b);
					allPeople.add(b);
				}

				String rootB = friends.Find(b);
				
				if (rootA.equals(rootB))
				{
					System.out.println(friends.GetRootSize(rootA));
				}
				else
				{
					System.out.println(friends.GetRootSize(rootA) + friends.GetRootSize(rootB));
					friends.Union(rootA, rootB);
				}
			}
		}


		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
