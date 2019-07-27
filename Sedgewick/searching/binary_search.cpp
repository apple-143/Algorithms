#include <iostream>
#include <string>

using namespace std;

/*TODO
	- Put, Get, Delete, Contains, Keys
	- guarantee that Key is comparable
	- resize ST
*/

template <typename Key, typename Value>
class BinarySearchST
{
private:
	Key *keys_;
	Value *vals_;
	int num_ = 0;

public:
	BinarySearchST()
	{
		keys_ = new Key[4];
		vals_ = new Value[4];
	}


	BinarySearchST(int capacity)
	{
		keys_ = new Key[capacity];
		vals_ = new Value[capacity];
	}

	int Size()
	{ return num_; }

	void Put(Key key, Value val)
	{
	}

	Value Get(Key key)
	{}

	void Delete(Key key)
	{}

	bool Contains(Key key)
	{}

	bool IsEmpty()
	{ return num_ == 0; }

/*
	? Keys()
	{}
*/

	~BinarySearchST()
	{
		delete[] keys_;
		delete[] vals_;
	}
};


int main()
{
	BinarySearchST<string, int> st;

	cout << st.Size() << endl;

	return 0;
}
