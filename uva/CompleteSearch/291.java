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

/* UVA 291: The House Of Santa Claus
 *  Back tracking
 */
class Main {

	
	final int NodeSize = 6;
	final int EdgeSize = 8;
	
	boolean IsPossibleEdge(int last, int i)
	{
		if (last == 1)
			return i == 2 || i == 3 || i  == 5;
		else if (last == 2)
			return i == 1 || i  == 3 || i == 5;
		else if (last == 3)
			return i == 1 || i == 2 || i == 4 || i  == 5;
		else if (last == 4)
			return i == 3 || i  == 5;
		else if (last == 5)
			return i == 1 || i == 2 || i  == 3 || i == 4;
		else
			return false;
	}

	int ToEdgeID(int a, int b)
	{
		int small = a < b ? a : b;
		int big = a < b ? b : a;
		
		if (small == 1 &&  big == 2)
			return 0;
		if (small == 1 &&  big == 5)
			return 1;
		if (small == 2 &&  big == 3)
			return 2;
		if (small == 2 &&  big == 5)
			return 3;
		if (small == 3 &&  big == 4)
			return 4;
		if (small == 3 &&  big == 5)
			return 5;
		if (small == 4 &&  big == 5)
			return 6;
		if (small == 1 &&  big == 3)
			return 7;
		
		return -1;
		
	}

	void Draw_r (int step, int lastNode, int[] g, int[] path)
	{
		for (int i = 1; i < NodeSize; i++)
		{
			int edgeID = ToEdgeID(lastNode, i);

			if(!IsPossibleEdge(lastNode, i) || g[edgeID] > 0)
				continue;
			
			path[step] = i;
			g[edgeID] = step;
			
			if (step == EdgeSize)
			{
				for (int j = 0; j < EdgeSize + 1; j++)
					System.out.print(path[j]);

				System.out.println();
				
			}else
			{
				Draw_r (step + 1, i, g, path);
			}

			g[edgeID] = 0;
		}
		
	}

	void Run() {
		int[] edges = new int[EdgeSize];
		int[] sequence = new int[EdgeSize + 1];
		sequence[0] = 1;
		Draw_r (1, 1, edges, sequence);
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
