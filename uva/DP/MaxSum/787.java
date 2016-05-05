import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.math.BigDecimal;
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

/* UVA 787 Maximum Sub-sequence Product
 * Maximum sum
 */

class Main {
	List<BigDecimal> nums;
	BigDecimal[] maxPosProd;
	BigDecimal[] minNegProd;
	BigDecimal Zero;
	BigDecimal One;

	void Process() {
		if (nums.get(0).compareTo(Zero) > 0) {
			maxPosProd[0] = nums.get(0);
			minNegProd[0] = Zero;
		} else if (nums.get(0).compareTo(Zero) < 0) {
			maxPosProd[0] = Zero;
			minNegProd[0] = nums.get(0);
		} else {
			maxPosProd[0] = Zero;
			minNegProd[0] = Zero;
		}

		for (int i = 1; i < nums.size(); i++) {
			if (nums.get(i).compareTo(Zero) > 0) {
				BigDecimal maxPosGuess = nums.get(i)
						.multiply(maxPosProd[i - 1]);

				if (maxPosGuess.compareTo(Zero) > 0)
					maxPosProd[i] = maxPosGuess;
				else
					maxPosProd[i] = nums.get(i);

				BigDecimal minNegGuess = nums.get(i)
						.multiply(minNegProd[i - 1]);

				minNegProd[i] = minNegGuess;
			} else if (nums.get(i).compareTo(Zero) < 0) {
				BigDecimal minNegGuess = nums.get(i)
						.multiply(maxPosProd[i - 1]);

				if (minNegGuess.compareTo(Zero) < 0)
					minNegProd[i] = minNegGuess;
				else
					minNegProd[i] = nums.get(i);

				BigDecimal maxPosGuess = nums.get(i)
						.multiply(minNegProd[i - 1]);

				maxPosProd[i] = maxPosGuess;
			} else {
				maxPosProd[i] = Zero;
				minNegProd[i] = Zero;
			}
		}

		BigDecimal curMax = nums.get(0);

		for (int i = 1; i < nums.size(); i++) {
			if (maxPosProd[i].compareTo(curMax) > 0)
				curMax = maxPosProd[i];
		}

		if (curMax.compareTo(Zero) > 0) {
			System.out.println(curMax);
			return;
		}

		curMax = nums.get(0);

		for (int i = 1; i < nums.size(); i++) {
			if (nums.get(i).compareTo(curMax) > 0)
				curMax = nums.get(i);
		}

		System.out.println(curMax);
	}

	void Run() {
		InputStream inStream = System.in;

		try {
		//	inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			Zero = new BigDecimal(0);
			One = new BigDecimal(1);

			while (st.nextToken() != st.TT_EOF) {
				nums = new ArrayList<BigDecimal>();
				int num = (int) st.nval;

				nums.add(new BigDecimal(num));

				while (true) {
					st.nextToken();

					num = (int) st.nval;

					if (num == -999999)
						break;
					nums.add(new BigDecimal(num));
				}

				maxPosProd = new BigDecimal[nums.size()];
				minNegProd = new BigDecimal[nums.size()];

				Process();
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
