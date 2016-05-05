import java.io.FileInputStream;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.StringTokenizer;

/* UVA 10141 Request for proposal 
 */
class Main {

	void Run() {
		InputStream inStream = System.in;
		
		/*
		 try { inStream = new
		  FileInputStream("D:\\PersonalCode\\Algorithms\\UVA\\10141\\Test.txt");
		  } catch(Exception e) {
		  
		  }
		  */
		  

		Scanner s = new Scanner(inStream);

		boolean isFirst = true;

		int RFPNum = 0;
		while (s.hasNextLine()) {
			StringTokenizer t1 = new StringTokenizer(s.nextLine());
			int n = Integer.parseInt(t1.nextToken());
			int p = Integer.parseInt(t1.nextToken());

			if (n == 0 && p == 0)
			{
				break;
			}
			else if (!isFirst)
			{
				System.out.println();
			}

			RFPNum ++;
			String[] requirements = new String[n];

			for (int i = 0; i < n; i++)
				requirements[i] = s.nextLine();

			String curProposal = null;
			double curProposalPrice = -1;
			double curProposalCompliance = -1;


			for (int i = 0; i < p; i++)
			{
				String proposal = s.nextLine();
				StringTokenizer proposalTokens = new StringTokenizer(s.nextLine());
				double price = Double.parseDouble(proposalTokens.nextToken());
				int r = Integer.parseInt(proposalTokens.nextToken());

				for (int j = 0; j < r; j++)
					s.nextLine();

				double compliance = (double) r/(double) n;

				if (compliance > curProposalCompliance || 
						(compliance == curProposalCompliance && price < curProposalPrice))
				{
					curProposal = proposal;
					curProposalPrice = price;
					curProposalCompliance = compliance;
				}
			}

			System.out.println(String.format("RFP #%d", RFPNum));
			System.out.println(curProposal);

			if (isFirst)
				isFirst = false;
		}
		
		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
