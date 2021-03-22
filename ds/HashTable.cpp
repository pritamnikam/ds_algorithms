#include <iostream>


namespace {

	struct Node {
		char* key_;
		int value_;
		Node* next_;
	};

	struct Pool {
		int size_;

		void Init();
		Node* GetNewNode();
		Node* GetNodeByID(int id);
	};


	struct List {
		int size_;
		Node* first_;

		void Init() {
			size_ = 0;
			first_ = nullptr;
		}

		bool Equal(const char* a, const char* b);
		void Add(const char* key, int value);
		Node* Search(const char* key);
		Node* Remove(const char* key);

		int Size() {
			return size_;
		}
	};

	// Seperate chain:
	struct HashTable {
		int table_size_;
		List* lists_[];

		void Init();
		void Insert(const char* key, int value) {
			int id = Hash(key) % table_size_;
			lists_[id]->Add(key, value);
		}
		int Search(const char* key) {
			int id = Hash(key) % table_size_;
			Node* t = lists_[id]->Search(key);
			return (t == nullptr) ? -1 : t->value_;
		}

		void Remove(const char* key) {
			int id = Hash(key) % table_size_;
			lists_[id]->Remove(key);
		}

		unsigned long Hash(const char* key) {
			unsigned long hash = 5381;
			for (int i = 0; key[i] != '\0'; ++i) {
				hash = ((hash << 5) + hash) + key[i];
			}

			return hash;
		}
	};

	const int kTableSize = 100013;
	Pool pool_;

	void HashTable::Init() {
		pool_.Init();
		table_size_ = kTableSize;
		for (int i = 0; i < kTableSize; ++i) {
			lists_[i]->Init();
		}
	}

	void List::Add(const char* key, int value) {
		Node* t = pool_.GetNewNode();
		t->key_ = (char*) key;
		t->value_ = value;
		t->next_ = first_;
		first_ = t;
		++size_;
	}

	Node* List::Search(const char* key) {
		Node* cur = first_;
		while (cur && !Equal(cur->key_, key)) {
			cur = cur->next_;
		}
		return cur;
	}

	Node* List::Remove(const char* key) {
		Node* cur = first_;
		Node* prev = nullptr;
		while (cur && !Equal(cur->key_, key)) {
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
			--size_;
			cur->next_ = nullptr;
		}

		return cur;
	}

	bool List::Equal(const char* a, const char* b) {
		int i = 0;
		while (a && b && a[i] != '\0' && b[i] != '\0' && a[i] == b[i]) {
			++i;
		}

		return (a[i] == '\0') && (b[i] == '\0');
	}

	const int kPoolSize = 10000;
	Node arr_[kPoolSize];

	void Pool::Init() {
		size_ = 0;
	}

	Node* Pool::GetNewNode() {
		return &arr_[size_++];
	}
	Node* Pool::GetNodeByID(int id) {
		return &arr_[id];
	}

}  // namespace