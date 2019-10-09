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
public:
}

class Graph {
private:
	const int V;
	int E;
	Bag<int> * adj;

public:
	Graph(int V) : V(V) {
	}

	Graph() {
	}

	int V() { return V; }
	int E() { return E; }

	void AddEdge(int v, int w) {
	}

	void Adj(int v) {
	}

	std::string ToString() {
	}
};

#endif	// GRAPH_TW_H_
