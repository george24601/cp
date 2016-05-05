import java.io.FileInputStream;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.BitSet;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;

/* UVA 299  Train swapping: reverse index problem with bubble sort
 */
class Main {
	

int Process_r(List<Integer> ints, int step)
{
	int index = ints.indexOf(step);
	
	if (index < 0)
		return 0;
	
	ints.remove(index);
	return index+ Process_r(ints, step + 1);
}


	void Run() {
		InputStream inStream = System.in;

		/*
		 try { inStream = new FileInputStream(
		  "D:\\PersonalCode\\Algorithms\\UVA\\299\\Test.txt"); } catch
		  (Exception e) {
		  
		  }
		  */
		  
		  
		

		Scanner s = new Scanner(inStream);

		int  N = Integer.parseInt(s.nextLine());

		for (int i = 0; i < N; i++)
		{
			int  L = Integer.parseInt(s.nextLine());
			StringTokenizer tokens = new StringTokenizer(s.nextLine());

			List<Integer> ints = new ArrayList<Integer>();
			for (int j = 0; j < L ; j++)
				ints.add(Integer.parseInt(tokens.nextToken()));
			
			int result = Process_r(ints, 1);
			System.out.println(String.format("Optimal train swapping takes %d swaps.", result));
			
		}
		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
