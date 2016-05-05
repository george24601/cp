import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/* UVA 105 skyline problem 
 * ad hoc
 */
class Main {

	void Process(int val) {

		int factor = 1;
		for (int i = 0; i < val / 2; i++)
			factor *= 10;

		for (int i = 0; i < factor; i++) {
			for (int j = 0; j < factor; j++) {
				int num = i * factor + j;
				if ((i + j) * (i + j) == num)
					System.out.println(num);
			}
		}

	}

	void Run() {
		InputStream inStream = System.in;
/*
		try {
			inStream = new FileInputStream(
					"D:\\PersonalCode\\Algorithms\\UVA\\105\\Test.txt");
		} catch (Exception e) {
		}
		*/

		try {
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer s = new StreamTokenizer(reader);

			final int Size = 10000;
			int[] land = new int[Size];
			while (s.nextToken() != s.TT_EOF) {
				int l = (int) s.nval;
				s.nextToken();
				int h = (int) s.nval;
				s.nextToken();
				int right = (int) s.nval;

				for (int i = l; i < right; i++) {// actual right one is not "painted"
					if (land[i] < h)
						land[i] = h;
				}

			}

			int currentHeight = 0;
			boolean isFirst = true;

			for (int i = 0; i < Size; i++) {
				if (currentHeight == land[i])
					continue;

				if (isFirst)
					isFirst = false;
				else
					System.out.print(' ');

				currentHeight = land[i];
				System.out.print(i);
				System.out.print(' ');
				System.out.print(currentHeight);
			}

			System.out.println();
		} catch (IOException e) {

		}
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
