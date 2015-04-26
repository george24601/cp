import java.io.FileInputStream;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.StringTokenizer;

/* UVA 10281 average speed
 */
class Main {
	
	long Convert(String timeLine)
	{
		String[] parts = timeLine.split(":");
		long seconds = Long.parseLong(parts[2]);
		long minitues = Long.parseLong(parts[1]);
		long hours = Long.parseLong(parts[0]);
		
		return 3600 * hours + 60 * minitues + seconds;
	}
	
	
	double toTwoDecimal(double d)
	{
		long i = (long) (d * 100);
		
		return (double) i/ 100;

	}

	void Run() {
		InputStream inStream = System.in;
		
		/*
		 try { inStream = new
		  FileInputStream("D:\\PersonalCode\\Algorithms\\UVA\\10281\\Test2.txt");
		  } catch(Exception e) {
		  
		  }
		  */
		  
		

		Scanner s = new Scanner(inStream);
		
		double distanceSoFar = 0;
		long currentSpeed =0;
		long lastCalcAt = 0;
		

		while (s.hasNextLine()) {
			StringTokenizer line = new StringTokenizer(s.nextLine());
			String time = line.nextToken();
			long currentTime = Convert(time); 
			
			double newlyTravelled = currentSpeed/3600.0 * (currentTime - lastCalcAt);
			lastCalcAt = currentTime;
			distanceSoFar += newlyTravelled;

			if(line.hasMoreTokens())
			{
				long newSpeed = Long.parseLong(line.nextToken());
				currentSpeed = newSpeed;
			}else
			{
				System.out.println(String.format("%s %.2f km" , time, toTwoDecimal(distanceSoFar)));
			}

		}
		
		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
