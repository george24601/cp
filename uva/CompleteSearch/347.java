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

/* UVA 347 Run, Run, Runaround Numbers 
 * complete search
 */

class Main {

	int usedDigitSet;

	boolean IsRunAbout(long num) {
		String numString = Long.toString(num);

		int checkedIndexSet = 0;
		int nextIndex = 0;

		for (int i = 0; i < numString.length(); i++) {
			int digit = numString.charAt(nextIndex) - '0';
			nextIndex = (digit + nextIndex) % numString.length();
			checkedIndexSet = checkedIndexSet | (1 << nextIndex);
		}

		for (int i = 0; i < numString.length(); i++) {
			if (((checkedIndexSet >> i) & 1) == 0)
				return false;
		}

		return true;
	}

	long Process_r(int R, long currentVal, int moreToCheck) {

		for (int i = 0; i <= 9; i++) {

			boolean isNonZeroUsed = i != 0 || (i == 0 && usedDigitSet != 0);

			if (isNonZeroUsed) {
				boolean isDigitUsed = ((usedDigitSet >> i) & 1) == 1;

				if (isDigitUsed)
					continue;
			}

			long newVal = currentVal * 10 + i;
			int usedDigitBeforeExpanding = usedDigitSet;

			if (isNonZeroUsed)
				usedDigitSet = usedDigitSet | (1 << i);

			if (moreToCheck > 0) {
				long returnedVal = Process_r(R, newVal, moreToCheck - 1);

				if (returnedVal > 0)
					return returnedVal;
				else
					usedDigitSet = usedDigitBeforeExpanding;
			} else if (newVal >= R && IsRunAbout(newVal)) {
				return newVal;
			} else {
				usedDigitSet = usedDigitBeforeExpanding;
			}
		}

		return -1;
	}

	void Run() {
		InputStream inStream = System.in;

		try {
		//	inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			int caseCount = 0;
			while (true) {
				st.nextToken();

				int R = (int) st.nval;
				if (R == 0)
					break;

				caseCount++;

				usedDigitSet = 0;
				long result = Process_r(R, 0, 8);

				System.out.println(String.format("Case %d: %d", caseCount,
						result));
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
