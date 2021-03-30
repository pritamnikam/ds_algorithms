#include <iostream>


#include <algorithm>

using namespace std;

struct Tree {
	int data_;
	Tree* left_;
	Tree* right_;
};

int Height(Tree* root) {
	if (root == nullptr) {
		return 0;
	}

	int lh = Height(root->left_);
	int rh = Height(root->right_);

	return 1 + std::max(lh, rh);
}