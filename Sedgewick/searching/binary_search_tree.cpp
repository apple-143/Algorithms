#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

/* TODO
	- Contains, Delete, Size, Keys

DONE
	- Get, Put
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
		int num = 1;

		Node(Key new_key, Value new_val) : key(new_key), val(new_val)
		{}
	};

	Node * root_ = nullptr;

public:
	BinarySearchTreeST()
	{ }

	int Size(Node * node)
	{ return node == nullptr ? 0 : node->num; }

	void Put(Key key, Value val)
	{	root_ = Put(root_, key, val); }

	Node * Put(Node * x, Key key, Value val)
	{
		if (x == nullptr)
			return new Node(key, val);

		if		(key < x->key)	x->left = Put(x->left, key, val);
		else if	(x->key < key)	x->right = Put(x->right, key, val);
		else					x->val = val;

		x->num = Size(x->left) + Size(x->right) + 1;
		return x;
	}


	Value Get(Key key)
	{ return Get(root_, key); }

	Value Get(Node * x, Key key)
	{
		if (x == nullptr)
			throw -1;

		if		(key < x->key)	return Get(x->left, key);
		else if	(x->key < key)	return Get(x->right, key);
		else					return x->val;
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

/*
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

























