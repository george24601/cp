import java.io.FileInputStream;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;

/* UVA 10528 major scales
 */
class Main {
	final int MajorSize = 7;
	final int NotesSize = 12;

	List<Set<String>> GenerateMajorList(String[] notes)
	{
		int[] gaps = new int[] {2,2,1,2,2,2, 1};

		List<Set<String>> toReturn = new ArrayList<Set<String>>();

		for (int i = 0; i < NotesSize; i++)
		{
			toReturn.add(new HashSet<String>());

			toReturn.get(i).add(notes[i]);
			int lastNoteIndex = i;
			for (int j = 0; j < MajorSize; j++)
			{
				int newNoteIndex = (lastNoteIndex + gaps[j]) % NotesSize;
				toReturn.get(i).add(notes[newNoteIndex]);
				lastNoteIndex = newNoteIndex;
			}
		}

		return toReturn;
	}

	void Process(String[] notes, List<Set<String>> majorLists, Set<String> distinctNotes)
	{
		List<String> input = new ArrayList<String>(distinctNotes);

		boolean isFirst = true;
		for (int i = 0; i < NotesSize; i++)
		{
			boolean allInRange = true;
			for (int j = 0; j < input.size(); j++)
			{
				if(!majorLists.get(i).contains(input.get(j)))
				{
					allInRange = false;
					break;
				}
			}

			if (allInRange)
			{
				if (isFirst)
					isFirst = false;
				else
					System.out.print(" ");

				System.out.print(notes[i]);
			}
			
		}

		System.out.println();
	}
	
	void Run() {
		InputStream inStream = System.in;

		/*
		try {
			inStream = new FileInputStream(
					"D:\\PersonalCode\\Algorithms\\UVA\\10528\\Test.txt");
		} catch (Exception e) {

		}
		*/

		Scanner s = new Scanner(inStream);


		String[] notes =  new String[] {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
		List<Set<String>> majorLists = GenerateMajorList(notes); 

		while(s.hasNextLine())
		{
			String line = s.nextLine();

			if (line.equals("END"))
				break;

			StringTokenizer tokens = new StringTokenizer(line);

			Set<String> distinctNotes = new HashSet<String>();

			while(tokens.hasMoreTokens())
				distinctNotes.add(tokens.nextToken());

			Process(notes, majorLists, distinctNotes);
		}

		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
