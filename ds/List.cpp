#include <iostream>

using namespace std;

namespace {

	struct Node {
		int data_;
		Node* next_;
	};

	struct Pool {
		int size_;

		Node* GetNewNode();
		Node* GetNodeByID(int id);
		void Init();
	};

	struct List {
		int size_;
		Node* first_;

		void Add(int a);
		Node* Search(int a);
		Node* Remove(int a);
		void Init();
	};

	const int kPoolSize = 1000;
	Node arr_[kPoolSize];

	Node* Pool::GetNewNode() {
		return GetNodeByID(size_++);
	}

	Node* Pool::GetNodeByID(int id) {
		return &arr_[id];
	}

	void Pool::Init() {
		size_ = 0;
	}

	Pool pool_;

	void List::Add(int a) {
		Node* t = pool_.GetNewNode();
		t->data_ = a;
		t->next_ = first_;
		first_ = t;
		++size_;
	}

	Node* List::Search(int a) {
		Node* cur = first_;
		while (cur && cur->data_ != a) {
			cur = cur->next_;
		}
		return cur;
	}


	Node* List::Remove(int a) {
		Node* cur = first_;
		Node* prev = nullptr;
		while (cur && cur->data_ != a) {
			prev = cur;
			cur = cur->next_;
		}

		if (cur) {
			if (prev) {
				prev->next_ = cur->next_;
			}
			else {
				first_ = cur->next_;
			}

			cur->next_ = nullptr;
			--size_;
		}

		return cur;
	}

	void List::Init() {
		size_ = 0;
		first_ = nullptr;
	}
}