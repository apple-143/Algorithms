#include <iostream>
#include <vector>

using namespace std;

namespace Insertion
{
	template <typename Comparable>
	bool less(Comparable v, Comparable w)
	{
		return v < w;
	}

	template <typename RandomAccessIterator>
	void exch(RandomAccessIterator& begin, const int& i, const int& j)
	{
		auto tmp = *(begin + i);
		*(begin + i) = *(begin + j);
		*(begin + j) = tmp;
	}

	template <typename RandomAccessIterator>
	void sort(RandomAccessIterator begin, RandomAccessIterator end)
	{
		for (RandomAccessIterator i = begin+1; i != end; ++i)
		{
			for (RandomAccessIterator j = i; j != begin; --j)
				if (less(*j, *(j-1)))
					exch(begin, j-begin, j-1-begin);
				else
					break;
		}
	}

	template <typename RandomAccessIterator, typename Comp>
	void sort(RandomAccessIterator begin, RandomAccessIterator end, Comp comp)
	{
		for (RandomAccessIterator i = begin+1; i != end; ++i)
		{
			for (RandomAccessIterator j = i; j != begin; --j)
				if (comp(*j, *(j-1)))
					exch(begin, j-begin, j-1-begin);
				else
					break;
		}
	}
}


class CustomCompare
{
private:
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

void print_vector(vector<int> a)
{
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;
}


int main()
{
	vector<int> a;
	a.push_back(5);
	a.push_back(2);
	a.push_back(9);
	a.push_back(4);
	a.push_back(3);
	a.push_back(1);

	print_vector(a);

	Insertion::sort(a.begin(), a.end());
	print_vector(a);

	CustomCompare my_compare;
	Insertion::sort(a.begin(), a.end(), my_compare);
	print_vector(a);

	return 0;
}
