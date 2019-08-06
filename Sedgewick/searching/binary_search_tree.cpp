#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

/* TODO
	- Put, Get, Contains, Delete, Size, Keys

DONE
*/

template <typename Key, typename Value>
class BinarySearchTreeST
{
private:
	struct Node
	{
		Key key;
		Value val;
		Node * left = nullptr;
		Node * right = nullptr;
		int num = 0;

		Node(Key new_key, Value new_val) : key(new_key), val(new_val)
		{}
	};

	Node * root_;

public:
	BinarySearchTreeST() : root_(nullptr)
	{ }

	void Put(Key key, Value val)
	{
	}

	void Put(Node * x, Key key, Value val)
	{
	}


	Value Get(Key key)
	{ return Get(root_, key); }

	Value Get(Node * x, Key key)
	{
		if (x == nullptr)
			throw -1;

		if		(key < x.key)	return Get(x.left, key);
		else if	(x.key < key)	return Get(x.right, key);
		else					return x.val;
	}

	bool Contains(Key key)
	{
	}

	void Delete(Key key)
	{
	}

	bool IsEmpty()
	{ return root_ == nullptr; }

	int Size()
	{ }

	void Keys()
	{ }

	~BinarySearchTreeST()
	{
	}
};

int main()
{
	BinarySearchTreeST<std::string, int> st;

/*
	st.Put("f", 6);
	st.Put("b", 2);
	st.Put("c", 3);
	st.Put("a", 1);
	st.Put("e", 5);
	st.Put("d", 4);
	st.Put("g", 7);
	st.Put("a", 11);

	cout << "a: " << st.Get("a") << endl;
	cout << "b: " << st.Get("b") << endl;

	if (st.Contains("a"))
		cout << "table has key \"a\"" << endl;
	else
		cout << "table doesn't have key \"a\"" << endl;

	st.Delete("a");
	if (st.Contains("a"))
		cout << "table has key \"a\"" << endl;
	else
		cout << "table doesn't have key \"a\"" << endl;

	if (st.IsEmpty())
		cout << "table is empty" << endl;
	else
		cout << "table is not empty" << endl;

	cout << "table size is " << st.Size() << endl;


	for (;;)
	{
		break;
	}
*/

	return 0;
}

























