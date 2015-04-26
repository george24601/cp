import java.io.FileInputStream;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.BitSet;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;

/* UVA 594 One Two Three Little Endian: use bitset
 */
class Main {
	
	final int NumBits = 32;
	final int BitsInByte = 8;

	int Process(int before)
	{
		BitSet bitSet = new BitSet(NumBits);

		int shifted = before;
		for (int i = 0; i < NumBits; i++)
		{
			if ((shifted & 0x1) == 0x1)
				bitSet.flip(NumBits - 1 - i);

			shifted = shifted >> 1;
		}

		BitSet reversed = new BitSet(NumBits);
		
		
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < BitsInByte; j++)
			{
				if (bitSet.get(i * BitsInByte + j))
				{
					reversed.flip ((3 - i) * BitsInByte + j);
				}
			}
		}
		
		bitSet = reversed;
		long posSum = 0;
		for (int i = NumBits - 1; i >= 1 ; i--)
		{
			if (bitSet.get(i))
			{
				long powerTwo = (long) Math.pow(2, NumBits - 1 - i);
				posSum += powerTwo;
			}
		}

		if (bitSet.get(0))
			posSum -= Math.pow (2, NumBits - 1);

		return (int) posSum;
	}


	void Run() {
		InputStream inStream = System.in;

		/*
		 try { inStream = new FileInputStream(
		  "D:\\PersonalCode\\Algorithms\\UVA\\594\\Test.txt"); } catch
		  (Exception e) {
		  
		  }
		  */
		  
		

		Scanner s = new Scanner(inStream);

		while (s.hasNextLine())
		{
			int before = Integer.parseInt(s.nextLine()); 
			int after = Process (before);

			System.out.println(String.format("%d converts to %d", before, after));
		}

		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
