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
import java.util.Scanner;

/* UVA 10079 Pizza
 * induction proof
 */

class Main {


	void Run() {
		InputStream inStream = System.in;

		try {
		//	inStream = new FileInputStream(
		//			"C:\\Users\\IBM_ADMIN\\PersonalCode\\Algorithms\\UVA\\10079\\Test.txt");

			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			
			while(true)
			{
				st.nextToken() ;
				long t = (long) st.nval;

				if (t < 0)
					break;
				long result = (t +1 ) * t /2 + 1;
				
				System.out.println(result);

			}
		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
