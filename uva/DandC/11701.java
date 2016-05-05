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
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Vector;

/* UVA 11701 Cantor

 * DP search
 */

class Main {

	int size = 1000000;
	boolean[] answers;
	int Three = 3;
	Queue<Integer> queue;

	void ProcessCandidate(int candidate)
	{
		if (answers[candidate])
		{
			answers[candidate] = false;
			
			if (candidate % 3 == 0)
				queue.add(candidate/ 3);
			
			if ((candidate + size) % 3 == 0)
				queue.add((candidate + size) / 3);
				
			if ((candidate + 2 * size) % 3 == 0)
				queue.add((candidate +  2 * size) / 3);
		}
	}
	
	void PreCompute() {
		answers = new boolean[size + 1];
		answers[0] = true;
		answers[size] = true;
		
		queue = new LinkedList<Integer>();
		
		for (int i =1; i < size; i++)
		{
			if (i * 3 > size && i * 3 < (2*size))
			{
				queue.add(i);
			}
				
			answers[i] = true;
			
		}

		while(!queue.isEmpty())
		{
			int next = queue.poll();
			
			ProcessCandidate(next);	
		}
		
	}

	void Run() {
		InputStream inStream = System.in;

		try {
		//	inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			PreCompute();
			while (true) {
				st.nextToken();
				if (st.ttype == st.TT_NUMBER) {
					double val = (double) st.nval;
					int intVal = ((int) (val * size * 100)) / 100;
					if (answers[intVal])
						System.out.println("MEMBER");
					else
						System.out.println("NON-MEMBER");
				} else
					break;

			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
