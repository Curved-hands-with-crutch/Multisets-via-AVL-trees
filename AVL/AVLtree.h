#pragma once
#include <iostream>

template <typename T>
class AVLtree
{
private:
	struct Node
	{
		T value;
		Node* left;
		Node* right;
		unsigned __int8 height;
	};

	Node* current;

	Node* createNode(T val)
	{
		Node* node = new Node;
		node->value = val;
		node->left = nullptr;
		node->right = nullptr;
		node->height = 1;
		return node;
	}

	__int8 balanceFactor(Node* a)
	{
		return getHeight(a->right) - getHeight(a->left);
	}

	void correctHeight(Node* a)
	{
		unsigned __int8 hr = getHeight(a->right),
			hl = getHeight(a->left);
		a->height = (hr > hl ? hr : hl) + 1;
	}

	Node* smallRotateLeft(Node* a)
	{
		Node* b = a->right;
		a->right = b->left;
		b->left = a;

		correctHeight(a);
		correctHeight(b);
		return b;
	}

	Node* smallRotateRight(Node* a)
	{
		Node* b = a->left;
		a->left = b->right;
		b->right = a;

		correctHeight(a);
		correctHeight(b);
		return b;
	}

	Node* bigRotateLeft(Node* a)
	{
		smallRotateRight(a->right);
		return smallRotateLeft(a);
	}

	Node* bigRotateRight(Node* a)
	{
		smallRotateLeft(a->right);
		return smallRotateRight(a);
	}

	Node* balance(Node* a)
	{
		if (!a)
			return nullptr;

		correctHeight(a);

		if (balanceFactor(a) == 2)
		{
			if (balanceFactor(a->right) < 0)
				a->right = smallRotateRight(a->right);
			return smallRotateLeft(a);
		}

		if (balanceFactor(a) == -2)
		{
			if (balanceFactor(a->left) > 0)
				a->left = smallRotateLeft(a->left);
			return smallRotateRight(a);
		}
		return a;
	}

	void destructorImplementation(Node* cur)
	{
		Node* temp = cur;
		if (cur->left)
		{
			cur = cur->left;
			destructorImplementation(cur);
		}

		cur = temp;
		if (cur->right)
		{
			cur = cur->right;
			destructorImplementation(cur);
		}

		cur = temp;
		delete[] cur;
		return;
	}

	Node* insertImplementation(Node* a, T val)
	{
		if (!a)
			return createNode(val);

		if (val < a->value)
			a->left = insertImplementation(a->left, val);
		else
			a->right = insertImplementation(a->right, val);

		return balance(a);
	}

	Node* findMin(Node* a)
	{
		Node* temp = a->left;
		if (temp)
		{
			while (temp->left)
				temp = temp->left;
			
			return temp;
		}
		else
			return a;
	}

	Node* removeMin(Node* a)
	{
		if (!(a->left))
			return a->right;
		a->left = removeMin(a->left);
		return balance(a);
	}

	Node* removeImplementation(Node* a, T val)
	{
		if (!a)
			return nullptr;

		if (val < a->value)
			a->left = removeImplementation(a->left, val);
		else
			if (val > a->value)
				a->right = removeImplementation(a->right, val);
			else
			{
				Node *rightChild = a->right,
					*leftChild = a->left;
				delete a;

				if (!rightChild)
					return leftChild;
				
				Node* alternate = findMin(rightChild);		// extract чревато проблемами

				alternate->right = removeMin(rightChild);
				alternate->left = leftChild;

				return balance(alternate);
			}
		return balance(a);
	}

public:

	unsigned __int8 getHeight(Node* a)
	{
		return a ? a->height : 0;
	}

	AVLtree()
	{
		current = nullptr;
	};

	~AVLtree()
	{
		if (current)
			destructorImplementation(current);
	};

	void insert(T val)
	{
		current = insertImplementation(current, val);
		return;
	}

	void remove(T val)
	{
		current = balance(removeImplementation(current, val));
		return;
	}

	void traversalLcr()
	{
		if (!current)
			return;

		if (current->left)
		{
			Node* temp = current;
			current = current->left;
			traversalLcr();
			current = temp;
		}
		std::cout << current->value << " ";
		if (current->right)
		{
			Node* temp = current;
			current = current->right;
			traversalLcr();
			current = temp;
		}
	}



};
