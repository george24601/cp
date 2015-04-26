import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.StringTokenizer;

/* UVA 10583: Ubiquitous Religions 
 * union find 
 * java scanner is too slow for the input size
 * need to use cpp instead
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
				return; // already unioned, nothing to be done

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

		
		  try { inStream = new FileInputStream(
		  "D:\\PersonalCode\\Algorithms\\UVA\\10583\\Test.txt"); } catch
		  (Exception e) { }
		 

		Reader r = new BufferedReader(new InputStreamReader(inStream));
		StreamTokenizer s = new StreamTokenizer(r);

		try {
			int count = 0;
			while (true) {

				UnionFind friends = new UnionFind();
				s.nextToken();
				int N = (int) s.nval;
				s.nextToken();
				int M = (int) s.nval;

				if (N == 0 && M == 0)
					break;

				count++;
				for (int j = 1; j <= N; j++)
					friends.Add(j);

				for (int j = 0; j < M; j++) {
					s.nextToken();
					int a = (int) s.nval;
					s.nextToken();
					int b = (int) s.nval;
					friends.Union(a, b);
				}

				HashSet<Integer> roots = new HashSet<Integer>();

				for (int j = 1; j <= N; j++) {
					int current = friends.Find(j);
					roots.add(current);
				}

				System.out.println(String.format("Case %d: %d", count,
						roots.size()));

			}
		} catch (Exception e) {

		}
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
