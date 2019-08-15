#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::cin;

/* TODO
	- Keys

DONE
	- Get, Put, Min, Floor, Max, Ceiling, Select, Rank, Size, DeleteMin, DeleteMax, Delete
	- delete node dynamically made
	- PrintTree
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
	Value Get(Node * x, Key key)
	{
		if (x == nullptr)
			throw -1;

		if		(key < x->key)	return Get(x->left, key);
		else if	(x->key < key)	return Get(x->right, key);
		else					return x->val;
	}

	Node * Min(Node * x)
	{
		if (x->left == nullptr)
			return x;
		return Min(x->left);
	}
	Node * Max(Node * x)
	{
		if (x->right == nullptr)
			return x;
		return Max(x->right);
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

	Node * Select(Node * x, int k)
	{
		if (x == nullptr)
			throw -1;
		int t = Size(x->left);
		if		(k < t)	return Select(x->left, k);
		else if	(t < k)	return Select(x->right, k-t-1);
		else			return x;
	}
	int Rank(Node * x, Key key)
	{
		if (x == nullptr) return 0;

		if		(key < x->key)	return Rank(x->left, key);
		else if	(x->key < key)	return Rank(x->right, key) + Size(x->left) + 1;
		else					return Size(x->left);
	}

	Node * DeleteMin(Node * x)
	{
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
	Node * DeleteMax(Node * x)
	{
		if (x->right == nullptr)
		{
			Node * tmp;
			tmp = x->left;
			delete x;
			return tmp;
		}

		x->right = DeleteMax(x->right);
		x->num = Size(x->left) + Size(x->right) + 1;
		return x;
	}
	Node * Delete(Node * x, Key key)
	{
		if (x == nullptr)
			return nullptr;

		if		(x->key < key)	x->right = Delete(x->right, key);
		else if	(key < x->key)	x->left = Delete(x->left, key);
		else	//(x->key == key)
		{
			if (x->left == nullptr)
			{
				Node * tmp = x->right;
				delete x;
				return tmp;
			}
			if (x->right == nullptr)
			{
				Node * tmp = x->left;
				delete x;
				return tmp;
			}

			Node * t = x;
			x = Min(t->right);
			x->right = DeleteMin(t->right);
			x->left = t->left;
		}

		x->num = Size(x->left) + Size(x->right) + 1;
		return x;
	}

	int Size(Node * node)
	{ return node == nullptr ? 0 : node->num; }

	std::vector<Key> Keys(Key lo, Key hi)
	{
		std::vector<Key> key_vec;
		Keys(root_, key_vec, lo, hi);
		return key_vec;
	}
	void Keys(Node * x, std::vector<Key>& key_vec, Key lo, Key hi)
	{
		key_vec.push_back(lo);
	}

	void PrintTree(Node * x)
	{
		if (x == nullptr)
			return;
		PrintTree(x->left);
		cout << x->key << "  ";
		PrintTree(x->right);
	}

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
	Value Get(Key key)
	{ return Get(root_, key); }

	Key Min()
	{ return Min(root_)->key; }
	Key Max()
	{ return Max(root_)->key; }

	Key Floor(Key key)
	{
		Node * x = Floor(root_, key);
		if (x == nullptr)
			throw -1;
		return x->key;
	}
	Key Ceiling(Key key)
	{
		Node * x = Ceiling(root_, key);
		if (x == nullptr)
			throw -1;
		return x->key;
	}

	Key Select(int k)
	{ return Select(root_, k)->key; }
	int Rank(Key key)
	{ return Rank(root_, key); }

	void DeleteMin()
	{ root_ = DeleteMin(root_); }
	void DeleteMax()
	{ root_ = DeleteMax(root_); }
	void Delete(Key key)
	{ root_ = Delete(root_, key); }

	bool IsEmpty()
	{ return root_ == nullptr; }

	int Size()
	{ return Size(root_); }

	std::vector<Key> Keys()
	{ return Keys(Min(), Max()); }

	void PrintTree()
	{ PrintTree(root_); }

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
	cout << "BST: ";
	st.PrintTree();
	cout << endl;
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
	cout << "min: " << st.Min() << endl;
	st.DeleteMin(); cout << "DeleteMin()" << endl;
	cout << "min: " << st.Min() << endl;
	cout << "BST: ";
	st.PrintTree();
	cout << endl;
	cout << endl;


	cout << "DeleteMax Function\n";
	cout << "max: " << st.Max() << endl;
	st.DeleteMax(); cout << "DeleteMax()" << endl;
	cout << "max: " << st.Max() << endl;
	cout << "BST: ";
	st.PrintTree();
	cout << endl;
	cout << endl;

	cout << "Delete Function\n";
	st.PrintTree();
	cout << endl;
	st.Delete("b"); cout << "Delete(\"b\")" << endl;
	st.PrintTree();
	cout << endl;
	cout << endl;

	cout << "Keys Function\n";
	for (auto each_key : st.Keys())
		cout << each_key << " => " << st.Get(each_key) << endl;
	cout << endl;

	return 0;
}
