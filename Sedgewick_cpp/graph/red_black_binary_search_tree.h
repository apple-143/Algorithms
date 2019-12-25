#ifndef REDBLACK_BST_TW_H_
#define REDBLACK_BST_TW_H_

#include <iostream>
#include <vector>

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
			Node * tmp;
			tmp = x->right;
			if (tmp != nullptr)
				tmp->color = x->color;
			delete x;
			return tmp;
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
		if (x->right == nullptr)
		{
			Node * tmp;
			tmp = x->left;
			if (tmp != nullptr)
				tmp->color = x->color;
			delete x;
			return tmp;
		}

		x->right = DeleteMax(x->right);

		if	(IsRed(x->right) && !IsRed(x->left))		x = RotateLeft(x);
		if	(IsRed(x->left) && IsRed(x->left->left))	x = RotateRight(x);
		if	(IsRed(x->left) && IsRed(x->right))			FlipColor(x);

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
				if (tmp != nullptr)
					tmp->color = x->color;
				delete x;
				return tmp;
			}
			if (x->right == nullptr)
			{
				Node * tmp = x->left;
				if (tmp != nullptr)
					tmp->color = x->color;
				delete x;
				return tmp;
			}

			Node * tmp = Min(x->right);
			x->key = tmp->key;
			x->val = tmp->val;
			x->right = DeleteMin(x->right);
		}

		if	(IsRed(x->right) && !IsRed(x->left))		x = RotateLeft(x);
		if	(IsRed(x->left) && IsRed(x->left->left))	x = RotateRight(x);
		if	(IsRed(x->left) && IsRed(x->right))			FlipColor(x);

		x->num = Size(x->left) + Size(x->right) + 1;

		return x;
	}

	void Keys(Node * x, std::vector<Key>& key_vec, Key lo, Key hi)
	{
		if (x == nullptr)
			return;

		if (lo < x->key)						Keys(x->left, key_vec, lo, hi);
		if (!(x->key < lo) && !(hi < x->key))	key_vec.push_back(x->key);
		if (x->key < hi)						Keys(x->right, key_vec, lo, hi);
	}

	void DeleteNode(Node * node)
	{
		if (node == nullptr)
			return;

		DeleteNode(node->left);
		DeleteNode(node->right);
		delete node;
	}

	void PrintTree(Node * x)
	{
		if (x == nullptr)
			return;
		PrintTree(x->left);
		std::cout << x->key << "  ";
		PrintTree(x->right);
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
	bool Contains(Key key)
	{
		try {
			Get(root_, key);
			return true;
		} catch (int err) {
			return false;
		}
		
	}

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

	void PushData(Node * x, std::vector<Key>& container, int height, int col)
	{
		if (x == nullptr)
			return;

		container[(1<<(height-1)) + col] = x->key;
		PushData(x->left, container, height + 1, col * 2);
		PushData(x->right, container, height + 1, col * 2 + 1);
	}

	void PrintTree()
	{ PrintTree(root_); }
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
			std::string padding;
			for (int i = 0; i < (1<<(height - h)) - 1; i++)
				padding += " ";
			for (int c = 0; c < (1<<(h-1)); c++)
				std::cout << print_ordered_key[(1<<(h-1)) + c] << padding;
			std::cout << std::endl;
		}
	}

	~RedBlackBST()
	{ DeleteNode(root_); }
};

#endif	// REDBLACK_BST_TW_H_
