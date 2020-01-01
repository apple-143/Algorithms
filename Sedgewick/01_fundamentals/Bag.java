import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.In;

import java.util.Iterator;

public class Bag<Item> implements Iterable<Item>
{
	private Node first;

	private class Node
	{
		Item item;
		Node next = null;
	}

	public Bag()
	{ first = null; }

	public void add(Item item)
	{
		Node oldfirst = first;
		first = new Node();
		first.item = item;
		first.next = oldfirst;
	}

	public Iterator<Item> iterator()
	{ return new ListIterator(); }

	private class ListIterator implements Iterator<Item>
	{
		private Node current = first;

		public boolean hasNext()
		{ return current != null; }

		public Item next()
		{
			Item item = current.item;
			current = current.next;
			return item;
		}

		public void remove() {}
	}

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
