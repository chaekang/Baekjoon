#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
	node* left;
	node* right;
	char value;
};

node* tree[26];

node* CreateNode(char value) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->value = value;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}

void Preorder(node* n) {
	cout << n->value;
	if (n->left != NULL) {
		Preorder(n->left);
	}
	if (n->right != NULL) {
		Preorder(n->right);
	}
}

void Inorder(node* n) {
	if (n->left != NULL) {
		Inorder(n->left);
	}
	cout << n->value;
	if (n->right != NULL) {
		Inorder(n->right);
	}
}

void Postorder(node* n) {
	if (n->left != NULL) {
		Postorder(n->left);
	}
	if (n->right != NULL) {
		Postorder(n->right);
	}
	cout << n->value;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		char value, left, right;
		cin >> value >> left >> right;

		if (!tree[value - 'A']) {
			tree[value - 'A'] = CreateNode(value);
		}

		if (left != '.') {
			if (!tree[left - 'A']) {
				tree[left - 'A'] = CreateNode(left);
			}
			tree[value - 'A']->left = tree[left - 'A'];
		}

		if (right != '.') {
			if (!tree[right - 'A']) {
				tree[right - 'A'] = CreateNode(right);
			}
			tree[value - 'A']->right = tree[right - 'A'];
		}
	}

	Preorder(tree[0]);
	cout << "\n";
	Inorder(tree[0]);
	cout << "\n";
	Postorder(tree[0]);
}