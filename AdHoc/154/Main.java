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

/* UVA 154 recycling 
 * complete search
 */
class Main {

	final int Size = 5;

	void Process(List<char[]> cities) {
		int min = Integer.MAX_VALUE;
		int minNum = 0;

		for (int i = 0; i < cities.size(); i++) {
			char[] current = cities.get(i);
			int totalChanges = 0;

			for (int j = 0; j < cities.size(); j++) {
				for (int k = 0; k < Size; k++) {
					if (current[k] != cities.get(j)[k])
						totalChanges++;
				}
			}

			if (totalChanges < min)
			{
				min = totalChanges;
				minNum = i + 1;
			}

		}

		System.out.println(minNum);
	}

	int ToIndex(char c) {
		if (c == 'r')
			return 0;
		if (c == 'o')
			return 1;
		if (c == 'y')
			return 2;
		if (c == 'g')
			return 3;
		if (c == 'b')
			return 4;

		return -1;
		// r, o, y,g , b
	}

	void Run() {
		InputStream inStream = System.in;
		/*
		try {
			inStream = new FileInputStream(
					"C:\\Users\\user\\PersonalCode\\Algorithms\\UVA\\154\\Test.txt");
		} catch (Exception e) {
		}
		*/

		Scanner s = new Scanner(inStream);
		List<char[]> config = new ArrayList<char[]>();
		while (s.hasNextLine()) {
			String line = (String) s.nextLine();

			if (line.equals("#"))
				break;

			if (line.charAt(0) == 'e') {
				Process(config);
				config.clear();
			} else {
				char[] newLine = new char[Size];

				String[] blocks = line.split(",");

				for (int i = 0; i < Size; i++) {
					char color = blocks[i].charAt(0);
					char waste = blocks[i].charAt(2);
					newLine[ToIndex(color)] = waste;
				}

				config.add(newLine);
			}
		}
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
