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
	int N_ = 0;

public:
	SequentialSearchST()
	{
	}

	Node * get(Key key)
	{
		for(Node * i = first_; i != nullptr; i = i->next_)
			if (i->key_ == key)
				return i;

		return nullptr;
	}

	void put(Key key, Value value)
	{
		N_++;
		for (Node * i = first_; i != nullptr; i = i->next_)
			if (i->key_ == key)
			{ i->value_ = value; return; }

		first_ = new Node(key, value, first_);
		return;
	}

	int getNum()
	{ return N_; }


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

int main(int argc, char * argv[])
{
	int minlen;

	if (argc == 1)
		minlen = 5;
	else
		minlen = atoi(argv[1]);

	SequentialSearchST<string, int> st;

	while (!(cin.eof() || cin.fail()))
	{
		string word;
		cin >> word;

		if (word.size() < minlen)
			continue;
		if (st.get(word) == nullptr)
			st.put(word, 1);
		else
			st.put(word, st.get(word)->value_ + 1);
	}

	string max;
	st.put(max, 0);

	for (SequentialSearchST<string, int>::Node * i = st.first_; i != nullptr; i = i->next_)
	{
		if (i->value_ > st.get(max)->value_)
			max = i->key_;
	}

	cout << max << ": " << st.get(max)->value_ << endl;

	return 0;
}
