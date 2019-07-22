#include <iostream>
#include <vector>
using namespace std;


namespace selection
{
	template <typename comparable>
	bool less(comparable v, comparable w)
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
		for (RandomAccessIterator i = begin; i < end; i++)
		{
			RandomAccessIterator min = i;
			for(RandomAccessIterator j = i; j < end; j++)
				if (less(*j, *min))
					min = j;
			exch(begin, i-begin, min-begin);
		}
	}

	template <typename RandomAccessIterator, typename Comp>
	void sort(RandomAccessIterator begin, RandomAccessIterator end, Comp comp)
	{
		for (RandomAccessIterator i = begin; i < end; i++)
		{
			RandomAccessIterator min = i;
			for(RandomAccessIterator j = i; j < end; j++)
				if (comp(*j, *min))
					min = j;
			exch(begin, i-begin, min-begin);
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
	vector<int> sample_vector;
	sample_vector.push_back(9);
	sample_vector.push_back(7);
	sample_vector.push_back(1);
	sample_vector.push_back(2);
	sample_vector.push_back(6);

	print_vector(sample_vector);

	selection::sort(sample_vector.begin(), sample_vector.end());
	print_vector(sample_vector);

	CustomCompare my_compare;
	selection::sort(sample_vector.begin(), sample_vector.end(), my_compare);
	print_vector(sample_vector);

	return 0;
}
