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
		Map<Integer, Integer> _entries;
		ArrayList<Integer> _strings;
		ArrayList<Integer> _parents;
		ArrayList<Integer> _rootSizes;

		public UnionFind() {
			_entries = new HashMap<Integer, Integer>();
			_strings = new ArrayList<Integer>();
			_parents = new ArrayList<Integer>();
			_rootSizes = new ArrayList<Integer>();
		}

		public void Union(int a, int b) {
			int aIndex = _entries.get(a);
			int bIndex = _entries.get(b);

			if (aIndex < 0 || bIndex < 0)
				return;

			int rootA = FindInternal(aIndex);
			int rootB = FindInternal(bIndex);
			
			if (rootA == rootB)
				return; //already unioned, nothing to be done
			
			_parents.set(rootA, rootB);

			int newRootSize = _rootSizes.get(rootA) + _rootSizes.get(rootB);

			_rootSizes.set(rootA, newRootSize);
			_rootSizes.set(rootB, newRootSize);
		}

		public void Add(int c) {

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
				_parents.set(current, FindInternal(currentParent));// path
																	// compression
				current = currentParent;
				currentParent = _parents.get(current);
			}

			return currentParent;
		}

		public int Find(int c) {
			int cIndex = _entries.get(c);
			int cParentIndex = FindInternal(cIndex);
			return _strings.get(cParentIndex);
		}

		public int GetRootSize(int key) {
			int cIndex = _entries.get(key);
			int cParentIndex = FindInternal(cIndex);
			return _rootSizes.get(cParentIndex);
		}
	}

	void Run() {
		InputStream inStream = System.in;
/*
		  try { inStream = new FileInputStream(
		  "D:\\PersonalCode\\Algorithms\\UVA\\10608\\Test2.txt"); } catch
		  (Exception e) {
		  }
		  */

		Scanner s = new Scanner(inStream);
		int t = Integer.parseInt(s.nextLine());

		for (int i = 0; i < t; i++) {
			StringTokenizer tokens = new StringTokenizer(s.nextLine());

			UnionFind friends = new UnionFind();
			int N = Integer.parseInt(tokens.nextToken());
			int M = Integer.parseInt(tokens.nextToken());

			for (int j = 1; j <= N; j++)
				friends.Add(j);

			for (int j = 0; j < M; j++) {
				tokens = new StringTokenizer(s.nextLine());
				int a = Integer.parseInt(tokens.nextToken());
				int b = Integer.parseInt(tokens.nextToken());
				friends.Union(a, b);
			}
			
			int max = 0;
			
			for (int j = 1; j <= N; j++)
			{
				int current = friends.GetRootSize(j);
				
				if (current > max)
					max = current;
			}
			
			System.out.println(max);

		}

		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
