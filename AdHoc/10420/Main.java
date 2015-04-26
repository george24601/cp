import java.io.FileInputStream;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;

/* UVA 10420  list of conquests 
 */
class Main {

	void Run() {
		InputStream inStream = System.in;

		/*
		try {
			inStream = new FileInputStream(
					"D:\\PersonalCode\\Algorithms\\UVA\\10420\\Test.txt");
		} catch (Exception e) {

		}
		*/

		Scanner s = new Scanner(inStream);

		StringTokenizer firstLine = new StringTokenizer(s.nextLine());
		int numLines = Integer.parseInt(firstLine.nextToken());

		Map<String, Set<String>> nationToNames = new HashMap<String, Set<String>>();
		for (int i = 0; i < numLines; i++) {
			String line = s.nextLine();
			StringTokenizer tokens = new StringTokenizer(line);
			String nation = tokens.nextToken();
			String firstName = tokens.nextToken();
			String fullName = line.substring(line.indexOf(firstName));

			if (!nationToNames.containsKey(nation))
				nationToNames.put(nation, new HashSet<String>());

			nationToNames.get(nation).add(fullName);

		}

		List<String> names = new ArrayList<String>(nationToNames.keySet());
		Collections.sort(names);

		for (int i = 0; i < names.size(); i++)
		{
			String nation = names.get(i);
			System.out.println(String.format("%s %d", nation, nationToNames.get(nation).size()));
		}

		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
