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

/* UVA 10706 Number Sequence
 *binary search
 */

class Main {

	long Total(long k) {

		long total = 0;

		long comp = 1;
		long charLength = 1;

		while (true) {
			long nextComp = comp * 10;

			if (nextComp <= k) {
				total += (k - comp + 1 + k - nextComp + 2) * 9 * comp / 2
						* charLength;
			} else {
				total += (k - comp + 1 + 1) * (k - comp + 1) / 2 * charLength;
				break;

			}

			comp = nextComp;
			charLength++;
		}

		return total;
	}

	long SingleSeqLength(long k) {
		long total = 0;
		long comp = 1;
		long charLength = 1;
		while (true) {
			long nextComp = comp * 10;

			if (nextComp <= k) {
				total += comp * 9 * charLength;
			} else {
				total += (k - comp + 1) * charLength;
				break;
			}

			comp = nextComp;
			charLength++;
		}

		return total;
	}

	long ResolveSingle_r(long low, long high, long pos) {
		long mid = (low + high) / 2;

		long midLength = SingleSeqLength(mid);
		long curSeg = (new Long(mid)).toString().length();

		if (pos <= midLength - curSeg) {
			return ResolveSingle_r(low, mid - 1, pos);

		} else if (midLength - curSeg < pos && pos <= midLength) {
			int digit = (int)(pos - midLength + curSeg);
			return (new Long(mid)).toString().charAt(digit - 1) - '0';
		} else {
			return ResolveSingle_r(mid + 1, high, pos);
		}
	}

	long Guess_r(long pos, long low, long high) {
		long mid = (low + high) / 2;
		long midLength = Total(mid);
		long curSeg = SingleSeqLength(mid);

		if (pos <= midLength - curSeg)
		{
			return Guess_r(pos, low, mid - 1);
		}
		else if (midLength - curSeg < pos && pos <= midLength) 
		{
			return ResolveSingle_r(1, mid, (int) (pos - midLength + curSeg));
		}
		else
		{
			return Guess_r(pos, mid + 1, high);
		}
	}

	void Run() {
		InputStream inStream = System.in;

		try {
		//	 inStream = new FileInputStream(
		//	 "C:\\Users\\IBM_ADMIN\\PersonalCode\\Algorithms\\UVA\\10706\\D.IN");

			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			st.nextToken();
			int t = (int) st.nval;

			for (int i = 0; i < t; i++) {
				st.nextToken();
				long target = (long) st.nval;
				System.out.println(Guess_r(target, 1, 500000));
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
