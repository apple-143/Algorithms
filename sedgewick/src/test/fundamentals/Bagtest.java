package fundamentals;

import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.In;

import fundamentals.Bag;

public class Bagtest {
	public static void main(String[] args)
	{
		Bag<String> s = new Bag<String>();

		while(!StdIn.isEmpty())
		{
			String item = StdIn.readString();
			s.add(item);
		}

		for (String st : s)
			StdOut.print(st + " ");
		StdOut.println();
	}
}
