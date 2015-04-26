import java.io.FileInputStream;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/* UVA 573 the snails
 * boundary cases!
 */
class Main
{
	void Climb_r(int H, int U, int D, int F, double curHeight, int spentDay)
	{
		
		double curClimbRate = ((double)(U * (100 - (F * spentDay))))/100;
		spentDay++;
		
		double endOfDayHeight = curHeight;
		if (curClimbRate > 0)
		{
			endOfDayHeight += curClimbRate;
			if (endOfDayHeight > H)
			{
				System.out.print("success on day ");
				System.out.println(spentDay);
				return;
			}
		}
		
		endOfDayHeight -= D;
		
		if (endOfDayHeight < 0)
		{
				System.out.print("failure on day ");
				System.out.println(spentDay);
				return;
		}else
		{
			Climb_r(H, U, D, F, endOfDayHeight, spentDay);
		}
	}
	
	void Process(int H, int U, int D, int F)
	{
		Climb_r(H, U, D, F, 0, 0);
	}
	
	void Run() {
		InputStream inStream = System.in;

		/*
		try
		{
			inStream = new FileInputStream("D:\\PersonalCode\\Algorithms\\UVA\\573\\Test.txt");
		} catch(Exception e)
		{
			
		}
		*/

		Scanner s = new Scanner(inStream);
		
		while(s.hasNextLine())
		{
			int H = s.nextInt();
			
			if (H == 0)
				break;
			Process(H, s.nextInt(), s.nextInt(), s.nextInt());
		}
	}

	public static void main (String args[]) {
		(new Main()).Run();
	}
}

