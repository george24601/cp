import java.io.FileInputStream;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.StringTokenizer;

/* UVA 119 Greedy Gift Giver 
 */
class Main {

	void ProcessSingleCase(Scanner f) {
		StringTokenizer st = new StringTokenizer(f.nextLine());

		int NP = Integer.parseInt(st.nextToken());

		String[] names = new String[NP];
		Map<String, Integer> ppl = new HashMap<String, Integer>();
		Map<String, Integer> init = new HashMap<String, Integer>();

		StringTokenizer pplNames = new StringTokenizer(f.nextLine());

		for (int i = 0; i < NP; i++) {
			String name = pplNames.nextToken();
			ppl.put(name, 0);
			names[i] = name;
		}

		for (int i = 0; i < NP; i++) {
			StringTokenizer tokenizer = new StringTokenizer(f.nextLine());
			String name = tokenizer.nextToken();

			int money = Integer.parseInt(tokenizer.nextToken());
			int NG = Integer.parseInt(tokenizer.nextToken());

			init.put(name, money);
			int eachAmount = NG == 0 ? 0 : money / NG;
			int remainingAmount = money - eachAmount * NG;

			ppl.put(name, ppl.get(name) + remainingAmount);

			for (int j = 0; j < NG; j++) {
				String receiver = tokenizer.nextToken();
				ppl.put(receiver, ppl.get(receiver) + eachAmount);

			}
		}

		for (int i = 0; i < NP; i++)
			System.out.println(String.format("%s %d", names[i], ppl.get(names[i])
					- init.get(names[i])));
	}

	void Run() {
		InputStream inStream = System.in;

		
		/*
		  try { inStream = new
		  FileInputStream("D:\\PersonalCode\\Algorithms\\UVA\\119\\t1.txt"
		  ); } catch(Exception e) {
		  
		  }
		  */

		Scanner f = new Scanner(inStream);

		while (f.hasNextLine())
		{
			ProcessSingleCase(f);
			
			if (f.hasNextLine())
				System.out.println();
		}

		//	System.out.println("end");
		f.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
