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
}
