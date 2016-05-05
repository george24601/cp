import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.Arrays;

/* UVA 10077 The Stern-Brocot Number System
 * simple binary search
 */
class Main {

	int m;
	int n;

	long gcd(long a, long b) {
		if (a % b == 0)
			return b;

		return gcd(b, a % b);
	}

	void Process_r(long lm, long ln, long mm, long mn, long rm, long rn) {

		if (m * mn < n * mm) {
			System.out.print('L');

			long newmm = mm + lm;
			long newmn = mn + ln;

			long gcd;

			if (newmm > newmn)
				gcd = gcd(newmm, newmn);
			else
				gcd = gcd(newmn, newmm);
			
			newmm = newmm/gcd;
			newmn = newmn/gcd;

			Process_r(lm, ln, newmm, newmn, mm, mn);

		} else if (m * mn > n * mm) {
			System.out.print('R');
			long newmm = mm + rm;
			long newmn = mn + rn;


			long gcd;

			if (newmm > newmn)
				gcd = gcd(newmm, newmn);
			else
				gcd = gcd(newmn, newmm);
			
			newmm = newmm/gcd;
			newmn = newmn/gcd;


			Process_r(mm, mn, newmm, newmn, rm, rn);

		} else {
			System.out.println();
		}

	}

	void Run() {
		InputStream inStream = System.in;

		try {
		//	inStream = new FileInputStream(
		//			"C:\\Users\\user\\PersonalCode\\Algorithms\\UVA\\10077\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer s = new StreamTokenizer(reader);

			while (true) {
				s.nextToken();
				m = (int) s.nval;
				s.nextToken();
				n = (int) s.nval;

				if (m == 1 && n == 1)
					break;

				Process_r(0, 1, 1, 1, 1, 0);
			}

		} catch (IOException e) {

		}
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
