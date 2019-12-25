#include <iostream>
#include <vector>

using namespace std;

namespace insertion
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
	void exch(RandomAccessIterator& begin, const int& i, const int& j)
	{
		auto tmp = *(begin + i);
		*(begin + i) = *(begin + j);
		*(begin + j) = tmp;
	}

	template <typename RandomAccessIterator, typename Comp>
	void insertionSort(RandomAccessIterator begin, RandomAccessIterator end, Comp comp)
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

	template <typename RandomAccessIterator>
	void sort(RandomAccessIterator begin, RandomAccessIterator end)
	{
		DefaultCompare comp;
		insertionSort(begin, end, comp);
	}

	template <typename RandomAccessIterator, typename Comp>
	void sort(RandomAccessIterator begin, RandomAccessIterator end, Comp comp)
	{
		insertionSort(begin, end, comp);
	}
}


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

	insertion::sort(a.begin(), a.end());
	print_vector(a);

	insertion::sort(a.begin(), a.end(), my_compare);
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

	insertion::sort(b.begin(), b.end());
	print_vector(b);

	insertion::sort(b.begin(), b.end(), my_compare);
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

	insertion::sort(c.begin(), c.end());
	print_vector(c);

	insertion::sort(c.begin(), c.end(), my_compare);
	print_vector(c);

	return 0;
}
