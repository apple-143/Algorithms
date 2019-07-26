#include <iostream>
#include <vector> 

using namespace std;

namespace heap
{
	class DefaultCompare
	{
	private:
	public:
		template <typename Comparable>
		bool operator()(const Comparable& v, const Comparable& w)
		{
			return v < w;
		}
	};

	template <typename RandomAccessIterator>
	void exch(RandomAccessIterator begin, const int& i, const int& j)
	{
		auto tmp = *(begin + i - 1);
		*(begin + i - 1) = *(begin + j - 1);
		*(begin + j - 1) = tmp;
	}


	template <typename RamdomAccessIterator, typename Comp>
	void sink(RamdomAccessIterator begin, RamdomAccessIterator end, Comp comp, int i, int N)
	{
		while (2*i <= N)
		{
			int j = 2*i;

			if (j < N && comp(*(begin + j - 1), *(begin + j)))
				j++;
			if (!comp(*(begin + i - 1), *(begin + j - 1)))
				break;
			exch(begin, i, j);
			i = j;
		}
	}

	template <typename RandomAccessIterator, typename Comp>
	void heapSort(RandomAccessIterator begin, RandomAccessIterator end, Comp comp)
	{
		int N = end - begin;

		for (int i = N/2; i >= 1; i--)
			sink(begin, end, comp, i, N);

		while (N > 1)
		{
			exch(begin, 1, N);
			sink(begin, end, comp, 1, --N);
		}
	}

	template <typename RandomAccessIterator>
	void sort(RandomAccessIterator begin, RandomAccessIterator end)
	{
		DefaultCompare comp;
		heapSort(begin, end, comp);
	}

	template <typename RandomAccessIterator, typename Comp>
	void sort(RandomAccessIterator begin, RandomAccessIterator end, Comp comp)
	{
		heapSort(begin, end, comp);
	}
};


class CustomCompare
{
private:
public:
	template <typename Comparable>
	bool operator()(const Comparable& a, const Comparable& b)
	{
		return b < a;
	}
};

template <typename T>
void print_vector(T a)
{
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;
}

class CustomClass
{
private:
public:
	int a;
	int b;

	CustomClass() : a(0), b(0)
	{ }
	CustomClass(const int& x, const int& y) : a(x), b(y)
	{ }

	bool operator<(const CustomClass& w) const
	{
		if (a < w.a)
			return true;
		if (a == w.a)
			if (b < w.b)
				return true;

		return false;
	}
};

std::ostream& operator<<(ostream& os, const CustomClass& x)
{
	os << "(" << x.a << ", " << x.b << ")";
	return os;
}


int main()
{
	// int test
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(5);
	a.push_back(3);
	a.push_back(9);
	a.push_back(8);
	a.push_back(6);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(9);
	a.push_back(3);
	CustomCompare my_compare;

	print_vector(a);

	heap::sort(a.begin(), a.end());
	print_vector(a);

	heap::sort(a.begin(), a.end(), my_compare);
	print_vector(a);

	// string test
	vector<string> b;
	b.push_back("a");
	b.push_back("ab");
	b.push_back("c");
	b.push_back("d");
	b.push_back("abc");
	b.push_back("f");
	b.push_back("king");
	b.push_back("h");
	b.push_back("i");
	b.push_back("j");
	b.push_back("k");
	b.push_back("l");

	print_vector(b);

	heap::sort(b.begin(), b.end());
	print_vector(b);

	heap::sort(b.begin(), b.end(), my_compare);
	print_vector(b);


	// custom object which has '<' operator test
	vector<CustomClass> c;

	c.push_back(CustomClass(1, 2));
	c.push_back(CustomClass(3, 7));
	c.push_back(CustomClass(2, 2));
	c.push_back(CustomClass(1, 2));
	c.push_back(CustomClass(2, 6));
	c.push_back(CustomClass(1, 3));
	c.push_back(CustomClass(3, 9));
	c.push_back(CustomClass(1, 8));

	print_vector(c);

	heap::sort(c.begin(), c.end());
	print_vector(c);

	heap::sort(c.begin(), c.end(), my_compare);
	print_vector(c);

	return 0;
}
