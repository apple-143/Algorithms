#include <iostream>
#include <vector>

using namespace std;

namespace merge
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
		auto tmp = *(begin + i);
		*(begin + i) = *(begin + j);
		*(begin + j) = tmp;
	}

	template <typename RandomAccessIterator, typename Comp>
	void merge(RandomAccessIterator begin, RandomAccessIterator end,
				RandomAccessIterator aux_begin, RandomAccessIterator aux_end,
				const int& lo, const int& mid, const int& hi, Comp comp)
	{
		for (int k = lo; k < hi + 1; k++)
			*(aux_begin + k) = *(begin + k);

		int i = lo, j = mid + 1;
		for (int k = lo; k < hi + 1; k++)
		{
			if (i > mid)			*(begin + k) = *(aux_begin + j++);
			else if	(j > hi)		*(begin + k) = *(aux_begin + i++);

			else if	(comp(*(aux_begin + i), *(aux_begin + j)))
									*(begin + k) = *(aux_begin + i++);
			else					*(begin + k) = *(aux_begin + j++);
		}

		return;
	}

	template <typename RandomAccessIterator, typename Comp>
	void sort(RandomAccessIterator begin, RandomAccessIterator end,
				RandomAccessIterator aux_begin, RandomAccessIterator aux_end,
				const int& lo, const int& hi, Comp comp)
	{
		if (hi <= lo) return;

		int mid = (lo + hi) / 2;
		sort(begin, end, aux_begin, aux_end, lo, mid, comp);
		sort(begin, end, aux_begin, aux_end, mid+1, hi, comp);
		merge(begin, end, aux_begin, aux_end, lo, mid, hi, comp);
	}

	template <typename RandomAccessIterator>
	void sort(RandomAccessIterator begin, RandomAccessIterator end)
	{
		auto t = *begin;
		using Value = decltype(t);
		DefaultCompare comp;
		int n = end - begin;
		vector<Value> aux(n);
		sort(begin, end, aux.begin(), aux.end(), 0, n, comp);
	}

	template <typename RandomAccessIterator, typename Comp>
	void sort(RandomAccessIterator begin, RandomAccessIterator end, Comp comp)
	{
		auto t = *begin;
		using Value = decltype(t);
		int n = end - begin;
		vector<Value> aux(n);
		sort(begin, end, aux.begin(), aux.end(), 0, n, comp);
	}
}

class CustomCompare
{
private:
public:
	bool operator()(const int& a, const int& b)
	{
		return b < a;
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

	print_vector(a);

	merge::sort(a.begin(), a.end());
	print_vector(a);

	CustomCompare my_compare;
	merge::sort(a.begin(), a.end(), my_compare);
	print_vector(a);

	return 0;
}
