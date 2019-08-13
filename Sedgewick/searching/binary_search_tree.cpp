#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

/* TODO
	- Delete, DeleteMax, Keys

DONE
	- Get, Put, Min, Floor, Max, Ceiling, Select, Rank, Size, DeleteMin
	- delete node dynamically made
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

	int Size(Node * node)
	{ return node == nullptr ? 0 : node->num; }

	void DeleteNode(Node * node)
	{
		if (node == nullptr)
			return;

		DeleteNode(node->left);
		DeleteNode(node->right);
		delete node;
	}

public:
	BinarySearchTreeST()
	{ }


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


	Key Min()
	{ return Min(root_)->key; }

	Node * Min(Node * x)
	{
		if (x->left == nullptr)
			return x;
		return Min(x->left);
	}

	Key Max()
	{ return Max(root_)->key; }

	Node * Max(Node * x)
	{
		if (x->right == nullptr)
			return x;
		return Max(x->right);
	}


	Key Floor(Key key)
	{
		Node * x = Floor(root_, key);
		if (x == nullptr)
			throw -1;
		return x->key;
	}

	Node * Floor(Node * x, Key key)
	{
		if (x == nullptr)
			return nullptr;

		if (x->key == key)
			return x;

		if (key < x->key)
			return Floor(x->left, key);

		Node * t = Floor(x->right, key);
		if (t != nullptr)
			return t;
		else
			return x;	
	}

	Key Ceiling(Key key)
	{
		Node * x = Ceiling(root_, key);
		if (x == nullptr)
			throw -1;
		return x->key;
	}

	Node * Ceiling(Node * x, Key key)
	{
		if (x == nullptr)
			return nullptr;

		if (x->key == key)
			return x;

		if (x->key < key)
			return Ceiling(x->right, key);

		Node * t = Ceiling(x->left, key);
		if (t != nullptr)
			return t;
		else
			return x;
	}


	Key Select(int k)
	{ return Select(root_, k)->key; }

	Node * Select(Node * x, int k)
	{
		if (x == nullptr)
			throw -1;
		int t = Size(x->left);
		if		(k < t)	return Select(x->left, k);
		else if	(t < k)	return Select(x->right, k-t-1);
		else			return x;
	}

	int Rank(Key key)
	{ return Rank(root_, key); }

	int Rank(Node * x, Key key)
	{
		if (x == nullptr) return 0;

		if		(key < x->key)	return Rank(x->left, key);
		else if	(x->key < key)	return Rank(x->right, key) + Size(x->left) + 1;
		else					return Size(x->left);
	}

	void DeleteMin()
	{ root_ = DeleteMin(root_); }

	Node * DeleteMin(Node * x)
	{
	/*
		if (x->left == nullptr)
			return x->right;
		x->left = DeleteMin(x->left);
		x->num = Size(x->left) + Size(x->right) + 1;
		return x;
	*/

		if (x->left == nullptr)
		{
			Node * tmp;
			tmp = x->right;
			delete x;
			return tmp;
		}

		x->left = DeleteMin(x->left);
		x->num = Size(x->left) + Size(x->right) + 1;
		return x;
	}

	void DeleteMax()
	{ root_ = DeleteMax(root_); }

	Node * DeleteMax(Node * x)
	{}

	void Delete(Key key)
	{ root_ = Delete(root_, key); }

	void Delete(Node * x, Key key)
	{
	}


	bool IsEmpty()
	{ return root_ == nullptr; }

	int Size()
	{ return Size(root_); }

	void Keys()
	{ }

	~BinarySearchTreeST()
	{ DeleteNode(root_); }
};

int main()
{
	BinarySearchTreeST<std::string, int> st;

	cout << "Size Function\n";
	cout << st.Size() << endl;
	st.Put("b", 2);
	cout << st.Size() << endl;
	st.Put("a", 1);
	cout << st.Size() << endl;
	st.Put("e", 5);
	cout << st.Size() << endl;
	st.Put("d", 4);
	cout << st.Size() << endl;
	st.Put("g", 7);
	cout << st.Size() << endl;
	st.Put("a", 11);
	cout << st.Size() << endl;
	cout << endl;

	cout << "Get Function\n";
	cout << "a: " << st.Get("a") << endl;
	cout << "b: " << st.Get("b") << endl;
	cout << endl;

	cout << "Min/Max Function\n";
	cout << st.Min() << endl;
	cout << st.Max() << endl;
	cout << endl;

	cout << "Floor/Ceiling Function\n";
	cout << st.Floor("f") << endl;
	cout << st.Ceiling("c") << endl;
	cout << endl;


	cout << "Select Function\n";
	for (int i = 0; i < st.Size(); i++)
		cout << st.Select(i) << endl;
	cout << endl;

	cout << "Rank Function\n";
	cout << st.Rank("a") << endl;
	cout << st.Rank("b") << endl;
	cout << st.Rank("c") << endl;
	cout << st.Rank("d") << endl;
	cout << st.Rank("e") << endl;
	cout << st.Rank("f") << endl;
	cout << st.Rank("g") << endl;
	cout << endl;

	cout << "DeleteMin Function\n";
	cout << st.Min() << endl;
	st.DeleteMin();
	cout << st.Min() << endl;
	cout << endl;
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

























