#ifndef BAG_TW_H_
#define BAG_TW_H_

#include <vector>

/*TODO
*/
template <typename T>
class Bag {
private:
	struct Node {
		T item;
		Node * next;
	};

	Node * first;

public:
	class iterator {
	private:
		Node * cur_;

	public:
		iterator(Node * node) {
			cur_ = node;
		}

		iterator& operator++() {
			cur_ = cur_->next;
			return *this;
		}

		T operator*() {
			return cur_->item;
		}

		bool operator!=(const iterator& x) {
			return cur_ != x.cur_;
		}
	};

	Bag () : first(nullptr) {}

	void Add(T item) {
		Node * old_first = first;
		first = new Node;
		first->item = item;
		first->next = old_first;
	}

	iterator begin() {
		return iterator(first);
	}

	iterator end() {
		return iterator(nullptr);
	}
};

#endif	// BAG_TW_H_
