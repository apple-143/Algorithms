#ifndef SW_SEQUENTIAL_SEARCH
#define SW_SEQUENTIAL_SEARCH

/*TODO
	- make other member functions that Symbol Table needs
	- Delete, Contains
	- Keys

*/


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
	}

	void Put(Key key, Value value)
	{
		num_++;
		for (Node * i = first_; i != nullptr; i = i->next_)
			if (i->key_ == key)
			{ i->value_ = value; return; }

		first_ = new Node(key, value, first_);
		return;
	}

	void Delete(Key key)
	{
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

#endif /* SW_SEQUENTIAL_SEARCH */
