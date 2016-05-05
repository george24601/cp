import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.Arrays;

/* UVA 10341 Solve It
 * simple binary search
 */
class Main {

	int p, q, r, s, t, u;

	double Eval(double x) {
		return p * Math.exp(-1 * x) + q * Math.sin(x) + r * Math.cos(x) + s
				* Math.tan(x) + t * x * x + u;
	}

	void Print(double val)
	{
		double newVal = ((double)((long) (val * 10000)))/ 10000; 
		System.out.println(String.format("%.4f", newVal));
	}

	void Process_r(double low, double high) {
		if (high - low < 0.0001) {
			Print (high);
			return;
		}
		
		if (Eval(low) == 0)
		{
			Print(low);
			return;
			
		}else if (Eval(high) == 0)
		{
			Print(high);
			return;
		}

		double mid = (high + low) / 2;

		if (Eval(mid) > 0) {

			Process_r(mid, high);
		} else if (Eval(mid) < 0) {
			Process_r(low, mid);
		}else
		{
			Print(mid);
		}
	}

	void Run() {
		InputStream inStream = System.in;

		try {
	//		inStream = new FileInputStream(
	//				"C:\\Users\\user\\PersonalCode\\Algorithms\\UVA\\10341\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			while (st.nextToken() != st.TT_EOF) {
				p = (int) st.nval;
				st.nextToken();
				q = (int) st.nval;
				st.nextToken();
				r = (int) st.nval;
				st.nextToken();
				s = (int) st.nval;
				st.nextToken();
				t = (int) st.nval;
				st.nextToken();
				u = (int) st.nval;

				if (Eval(0) < 0 || Eval(1) > 0)
					System.out.println("No solution");
				else
					Process_r(0, 1);

			}

		} catch (IOException e) {

		}
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
