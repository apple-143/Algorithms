#ifndef GRAPH_TW_H_
#define GRAPH_TW_H_

#include <vector>
#include <string>


/*TODO
	- constructor
	- AddEdge
	- Adj
	- ToString

done
*/
template <typename T>
class Bag {
private:
	std::vector<T> bag_;
public:
	Bag () {
	}

	T operator[] (size_t idx) {
		return bag_[idx];
	}

	void add (T x) {
		bag_.push_back(x);
	}
};

class Graph {
private:
	const int kV_;
	int E_;
	Bag<int> * adj;

public:
	Graph (int V) : kV_(V), E_(0) {
		adj = new Bag<int>[V];
	}

	int V () { return kV_; }
	int E () { return E_; }

	void AddEdge (int v, int w) {
		adj[v].add(w);
		adj[w].add(v);
		E_++;
	}
	int TestAddEdge (int x, int i) {
		return adj[x][i];
	}

	void Adj (int v) {
	}

	std::string ToString () {
	}
};

#endif	// GRAPH_TW_H_
