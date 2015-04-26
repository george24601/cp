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
import java.util.Comparator;
import java.util.Dictionary;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Vector;

/* UVA 10400 Game Show Math
 * DP
 */

class Main {
	int p;
	int[] nums;
	int target;
	int[][] prev;
	boolean[][] canGet;

	int Max = 32000;
	int Min = -32000;
	int Size = 64001;

	int NumToIndex(int num) {
		return num + Max;
	}

	int IndexToNum(int index) {
		return index - Max;
	}

	boolean InRange(long num) {
		return Min <= num && num <= Max;
	}

	void Print_r(int pIndex, int curResult) {
		int curNum = nums[pIndex];

		if (pIndex == 0) {
			System.out.print(curNum);
			return;
		}

		int prevOp = prev[pIndex][NumToIndex(curResult)];

		int prevResult = 0;
		if (prevOp == 1) {
			prevResult = curResult - curNum;

		} else if (prevOp == 2) {
			prevResult = curResult + curNum;

		} else if (prevOp == 3) {
			prevResult = curResult / curNum;

		} else if (prevOp == 4) {
			prevResult = curResult * curNum;

		}

		Print_r(pIndex - 1, prevResult);

		if (prevOp == 1) {
			System.out.print('+');

		} else if (prevOp == 2) {
			System.out.print('-');

		} else if (prevOp == 3) {
			System.out.print('*');

		} else if (prevOp == 4) {
			System.out.print('/');
		}

		System.out.print(curNum);
	}

	void Process() {
		canGet[0][NumToIndex(nums[0])] = true;

		for (int i = 1; i < p; i++) {
			int curNum = nums[i];

			for (int j = 0; j < Size; j++) {

				if (!canGet[i - 1][j])
					continue;

				int lastResult = IndexToNum(j);

				int plus = lastResult + curNum;

				if (InRange(plus)) {
					canGet[i][NumToIndex(plus)] = true;
					prev[i][NumToIndex(plus)] = 1;
				}

				int minus = lastResult - curNum;

				if (InRange(minus)) {
					canGet[i][NumToIndex(minus)] = true;
					prev[i][NumToIndex(minus)] = 2;
				}

				int mult = lastResult * curNum;

				if (InRange(mult)) {
					canGet[i][NumToIndex(mult)] = true;
					prev[i][NumToIndex(mult)] = 3;
				}

				int div = lastResult / curNum;
				if (lastResult % curNum == 0 && InRange(div)) {
					canGet[i][NumToIndex(div)] = true;
					prev[i][NumToIndex(div)] = 4;
				}
			}
		}

		if (canGet[p - 1][NumToIndex(target)])
		{
			Print_r(p - 1, target);
			System.out.print("=");
			System.out.println(target);
		}
		else
		{
			System.out.println("NO EXPRESSION");
		}
	}

	void Run() {
		InputStream inStream = System.in;

		try {
			//inStream = new FileInputStream("C:\\Test\\Test.txt");
			BufferedReader reader = new BufferedReader(new InputStreamReader(
					inStream));

			StreamTokenizer st = new StreamTokenizer(reader);
			st.nextToken();
			int n = (int) st.nval;

			for (int i = 0; i < n; i++) {
				st.nextToken();
				p = (int) st.nval;

				nums = new int[p];
				canGet = new boolean[p][Size];
				prev = new int[p][Size];

				for (int j = 0; j < p; j++) {
					st.nextToken();
					nums[j] = (int) st.nval;
				}

				st.nextToken();
				target = (int) st.nval;

				Process();
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
