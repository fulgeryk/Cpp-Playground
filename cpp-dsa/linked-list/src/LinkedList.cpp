#include <iostream>
#include <fmt/core.h>
using namespace std;

class Node {
public:
	int value;
	Node* next;
	Node(int value)
	{
		this->value = value;
		next = nullptr;
	}
};
class LinkedList {
private:
	Node* head;
	Node* tail;
	int length;
public:
	LinkedList(int value)
	{
		Node* newNode = new Node(value);
		head = newNode;
		tail = newNode;
		length = 1;
	}
	~LinkedList()
	{
		Node* temp = head;
		while (head)
		{
			head = head->next;
			delete temp;
			temp = head;
		}
	}
	void printList()
	{
		Node* temp = head;
		if (temp == nullptr)
			fmt::print("List is empty \n");
		else
		{
			while (temp != nullptr)
			{
				fmt::print("{}", temp->value);
				temp = temp->next;
				if (temp != nullptr)
				{
					fmt::print(" -> ");
				}
			}
		}
	}
	Node* getHead()
	{
		return head;
	}
	Node* getTail()
	{
		return tail;
	}
	int getLength()
	{
		return length;
	}
	void append(int value)
	{
		Node* newNode = new Node(value);
		if (length == 0)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		length++;
	}
	void prepand(int value)
	{
		Node* newNode = new Node(value);
		if (length == 0)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
		length++;
	}
	void deleteLast()
	{
		if (length == 0) return;
		Node* temp = head;
		if (length == 1)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			Node* pre = head;
			while (temp->next != nullptr)
			{
				pre = temp;
				temp = temp->next;
			}
			tail = pre;
			tail->next = nullptr;
		}
		delete temp;
		length--;
	}
	void deleteFirst()
	{
		if (length == 0) return;
		Node* temp = head;
		if (length == 1)
		{
			head = nullptr;
			tail = nullptr;
		}
		else {
			head = head->next;
		}
		delete temp;
		length--;
	}
	Node* get(int index)
	{
		if (index < 0 || index >= length) return nullptr;
		Node* temp = head;
		for (int i = 0; i < index; ++i)
		{
			temp = temp->next;
		}
		return temp;
	}
	bool set(int index, int value)
	{
		Node* temp = get(index);
		if (temp != nullptr)
		{
			temp->value = value;
			return true;
		}
		return false;
	}
	bool insert(int index, int value)
	{
		if (index < 0 || index >= length) return false;
		if (index == 0)
		{
			prepand(value);
			return true;
		}
		if (index == length)
		{
			append(value);
			return true;
		}
		Node* newNode = new Node(value);
		Node* temp = get(index - 1);
		newNode->next = temp->next;
		temp->next = newNode;
		length++;
		return true;
	}
	void deleteNode(int index)
	{
		if (index < 0 || index >= length) return;
		if (index == 0) return deleteFirst();
		if (index == length - 1) return deleteLast();
		Node* prev = get(index - 1);
		Node* temp = prev->next;
		prev->next = temp->next;
		delete temp;
		length--;
	}
	void reverse()
	{
		Node* temp = head;
		head = tail;
		tail = temp;
		Node* after = temp->next;
		Node* before = nullptr;
		for (int i = 0; i < length; ++i)
		{
			after = temp->next;
			temp->next = before;
			before = temp;
			temp = after;
		}
	}
};

int main()
{
	LinkedList list(10);

	list.append(20);
	list.append(30);
	list.prepand(5);

	fmt::print("Initial list:\n");
	list.printList();
	fmt::print("\n\n");

	fmt::print("Delete first:\n");
	list.deleteFirst();
	list.printList();
	fmt::print("\n\n");

	fmt::print("Delete last:\n");
	list.deleteLast();
	list.printList();
	fmt::print("\n\n");

	fmt::print("Insert at index 1:\n");
	list.insert(1, 99);
	list.printList();
	fmt::print("\n\n");

	fmt::print("Set index 1 -> 42:\n");
	list.set(1, 42);
	list.printList();
	fmt::print("\n\n");

	fmt::print("Reverse list:\n");
	list.reverse();
	list.printList();
	fmt::print("\n");

	return 0;
}

