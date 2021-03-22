#include <iostream>


using namespace std;

namespace {

	const int kVocabSize = 26;

	struct Node;

	struct Pool {
		int size_;
		void Init();
		Node* GetNewNode();
	};

	Pool pool_;

	struct Node {
		bool isWord_;
		bool deleted_;
		Node* children_[kVocabSize];

		static Node* NewNode() {
			Node* node = pool_.GetNewNode();
			node->isWord_ = false;
			node->deleted_ = false;
			for (int i = 0; i < kVocabSize; ++i) {
				node->children_[i] = nullptr;
			}

			return node;
		}

		void Insert(const char* key, int size, int index) {
			if (size == index) {
				isWord_ = true;
				return;
			}

			int id = key[index] - 'a';
			Node* child = children_[id];
			if (child == nullptr) {
				child = NewNode();
				children_[id] = child;
			}

			child->Insert(key, size, 1 + index);
		}

		bool Search(const char* key, int size, int index) {
			if (size == index) {
				return isWord_ && !deleted_;
			}

			int id = key[index] - 'a';
			Node* child = children_[id];
			if (child == nullptr) {
				return false;
			}

			return child->Search(key, size, 1 + index);
		}

		bool Empty() {
			for (int i = 0; i < kVocabSize; ++i) {
				if (children_[i] != nullptr) {
					return false;
				}
			}

			return true;
		}

		bool Delete(const char* key, int size, int index) {
			if (size == index) {
				if (isWord_) {
					isWord_ = false;
				}

				deleted_ = true;
				return Empty();
			}

			int id = key[index] - 'a';
			Node* child = children_[id];
			if (child && child->Delete(key, size, 1 + index)) {
				children_[id] = nullptr;
			}

			return !isWord_ && Empty();
		}
	};

	const int kPoolSize = 10000;
	Node arr_[kPoolSize];

	void Pool::Init() {
		size_ = 0;
	}

	Node* Pool::GetNewNode() {
		return &arr_[size_++];
	}

}  //namespace