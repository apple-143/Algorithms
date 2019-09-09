#include <iostream>
#include <string>

using namespace std;


template <typename Key, typename Value>
class SequentialSearchST
{
public:
	class Node
	{
	private:
	public:
		Key key_;
		Value value_;
		Node * next_;

		Node(Key key, Value value, Node * next) : key_(key), value_(value), next_(next)
		{ }

	};
	Node * first_ = nullptr;

private:
	int num_ = 0;

public:
	SequentialSearchST()
	{}


	Value Get(Key key)
	{
		for(Node * i = first_; i != nullptr; i = i->next_)
			if (i->key_ == key)
				return i->value_;

		throw -1;
	}

	bool Contains(Key key)
	{
		for (Node * i = first_; i != nullptr; i = i->next_)
			if (i->key_ == key)
				return true;

		return false;
	}

	void Put(Key key, Value value)
	{
		for (Node * i = first_; i != nullptr; i = i->next_)
			if (i->key_ == key)
			{ i->value_ = value; return; }

		first_ = new Node(key, value, first_);
		num_++;
		return;
	}

	void Delete(Key key)
	{
		Node * tmp;
		if (first_->key_ == key)
		{
			tmp = first_;
			first_ = first_->next_;
			delete tmp;
			--num_;

			return;
		}

		for (Node * i = first_; i != nullptr; i = i->next_)
		{
			if (i->next_->key_ == key)
			{
				tmp = i->next_;
				i->next_ = i->next_->next_;
				delete tmp;
				--num_;

				return;
			}
		}
	}

	int Size()
	{ return num_; }

	bool IsEmpty()
	{ return num_ == 0; }

	void Keys()
	{
	}

	~SequentialSearchST()
	{
		Node * tmp;

		while (first_ != nullptr)
		{
			tmp = first_;
			first_ = first_->next_;

			delete tmp;
		}
	}
};


template <typename Key, typename Value>
class SeparateChainingHashST
{
private:
	int M_;
	int hash(Key key)
	{ return 0; }

public:
	SeparateChainingHashST()
	{
		SequentialSearchST<Key, Value> hashtable[100];
	}


	~SeparateChainingHashST()
	{}
};


template <int Size>
class HashInt
{
private:
	int i = 0;

public:
	HashInt()
	{}

	int Value() const
	{ return this->i; }

	int HashCode()
	{ return this->i % Size; }

	HashInt& operator=(const int j)
	{
		this->i = j;
		return *this;
	}

	bool operator<(const HashInt x)
	{ return this->i < x.i; }
	bool operator<=(const HashInt x)
	{ return this->i <= x.i; }

	bool operator>(const HashInt x)
	{ return this->i > x.i; }
	bool operator>=(const HashInt x)
	{ return this->i >= x.i; }

	bool operator==(const HashInt x)
	{ return this->i == x.i; }

	~HashInt()
	{}
};

template <int Size>
ostream& operator<<(ostream &os, const HashInt<Size> &x)
{
	os << x.Value();
	return os;
}


int main()
{
	SeparateChainingHashST<int, int> st;

	HashInt<100> a;

	a.operator=(105);

	std::cout << a << std::endl;

	std::cout << a.HashCode() << std::endl;




	return 0;
}






















