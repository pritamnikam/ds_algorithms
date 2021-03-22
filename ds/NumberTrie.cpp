#include<iostream>

using namespace std;

namespace {

	const int kTrieNodes = 10;
	
	struct Trie {
		bool is_number_;
		int id_;
		Trie* children_[kTrieNodes];

		static Trie* NewTrieNode();

		void Insert(int key) {
			if (key == 0) {
				is_number_ = true;
				return;
			}

			int id = key % 10;
			Trie* child = children_[id];
			if (child == nullptr) {
				child = NewTrieNode();
				children_[id] = child;
			}

			child->Insert(key / 10);
		}

		int Search(int key) {
			if (key == 0) {
				return (is_number_ == true) ? id_ : -1;
			}

			int id = key % 10;
			Trie* child = children_[id];
			if (child == nullptr) {
				return -1;
			}

			return child->Search(key / 10);
		}

		bool Remove(int key) {
			if (key == 0) {
				if (is_number_)
					is_number_ = false;

				return Empty();
			}
			int id = key % 10;
			Trie* child = children_[id];
			if (child && child->Remove(key / 10)) {
				children_[id] = nullptr;
				return !is_number_ && Empty();
			}

			return false;
		}

		bool Empty() {
			for (int i = 0; i < kTrieNodes; ++i)
				if (children_[i]) return false;

			return true;
		}

		void Print() {
			cout << "id: " << id_ << ", is_number_: " << is_number_ << endl;
		}
	};

	const int kInsertCalls = 1000;
	Trie arr_[kTrieNodes * kInsertCalls];

	struct TrieNodePool {
		int size_;

		void Init() {
			size_ = 0;
		}

		Trie* GetNewNode() {
			return GetByID(size_++);
		}

		Trie* GetByID(int id) {
			return &arr_[size_];
		}
	};

	struct TrieNodePool pool_;

	Trie* Trie::NewTrieNode() {
		Trie* t = pool_.GetNewNode();
		t->is_number_ = false;
		t->id_ = pool_.size_ - 1;
		for (int i = 0; i < kTrieNodes; ++i)
			t->children_[i] = nullptr;

		return t;
	}
} // namespace


void testNumberTries() {
	Trie* root = Trie::NewTrieNode();
	int id = 1000000000;
	root->Insert(id);
	int idx = root->Search(id);
	if (idx == -1) {
		cout << "Error! Key not found!" << endl;
		return;
	}
		
	Trie* t = pool_.GetByID(idx);
	t->Print();

	root->Remove(id);
	idx = root->Search(id);
	if (idx != -1) {
		cout << "Error! Key found!" << endl;
		return;
	}
}
