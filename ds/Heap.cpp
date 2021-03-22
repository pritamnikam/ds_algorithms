#include <iostream>

using namespace std;

namespace {

	const int kCapcacityIncrement = 10;
	const int kHeapCapacity = 100;
	int arr[kHeapCapacity];

	struct Heap {
		Heap() = default;
		~Heap() = default;

		void Swap(int a, int b) {
			int c = arr_[a];
			arr_[a] = arr_[b];
			arr_[b] = c;
		}

		void EnsureCapacity() {
			if (Full())
				capacity_ = capacity_ + kCapcacityIncrement;
		}

		bool Full() {
			return size_ == capacity_;
		}

		bool Empty() {
			return size_ == 0;
		}

		int Size() {
			return size_;
		}

		bool HasParent(int id) {
			return id > 0;
		}

		bool HasLeftChild(int id) {
			return (id * 2 + 1) < size_;
		}

		bool HasRightChild(int id) {
			return (id * 2 + 2) < size_;
		}

		int ParentID(int id) {
			return (id - 1) / 2;
		}
		int LeftChildID(int id) {
			return (id * 2) + 1;
		}
		int RightChildID(int id) {
			return (id * 2) + 2;
		}

		void Push(int a) {
			arr_[size_] = a;
			++size_;

			HeapifyUp();
		}

		void Pop() {
			arr_[0] = arr_[size_ - 1];
			--size_;

			HeapifyDown();
		}

		int Top() {
			return arr_[0];
		}

		void Init() {
			size_ = 0;
			capacity_ = kCapcacityIncrement;
			arr_ = arr;
		}

		virtual void HeapifyUp() {}

		virtual void HeapifyDown() {}

		int size_;
		int capacity_;
		int* arr_;
	};

	struct MinHeap : public Heap {
		void HeapifyUp() override {
			int id = size_ - 1;
			while (HasParent(id)) {
				int parent_id = ParentID(id);
				if (arr_[id] < arr_[parent_id]) {
					Swap(id, parent_id);
					id = parent_id;
				}
				else {
					break;
				}
			}
		}

		void HeapifyDown() override  {
			int id = 0;
			while (HasLeftChild(id)) {
				int left_child_id = LeftChildID(id);
				int child_id = left_child_id;
				if (HasRightChild(id)) {
					int right_child_id = RightChildID(id);
					if (arr_[right_child_id] < arr_[left_child_id])
						child_id = right_child_id;
				}

				if (arr_[child_id] < arr_[id]) {
					Swap(id, child_id);
					id = child_id;
				}
				else {
					break;
				}
			}
		}
	};

	struct MaxHeap : public Heap {
		void HeapifyUp() override {
			int id = size_ - 1;
			while (HasParent(id)) {
				int parent_id = ParentID(id);
				if (arr_[id] > arr_[parent_id]) {
					Swap(id, parent_id);
					id = parent_id;
				}
				else {
					break;
				}
			}
		}

		void HeapifyDown() override {
			int id = 0;
			while (HasLeftChild(id)) {
				int left_child_id = LeftChildID(id);
				int child_id = left_child_id;

				if (HasRightChild(id)) {
					int right_child_id = RightChildID(id);
					if (arr_[right_child_id] > arr_[left_child_id]) {
						child_id = right_child_id;
					}
				}

				if (arr_[child_id] > arr_[id]) {
					Swap(id, child_id);
					id = child_id;
				}
				else {
					break;
				}
			}
		}
	};

}  // namespce


