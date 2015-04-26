import java.io.InputStream;
import java.util.Scanner;

/*UVA 100: the 3n+1 problem
 *Notice the term "between"
 * */
class Main
{

	int ThreeNP1CycleLength(int number) {

		int aggre = 0;
		long current = number;
		while (true) {
			aggre++;

			if (current == 1)
				break;
			else if (current % 2 == 1)
				current = (current * 3) + 1;
			else
				current = current / 2;
		}

		return aggre;
	}

	int GetMaxCycLengthBetween_r(int start, int end) {
		int curMax = 0;
		for (int i = start; i <= end; i++) {
			int challenger = ThreeNP1CycleLength(i);
			if (challenger >= curMax)
				curMax = challenger;
		}

		return curMax;
	}

	int GetMaxCycLengthBetween(int i, int j) {
		if (i >= j)
			return GetMaxCycLengthBetween_r(j, i);
		else
			return GetMaxCycLengthBetween_r(i, j);
	}

	void Run() {
		InputStream inStream = System.in;
		Scanner s = new Scanner(inStream);

		while (s.hasNext()) {
			int i = s.nextInt();
			int j = s.nextInt();
			System.out.println(String.format("%d %d %d", i, j,
					GetMaxCycLengthBetween(i, j)));
		}
	}

	public static void main (String args[]) {
		(new Main()).Run();
	}
}
