import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

/* UVA 624 CD 
 * knapsack
 */

class Main {
	class Pair
	{
		public long sum;
		public int usedTrack;
		
		public Pair(long s, int used)
		{
			sum=s;
			usedTrack = used;
		}
	}
	
	long N;
	int numTracks;
	long[] tracks;
	
	Pair Process_r(int curTrack, long remainingSpace)
	{
		if (curTrack >= numTracks || remainingSpace == 0)
			return new Pair(0, 0);
		//use this track
		Pair useFirst = null;
		
		
		if (remainingSpace - tracks[curTrack] >= 0)
		{
			useFirst = Process_r(curTrack + 1, remainingSpace - tracks[curTrack]);
		}
		
		Pair noUse = Process_r(curTrack+1, remainingSpace);
		
		if (useFirst != null && useFirst.sum + tracks[curTrack] > noUse.sum)
		{
			return new Pair(useFirst.sum + tracks[curTrack], (useFirst.usedTrack | (1 << curTrack)));
		}else
		{
			return noUse;
		}
		
	}
	
	void Run() {
		InputStream inStream = System.in;

		try {
			// inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			while(st.nextToken() != st.TT_EOF)
			{
				N = (long) st.nval;
				
				st.nextToken();
				numTracks = (int)st.nval;
				
				tracks = new long[numTracks];
				
				for(int i = 0; i < numTracks; i++)
				{
					st.nextToken();
					tracks[i] = (long)st.nval;
				}
				
				Pair pair = Process_r(0, N);
				int usedTracks = pair.usedTrack;
				
				for (int i = 0; i < numTracks; i++)
				{
					if (((usedTracks >> i) & 1 ) == 1)
					{
						System.out.print(tracks[i]);
						System.out.print(" ");
					}
				}
				
				System.out.println(String.format("sum:%d", pair.sum));
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
