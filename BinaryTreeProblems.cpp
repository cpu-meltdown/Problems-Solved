#include <iostream>

using namespace std;

struct node {
	int value;
	node *right;
	node *left;
};

void printTreePostOrder(node *root){
	if (root != NULL){
		printTreePostOrder(root->left);
		printTreePostOrder(root->right);
		cout << root->value << " ";
	}
}

void printTreePreOrder(node *root){
	if (root != NULL){
		cout << root->value << " ";
		printTreePreOrder(root->left);
		printTreePreOrder(root->right);
	}
}

void printTreeInOrder(node *root){
	if (root != NULL){
		printTreePostOrder(root->left);
		cout << root->value << " ";
		printTreePostOrder(root->right);
	}
}

void insert(node *root, node *tempNode){
	if (tempNode->value < root->value){
		if (root->left == NULL)
			root->left = tempNode;
		else
			insert(root->left, tempNode);
	}
	else{
		if (root->right == NULL)
			root->right= tempNode;
		else
			insert(root->right, tempNode);
	}
}

bool checkBST(Node* root, int minValue, int maxValue) {
    if (root == NULL) {
        return true;
    }

    if (root->data < minValue || root->data > maxValue) {
        return false;
    }

    return (    checkBST(root->left, minValue, root->data - 1) 
            &&  checkBST(root->right, root->data + 1, maxValue)
            );
}

bool checkBST(Node* root) {
    return checkBST(root, 0, 10000);
}

int main() {
	node *root = new node;
	root->left = root->right = NULL;
	root->value = 50;
	int temp = 0;
	while (temp != -1){
		cin >> temp;
		node *tempNode = new node;
		tempNode->left = tempNode->right = NULL;
		tempNode->value = temp;
		insert(root, tempNode);
	}
	printTreePostOrder(root);
	return 0;
}