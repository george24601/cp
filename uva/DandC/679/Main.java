import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.Arrays;


/* UVA 679 dropping balls
 * simple binary search
 */
class Main {

	void Process_r(int D, int I, long num)
	{
		if (D == 1)
		{
			System.out.println(num);
			return;
		}
		
		if (I % 2 == 0)
			Process_r(D - 1, I/2, 2 * num + 1);
		else
			Process_r(D - 1, (I + 1)/2, 2 * num);
	}

	void Run() {
		InputStream inStream = System.in;

		/*
		try {
			inStream = new FileInputStream(
					"C:\\Users\\user\\PersonalCode\\Algorithms\\UVA\\679\\Test.txt");
		} catch (Exception e) {
		}
		*/

		try {
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer s = new StreamTokenizer(reader);

			s.nextToken();
			int l = (int)s.nval;
			
			for (int i = 0; i < l; i++)
			{
				s.nextToken();
				int D = (int)s.nval;
				s.nextToken();
				int I = (int)s.nval;
				
				Process_r(D, I, 1);
			}


		} catch (IOException e) {

		}
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
