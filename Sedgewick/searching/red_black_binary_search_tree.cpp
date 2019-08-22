#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::cin;

/* TODO
	- PrintTreeStructure(need to edit)
 	- DeleteMin, DeleteMax, Delete

DONE
	- Keys
	- Node
	- Min, Floor, Max, Ceiling, Select, Rank, Get, Size, Put, IsEmpty
	- RotateLeft, RotateRight, FlipColor
	- PrintTree
	- delete node dynamically made
*/

template <typename Key, typename Value>
class RedBlackBST
{
private:
	struct Node
	{
		Key key;
		Value val;
		Node * left = nullptr;
		Node * right = nullptr;
		int num = 1;
		bool color;

		Node(Key key, Value val, int num, bool color)
		{
			this->key = key;
			this->val = val;
			this->num = num;
			this->color = color;
		}
	};

	bool RED = true;
	bool BLACK = false;

	bool IsRed(Node * x)
	{
		if (x == nullptr)	return false;
		return x->color == RED;
	}

	Node * root_ = nullptr;


	int Size(Node * x)
	{ return x == nullptr ? 0 : x->num; }


	Node * RotateLeft(Node * h)
	{
		Node * x = h->right;
		h->right = x->left;
		x->left = h;
		x->color = h->color;
		h->color = RED;
		x->num = h->num;
		h->num = Size(h->left) + Size(h->right) + 1;
		return x;
	}

	Node * RotateRight(Node * h)
	{
		Node * x = h->left;
		h->left = x->right;
		x->right = h;
		x->color = h->color;
		h->color = RED;
		x->num = h->num;
		h->num = Size(h->left) + Size(h->right) + 1;
		return x;
	}

	void FlipColor(Node * h)
	{
		h->color = RED;
		h->left->color = BLACK;
		h->right->color = BLACK;
	}


	Node * Put(Node * h, Key key, Value val)
	{
		if (h == nullptr)
			return new Node(key, val, 1, RED);

		if		(key < h->key)	h->left = Put(h->left, key, val);
		else if	(h->key < key)	h->right = Put(h->right, key, val);
		else					h->val = val;

		if	(IsRed(h->right) && !IsRed(h->left))		h = RotateLeft(h);
		if	(IsRed(h->left) && IsRed(h->left->left))	h = RotateRight(h);
		if	(IsRed(h->left) && IsRed(h->right))			FlipColor(h);

		h->num = Size(h->left) + Size(h->right) + 1;
		return h;
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
			if (x->right == nullptr)
			{
				delete x;
				return nullptr;
			}
			else if (!IsRed(x->right->left))
			{
				Node * tmp;
				tmp = x->right;
				tmp->color = x->color;
				delete x;
				return tmp;
			}
			else // if (x->right != nullptr && IsRed(x->right->left))
			{
				Node * tmp;
				tmp = x->right;
				delete x;
			}
		}

		x->left = DeleteMin(x->left);

		if	(IsRed(x->right) && !IsRed(x->left))		x = RotateLeft(x);
		if	(IsRed(x->left) && IsRed(x->left->left))	x = RotateRight(x);
		if	(IsRed(x->left) && IsRed(x->right))			FlipColor(x);

		x->num = Size(x->left) + Size(x->right) + 1;

		return x;
	}
	Node * DeleteMax(Node * x)
	{
/*
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
*/
	}
	Node * Delete(Node * x, Key key)
	{
/*
		if (x == nullptr)
			return nullptr;

		if		(x->key < key)	x->right = Delete(x->right, key);
		else if	(key < x->key)	x->left = Delete(x->left, key);
		else	//(x->key == key)
		{
			if (x->left == nullptr)
			{
				Node * tmp = x->right;
				tmp->color = x->color;
				delete x;
				return tmp;
			}
			if (x->right == nullptr)
			{
				Node * tmp = x->left;
				tmp->color = x->color;
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
*/
	}

	void Keys(Node * x, std::vector<Key>& key_vec, Key lo, Key hi)
	{
		if (x == nullptr)
			return;

		if (lo < x->key)						Keys(x->left, key_vec, lo, hi);
		if (!(x->key < lo) && !(hi < x->key))	key_vec.push_back(x->key);
		if (x->key < hi)						Keys(x->right, key_vec, lo, hi);
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
	RedBlackBST()
	{}

	void Put(Key key, Value val)
	{
		root_ = Put(root_, key, val);
		root_->color = BLACK;
	}
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
	std::vector<Key> Keys(Key lo, Key hi)
	{
		std::vector<Key> key_vec;
		Keys(root_, key_vec, lo, hi);
		return key_vec;
	}

	void PrintTree()
	{ PrintTree(root_); }

	void PushData(Node * x, std::vector<Key>& container, int height, int col)
	{
		if (x == nullptr)
			return;

		container[(1<<(height-1)) + col] = x->key;
		PushData(x->left, container, height + 1, col * 2);
		PushData(x->right, container, height + 1, col * 2 + 1);
	}

	void PrintTreeStructure()
	{
		int total_num = root_->num;
		int height = 1 + 2;
		//while (true)
		for (int i = 0; i < 10; i++)
		{
			if (total_num = total_num>>1)
				++height;
			else
				break;
		}

		std::vector<Key> print_ordered_key(1<<height, " ");

		PushData(root_, print_ordered_key, 1, 0);

		for (int h = 1; h < height; h++)
		{
			for (int c = 0; c < (1<<(h-1)); c++)
				cout << print_ordered_key[(1<<(h-1)) + c] << "   ";
			cout << endl;
		}
	}

	~RedBlackBST()
	{ DeleteNode(root_); }
};
int main()
{
	RedBlackBST<std::string, int> st;

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
	cout << "BST: \n";
	st.PrintTreeStructure();
	cout << endl;
	cout << endl;

	cout << "Get Function\n";
	cout << "a: " << st.Get("a") << endl;
	cout << "b: " << st.Get("b") << endl;
	st.PrintTree();
	cout << endl;

	cout << "Min/Max Function\n";
	cout << "Min: " << st.Min() << endl;
	cout << "Max: " << st.Max() << endl;
	st.PrintTree();
	cout << endl;

	cout << "Floor/Ceiling Function\n";
	cout << "Floor of f: " << st.Floor("f") << endl;
	cout << "Ceiling of c: " << st.Ceiling("c") << endl;
	st.PrintTree();
	cout << endl;


	cout << "Select Function\n";
	for (int i = 0; i < st.Size(); i++)
		cout << "Select " << i << ": " <<st.Select(i) << endl;
	st.PrintTree();
	cout << endl;

	cout << "Rank Function\n";
	cout << "Rank of a: " << st.Rank("a") << endl;
	cout << "Rank of b: " << st.Rank("b") << endl;
	cout << "Rank of c: " << st.Rank("c") << endl;
	cout << "Rank of d: " << st.Rank("d") << endl;
	cout << "Rank of e: " << st.Rank("e") << endl;
	cout << "Rank of f: " << st.Rank("f") << endl;
	cout << "Rank of g: " << st.Rank("g") << endl;
	st.PrintTree();
	cout << endl;

	cout << "BST: \n";
	st.PrintTreeStructure();
	cout << "DeleteMin Function\n";
	cout << "min: " << st.Min() << endl;
	st.DeleteMin(); cout << "DeleteMin()" << endl;
	cout << "min: " << st.Min() << endl;
	cout << "BST: \n";
	st.PrintTreeStructure();
	cout << endl;
	cout << endl;

/*
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

*/
/*
	st.Put("b", 2);
	st.Put("a", 1);
	st.Put("e", 5);
	st.Put("d", 4);
	st.Put("g", 7);
	st.Put("a", 11);
	st.Put("h", 12);
	st.Put("i", 13);
	st.Put("j", 14);
	
	cout << "Keys Function\n";
	cout << "All keys\n";
	for (auto each_key : st.Keys())
		cout << each_key << " => " << st.Get(each_key) << endl;
	cout << "Between b, e\n";
	for (auto each_key : st.Keys("b", "e"))
		cout << each_key << " => " << st.Get(each_key) << endl;
	st.PrintTree();
	cout << endl;

*/
/*
	st.Put("h", 1);
	st.Put("g", 1);
	st.Put("f", 1);
	st.Put("e", 1);
	st.Put("d", 1);
	st.Put("c", 1);
	st.Put("b", 1);
	st.Put("a", 1);
	st.PrintTree();
	cout << endl;
*/
/*
	st.DeleteMin();
	st.PrintTree();
	cout << endl;
*/


	return 0;
}







