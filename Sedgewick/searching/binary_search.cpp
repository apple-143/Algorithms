#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
/*TODO
	- Keys
	- guarantee that Key is comparable
	- resize ST

DONE
	- Rank, Put, Get, Delete, Contains
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
		keys_ = new Key[16];
		vals_ = new Value[16];
	}


	BinarySearchST(int capacity)
	{
		keys_ = new Key[capacity];
		vals_ = new Value[capacity];
	}

	int Size()
	{ return num_; }

	int Rank(Key key)
	{
		int lo=0, hi=num_-1, mid;
		while (lo <= hi)
		{
			mid = (lo + hi) / 2;
			if (keys_[mid] > key)
				hi = mid-1;
			else if (keys_[mid] < key)
				lo = mid+1;
			else //if (keys_[mid] == key)
				return mid;
		}

		return lo;
	}

	void Put(Key key, Value val)
	{
		int i = Rank(key);
		if (i < num_ && keys_[i] == key)
		{
			vals_[i] = val;
			return;
		}
		else
		{
			for (int j = num_; j > i; j--)
			{
				keys_[j] = keys_[j-1];
				vals_[j] = vals_[j-1];
			}
			keys_[i] = key;
			vals_[i] = val;
			num_++;
		}
	}

	Value Get(Key key)
	{
		if (IsEmpty())
			throw -1;

		int i = Rank(key);
		if (i < num_ && keys_[i] == key)
			return vals_[i];
		else
			throw -1;
	}

	void Delete(Key key)
	{
		int i = Rank(key);

		if (i < num_ && keys_[i] == key)
		{
			for (int j = i; j < num_; j++)
			{
				keys_[j] = keys_[j+1];
				vals_[j] = vals_[j+1];
			}
			num_--;
		}
		else
			return;
	}

	bool Contains(Key key)
	{
		int i = Rank(key);
		if(i < num_ && keys_[i] == key)
			return true;
		else
			return false;
	}

	bool IsEmpty()
	{ return num_ == 0; }

	void Keys()
	{}


	~BinarySearchST()
	{
		delete[] keys_;
		delete[] vals_;
	}
};

int main()
{
	BinarySearchST<std::string, int> st;

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

	return 0;
}



















