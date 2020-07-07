package fundamentals;

import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.In;

import fundamentals.Queue;

class Queuetest {
    public static void main(String[] args) {
        Queue<String> s = new Queue<String>();

		while(!StdIn.isEmpty())
		{
			String item = StdIn.readString();
			s.enqueue(item);
		}

		for (String st : s)
			StdOut.print(st + " ");
		StdOut.println();
	}
}
