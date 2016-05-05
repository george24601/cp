import java.io.FileInputStream;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.StringTokenizer;

/* UVA 10683 The decadary watch 
 */
class Main {
	
	void Run() {
		InputStream inStream = System.in;

		/*
		try {
			inStream = new FileInputStream(
					"D:\\PersonalCode\\Algorithms\\UVA\\10683\\Test.txt");
		} catch (Exception e) {

		}
		*/

		Scanner s = new Scanner(inStream);

		long totalOldCCs = 24  * 60 * 60 * 100;
		long totalNewCCs = 10 * 100 * 100 * 100;

		while(s.hasNextLine())
		{
			String line = s.nextLine();

			int hh = Integer.parseInt(line.substring(0, 2));
			int mm = Integer.parseInt(line.substring(2, 4));
			int ss = Integer.parseInt(line.substring(4, 6));
			int cc = Integer.parseInt(line.substring(6));

			long oldTotalCC = cc + 100 * ss + 60 * 100 * mm + 60 * 60 * 100 * hh; 
			long newCC = (long) (oldTotalCC  * ((double)totalNewCCs/ (double) totalOldCCs));
			
			long newHH = newCC / (100 * 100  *100);
			newCC -= newHH * 100 * 100 * 100;

			long newMM = newCC/ (100 * 100);
			newCC -= newMM * 100 * 100;

			long newSS = newCC / 100;

			newCC -= newSS * 100;

			System.out.println(String.format("%d%02d%02d%02d", newHH,newMM,newSS,newCC));
		}

		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
