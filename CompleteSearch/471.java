import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

/* UVA 471 Magic Numbers
 * (smart) complete search
 */

class Main {
	int usedDigits;
	long MaxS1 = 9876543210L;

	boolean NoRepeat(long second) {
		String digits = Long.toString(second);

		int digitsUsed = 0;
		for (int i = 0; i < digits.length(); i++) {
			int digit = digits.charAt(i) - '0';

			if (((digitsUsed >> digit) & 1) == 1)
				return false;
			else
				digitsUsed = digitsUsed | (1 << digit);
		}

		return true;
	}

	void Process_r(long N, long currentVal, int numDigitsToCheck, long stepSpace) {
		if (numDigitsToCheck == 0) {
			long first = currentVal * N;

			if (first > 0 && first <= MaxS1 && NoRepeat(first))
				System.out.println(String.format("%d / %d = %d", first, currentVal, N));
		} else {

			for (int i = 0; i <= 9; i++) {
				boolean isFirstDigit = usedDigits == 0;

				int usedDigitBeforeChoosing = usedDigits;
				if (isFirstDigit && i == 0) {

				} else {
					if (((usedDigits >> i) & 1) == 1)
						continue;

					usedDigits = usedDigits | (1 << i);
				}

				long newVal = currentVal * 10 + i;

				long floor = newVal * stepSpace * N;
				if (floor < 0 || floor > MaxS1) {

				} else {
					Process_r(N, newVal, numDigitsToCheck - 1, stepSpace / 10);
				}

				usedDigits = usedDigitBeforeChoosing;
			}
		}

	}

	void Run() {
		InputStream inStream = System.in;

		try {
			//inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			st.nextToken();
			int numCases = (int) st.nval;

			for (int i = 0; i < numCases; i++) {
				st.nextToken();
				long N = (long) st.nval;

				if (i > 0)
					System.out.println();

				usedDigits = 0;
				Process_r(N, 0, 9, 100000000);
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
