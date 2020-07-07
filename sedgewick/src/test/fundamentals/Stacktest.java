package fundamentals;

import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.In;

import fundamentals.Stack;

public class Stacktest {
    public static void main(String[] args)
    {
        Stack<String> s = new Stack<String>();

        while(!StdIn.isEmpty())
        {
            String item = StdIn.readString();
            if(!item.equals("-"))
                s.push(item);
            else if (!s.isEmpty()) StdOut.print(s.pop() + " ");
        }
        StdOut.println("(" + s.size() + " left on stack)");
        for (String st : s)
            StdOut.print(st + " ");
        StdOut.println();
    }
}
