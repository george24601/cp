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
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;
import java.util.StringTokenizer;

/* UVA 336: A node too far
 * simple BFS
 */
class Main {
	
	class Graph
	{
		HashMap<Integer, ArrayList<Integer>> _edges;
		
		public Graph()
		{
			_edges = new HashMap<Integer, ArrayList<Integer>>();
		}
		public void AddEdge(int a, int b)
		{
			if (!_edges.containsKey(a))
				_edges.put(a, new ArrayList<Integer>());
			
			_edges.get(a).add(b);

			if (!_edges.containsKey(b))
				_edges.put(b, new ArrayList<Integer>());
			
			_edges.get(b).add(a);
		}
		
		public ArrayList<Integer> GetEdges(int a)
		{
			return _edges.get(a);
			
		}
		
		public int NumNodes()
		{
			return _edges.size();
		}
	}
	
	void BFS(Graph g, List<Integer> level, Set<Integer> agg, int TTL)
	{
		if (TTL <= 0)
			return;
		
		Set<Integer> nextLevel = new HashSet<Integer>();
		
		for (int i = 0; i < level.size(); i++)
		{
			int nextNode = level.get(i);
			
			ArrayList<Integer> neighbors = g.GetEdges(nextNode);

			for (int j = 0; j < neighbors.size() ; j++)
			{
				nextLevel.add(neighbors.get(j));
				agg.add(neighbors.get(j));
			}
		}
		
		level.clear();
		Object [] nextLevelArray =  nextLevel.toArray();

		for (int i = 0; i < nextLevel.size(); i++)
			level.add((Integer) nextLevelArray[i]);
		
		BFS(g, level, agg, TTL - 1);
	}

	void Run() {
		InputStream inStream = System.in;

		/*
		  try { inStream = new FileInputStream(
		  "D:\\PersonalCode\\Algorithms\\UVA\\336\\Test.txt"); }
		  catch (Exception e) {
		  
		 }
		 */

		Scanner s = new Scanner(inStream);

		int count = 0;
		while (true) {
			int NC = Integer.parseInt(s.nextLine());
			
			if (NC == 0)
				break;

			Graph g = new Graph();
			for (int i = 0; i < NC; i++) {
				int nodeA = s.nextInt();
				int nodeB = s.nextInt();
				g.AddEdge(nodeA, nodeB);
			}
			
			while(true)
			{
				int node = s.nextInt();
				int TTL = s.nextInt();
				
				if (node == 0 && TTL == 0)
					break;
				
				count++;
				Set<Integer> agg = new HashSet<Integer>();
				List<Integer> level = new ArrayList<Integer>();
				level.add(node);
				agg.add(node);
				BFS(g, level, agg, TTL);

				System.out.println(String.format("Case %d: %d nodes not reachable from node %d with TTL = %d.", 
						count, g.NumNodes() - agg.size(), node, TTL));
			}
			
			s.nextLine();
			s.nextLine();
		}

		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
