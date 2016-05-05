import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.math.BigDecimal;
import java.util.Scanner;

/* UVA 424 integer inquiry 
 * bigdecimal
 */

class Main {

	void Run() {
		InputStream inStream = System.in;

		/*
		try {
			inStream = new FileInputStream(
					"C:\\Users\\user\\PersonalCode\\Algorithms\\UVA\\424\\Test.txt");
		} catch (IOException e) {

		}
		*/

		Scanner s = new Scanner(inStream);

		BigDecimal total = new BigDecimal("0");
		while (s.hasNextLine()) {

			String line = s.nextLine();
			if (line.equals("0"))
				break;

			BigDecimal p = new BigDecimal(line);
			total = total.add(p);
		}

		System.out.println(total);
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
