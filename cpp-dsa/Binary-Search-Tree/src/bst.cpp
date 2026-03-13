#include <iostream>
#include <fmt/core.h>

class Node {
public:
	int value;
	Node* right;
	Node* left;
	Node(int value)
	{
		this->value = value;
		right = nullptr;
		left = nullptr;
	}
};

class BinarySearchTree {
private:
	Node* root;
public:
	BinarySearchTree()
	{
		root = nullptr;
	}
	BinarySearchTree(int value)
	{
		Node* newNode = new Node(value);
		root = newNode;
	}
	void destroy(Node* currentNode)
	{
		if (currentNode == nullptr) return;
		if (currentNode->left != nullptr) destroy(currentNode->left);
		if (currentNode->right != nullptr) destroy(currentNode->right);
		delete currentNode;
	}
	~BinarySearchTree()
	{
		destroy(root);
	}
	Node* getRoot()
	{
		return root;
	}
	bool insert(int value)
	{
		Node* newNode = new Node(value);
		if (root == nullptr)
		{
			root = newNode;
			return true;
		}
		Node* temp = root;
		while (true)
		{
			if (newNode->value == temp->value) return false;
			if (newNode->value < temp->value)
			{
				if (temp->left == nullptr)
				{
					temp->left = newNode;
					return true;
				}
				temp = temp->left;
			}
			else
			{
				if (temp->right == nullptr)
				{
					temp->right = newNode;
					return true;
				}
				temp = temp->right;
			}
		}
	}
	bool contains(Node* node, int value)
	{
		if (node == nullptr)
			return false;

		if (value < node->value)
			return contains(node->left, value);

		if (value > node->value)
			return contains(node->right, value);

		return true;
	}
	bool containsValue(int value)
	{
		return contains(root, value);
	}
};


int main()
{
	fmt::print("===== BINARY SEARCH TREE TEST =====\n");

	BinarySearchTree bst;

	fmt::print("Insert values:\n");

	bst.insert(47);
	bst.insert(21);
	bst.insert(76);
	bst.insert(18);
	bst.insert(27);
	bst.insert(52);
	bst.insert(82);

	fmt::print("Root value: {}\n\n", bst.getRoot()->value);

	fmt::print("Contains 27? {}\n", bst.containsValue(27));
	fmt::print("Contains 17? {}\n", bst.containsValue(17));
	fmt::print("Contains 82? {}\n", bst.containsValue(82));
	fmt::print("Contains 100? {}\n\n", bst.containsValue(100));

	fmt::print("BST test finished\n");

	return 0;
}
